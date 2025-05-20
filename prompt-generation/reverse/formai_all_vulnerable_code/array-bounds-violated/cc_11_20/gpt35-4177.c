//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc < 3) {
        printf("Usage: %s <server-address> <port-number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));

    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_file_descriptor < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    if(connect(socket_file_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    int bytes_received;
    char buffer[BUFFER_SIZE];
    if((bytes_received = recv(socket_file_descriptor, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    fputs(buffer, stdout);

    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Enter your username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = '\0';

    sprintf(buffer, "USER %s\r\n", username);
    if(send(socket_file_descriptor, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    if((bytes_received = recv(socket_file_descriptor, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    fputs(buffer, stdout);

    sprintf(buffer, "PASS %s\r\n", password);
    if(send(socket_file_descriptor, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    if((bytes_received = recv(socket_file_descriptor, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    fputs(buffer, stdout);

    sprintf(buffer, "LIST\r\n");
    if(send(socket_file_descriptor, buffer, strlen(buffer), 0) < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    if((bytes_received = recv(socket_file_descriptor, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0';
    fputs(buffer, stdout);

    bool is_quit = false;
    while(!is_quit) {
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(strcmp(buffer, "QUIT") == 0) {
            sprintf(buffer, "QUIT\r\n");
            if(send(socket_file_descriptor, buffer, strlen(buffer), 0) < 0) {
                perror("send error");
                exit(EXIT_FAILURE);
            }

            if((bytes_received = recv(socket_file_descriptor, buffer, BUFFER_SIZE, 0)) < 0) {
                perror("recv error");
                exit(EXIT_FAILURE);
            }
            buffer[bytes_received] = '\0';
            fputs(buffer, stdout);

            is_quit = true;

        } else if(strncmp(buffer, "RETR ", strlen("RETR ")) == 0) {
            sprintf(buffer, "%s\r\n", buffer);
            if(send(socket_file_descriptor, buffer, strlen(buffer), 0) < 0) {
                perror("send error");
                exit(EXIT_FAILURE);
            }

            if((bytes_received = recv(socket_file_descriptor, buffer, BUFFER_SIZE, 0)) < 0) {
                perror("recv error");
                exit(EXIT_FAILURE);
            }
            buffer[bytes_received] = '\0';
            fputs(buffer, stdout);

        } else {
            printf("Invalid command.\n");
        }

    }

    close(socket_file_descriptor);
    return EXIT_SUCCESS;
}