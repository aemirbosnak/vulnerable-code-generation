//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket\n");
        exit(3);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        while (1) {
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                break;
            }

            buffer[bytes_received] = '\0';

            if (strstr(buffer, "GET /") == NULL) {
                printf("Invalid request\n");
                break;
            }

            char* filename = strstr(buffer, "GET /") + 5;

            FILE* file = fopen(filename, "rb");
            if (file == NULL) {
                printf("File not found\n");
                break;
            }

            char file_buffer[BUFFER_SIZE];
            memset(file_buffer, 0, BUFFER_SIZE);

            while (fread(file_buffer, 1, BUFFER_SIZE, file) > 0) {
                send(client_socket, file_buffer, strlen(file_buffer), 0);
            }

            fclose(file);

            break;
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}