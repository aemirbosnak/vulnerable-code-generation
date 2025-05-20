//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addr_len;

    if (argc!= 2) {
        printf("Usage:./server <port>\n");
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 5) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %s\n", argv[1]);

    while (1) {
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                printf("Error receiving data\n");
                break;
            }

            char *request = strtok(buffer, " ");
            if (request == NULL) {
                printf("Invalid request\n");
                break;
            }

            if (strcmp(request, "GET") == 0) {
                char *file = strtok(NULL, " ");
                if (file == NULL) {
                    printf("Invalid file name\n");
                    break;
                }

                FILE *fp;
                fp = fopen(file, "r");
                if (fp == NULL) {
                    printf("File not found\n");
                    break;
                }

                char ch;
                while ((ch = fgetc(fp))!= EOF) {
                    send(client_socket, &ch, 1, 0);
                }

                fclose(fp);
            } else {
                printf("Invalid request method\n");
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}