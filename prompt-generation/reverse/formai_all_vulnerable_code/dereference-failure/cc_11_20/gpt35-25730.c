//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    uint16_t port_number = htons(atoi(argv[2]));

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        perror("Error while creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = port_number;
    inet_aton(ip_address, &server_address.sin_addr);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error while establishing connection");
        exit(EXIT_FAILURE);
    }

    printf("Successfully connected to server %s:%d\n", ip_address, ntohs(server_address.sin_port));

    char buffer[BUFFER_SIZE];
    ssize_t n_bytes_received;

    while (true) {

        printf("ftp> ");
        fflush(stdout);

        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        if (strncmp(buffer, "get ", 4) == 0) {

            char *file_name = buffer + 4;
            strtok(file_name, "\n");

            uint32_t file_name_length = strlen(file_name);
            file_name_length = htonl(file_name_length);

            if (send(client_socket, &file_name_length, sizeof(file_name_length), 0) < 0) {
                perror("Error while sending data");
                exit(EXIT_FAILURE);
            }

            if (send(client_socket, file_name, strlen(file_name), 0) < 0) {
                perror("Error while sending data");
                exit(EXIT_FAILURE);
            }

            uint32_t file_size;

            if (recv(client_socket, &file_size, sizeof(file_size), 0) < 0) {
                perror("Error while receiving data");
                exit(EXIT_FAILURE);
            }

            file_size = ntohl(file_size);

            if (file_size == 0) {
                printf("File '%s' not found on server.\n", file_name);
                continue;
            }

            printf("Receiving file '%s' (%d bytes)...\n", file_name, file_size);

            int file_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);

            if (file_fd < 0) {
                perror("Error while creating file");
                exit(EXIT_FAILURE);
            }

            uint32_t remaining_bytes = file_size;

            while (remaining_bytes > 0) {
                memset(buffer, 0, BUFFER_SIZE);
                n_bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

                if (n_bytes_received < 0) {
                    perror("Error while receiving data");
                    exit(EXIT_FAILURE);
                }

                if (n_bytes_received == 0) {
                    break;
                }

                write(file_fd, buffer, n_bytes_received);

                remaining_bytes -= n_bytes_received;
            }

            close(file_fd);

            printf("Successfully received file '%s'.\n", file_name);

        } else {
            printf("Invalid command.\n");
        }

    }

    return 0;
}