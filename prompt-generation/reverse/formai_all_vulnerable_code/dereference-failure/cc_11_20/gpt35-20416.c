//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_port, socket_fd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE], server_response[BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: ./pop3_client <server-ip> <server-port>\n");
        exit(1);
    }

    server_port = atoi(argv[2]);

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(server_port);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    if (recv(socket_fd, server_response, BUFFER_SIZE, 0) < 0) {
        printf("Error: Did not receive server greeting.\n");
        exit(1);
    }

    printf("Server response: %s", server_response);

    while (1) {
        printf("\nEnter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(socket_fd, buffer, strlen(buffer), 0);

        if (recv(socket_fd, server_response, BUFFER_SIZE, 0) < 0) {
            printf("Error: Could not receive server response.\n");
            exit(1);
        }

        if (strncmp(server_response, "+OK", 3) == 0 || strncmp(server_response, "-ERR", 4) == 0) {
            printf("Server response: %s", server_response);
        } else {
            printf("%s", server_response);

            while (1) {
                if (recv(socket_fd, server_response, BUFFER_SIZE, MSG_PEEK | MSG_DONTWAIT) == 0 ||
                    strncmp(server_response, ".", 1) == 0) {
                    break;
                }

                if (recv(socket_fd, server_response, BUFFER_SIZE, 0) < 0) {
                    printf("Error: Could not receive message.\n");
                    exit(1);
                }

                printf("%s", server_response);
            }
        }

        memset(buffer, 0, BUFFER_SIZE);
        memset(server_response, 0, BUFFER_SIZE);
    }

    close(socket_fd);

    return 0;
}