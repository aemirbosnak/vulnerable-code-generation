//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int establish_connection(char *server_ip, int server_port) {
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client_socket < 0) {
        perror("ERROR: Failed to create socket");
        exit(errno);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &(server_address.sin_addr));

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR: Failed to connect to server");
        exit(errno);
    }

    return client_socket;
}

int receive_message(int client_socket, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("ERROR: Failed to receive message from server");
        exit(errno);
    }

    if (bytes_received == 0) {
        printf("Connection closed by server\n");
        exit(0);
    }

    return bytes_received;
}

void send_message(int client_socket, char *message) {
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("ERROR: Failed to send message to server");
        exit(errno);
    }
}

int main() {
    char server_ip[16];
    printf("Enter server IP: ");
    scanf("%s", server_ip);

    int server_port;
    printf("Enter server port: ");
    scanf("%d", &server_port);

    int client_socket = establish_connection(server_ip, server_port);

    char buffer[BUFFER_SIZE];
    receive_message(client_socket, buffer);
    printf("%s", buffer);

    char username[100], password[100];
    printf("Username: ");
    scanf("%s", username);
    send_message(client_socket, username);
    receive_message(client_socket, buffer);

    printf("%s", buffer);
    printf("Password: ");
    scanf("%s", password);

    send_message(client_socket, password);
    receive_message(client_socket, buffer);
    if (strncmp(buffer, "SUCCESS", 7) == 0) {
        printf("Connected to server\n");
    } else {
        printf("Invalid credentials\n");
        exit(0);
    }

    printf("Enter command (get/put/list/quit): ");
    char command[5];
    scanf("%s", command);

    while (strncmp(command, "quit", 4) != 0) {
        send_message(client_socket, command);
        receive_message(client_socket, buffer);

        if (strncmp(command, "list", 4) == 0) {
            printf("%s", buffer);
        } else if (strncmp(command, "get", 3) == 0) {
            if (strncmp(buffer, "ERROR", 5) == 0) {
                printf("%s", buffer);
                continue;
            }

            FILE *file = fopen(strtok(buffer, "\n"), "wb");
            while (1) {
                int bytes_received = receive_message(client_socket, buffer);
                if (bytes_received == 0) {
                    break;
                }

                fwrite(buffer, 1, bytes_received, file);
            }

            fclose(file);
            printf("File received successfully\n");
        } else if (strncmp(command, "put", 3) == 0) {
            char filename[100];
            printf("Enter filename: ");
            scanf("%s", filename);

            FILE *file = fopen(filename, "rb");
            if (file == NULL) {
                printf("ERROR: File does not exist\n");
                send_message(client_socket, "ERROR");
                continue;
            }

            send_message(client_socket, filename);
            while (1) {
                unsigned char file_buffer[BUFFER_SIZE] = {0};
                int bytes_read = fread(file_buffer, 1, BUFFER_SIZE, file);
                if (bytes_read == 0)
                    break;

                send(client_socket, file_buffer, bytes_read, 0);
            }

            fclose(file);
            printf("File sent successfully\n");
            receive_message(client_socket, buffer);
            printf("%s", buffer);
        }

        printf("Enter command (get/put/list/quit): ");
        scanf("%s", command);
    }

    send_message(client_socket, "quit");
    close(client_socket);

    return 0;
}