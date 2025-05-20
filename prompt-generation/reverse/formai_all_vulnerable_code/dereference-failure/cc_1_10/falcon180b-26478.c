//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int client_len;
    char *message;
    time_t current_time;
    struct tm *local_time;
    char time_buffer[80];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(EXIT_FAILURE);
        }

        current_time = time(NULL);
        local_time = localtime(&current_time);
        strftime(time_buffer, 80, "Current time: %X", local_time);

        message = (char *)malloc(BUFFER_SIZE);
        sprintf(message, "Welcome to the server! Current time: %s\n", time_buffer);
        send(client_socket, message, strlen(message), 0);

        free(message);
        close(client_socket);
    }

    return 0;
}