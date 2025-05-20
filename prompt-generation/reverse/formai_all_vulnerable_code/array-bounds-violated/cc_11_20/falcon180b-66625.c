//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %s...\n", argv[1]);

    while (TRUE) {
        socklen_t client_size;
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_size);

        if (conn_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(conn_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Connection closed by client\n");
                break;
            }

            buffer[bytes_received] = '\0';

            char *request_line = strtok(buffer, "\r\n");
            if (request_line == NULL) {
                continue;
            }

            char *method = strtok(request_line, " ");
            char *uri = strtok(NULL, " ");

            if (method == NULL || uri == NULL) {
                continue;
            }

            if (strcmp(method, "GET") == 0) {
                FILE *file = fopen(uri, "r");

                if (file == NULL) {
                    printf("404 Not Found\r\n");
                } else {
                    printf("200 OK\r\n");
                    printf("Content-Type: text/html\r\n");
                    printf("Connection: close\r\n");
                    printf("\r\n");

                    char line[1024];
                    while (fgets(line, sizeof(line), file)!= NULL) {
                        send(conn_fd, line, strlen(line), 0);
                    }

                    fclose(file);
                }
            } else {
                printf("405 Method Not Allowed\r\n");
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}