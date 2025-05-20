//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main()
{
    int server_socket = 0, client_socket[MAX_CLIENTS] = { 0 };
    int opt = 1, client_len = sizeof(client_socket[0]);
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    struct sockaddr_in server_addr, client_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)))
    {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1)
    {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1)
    {
        printf("Waiting for client to connect...\n");

        client_socket[0] = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&client_len);

        if (client_socket[0] == -1)
        {
            printf("Error accepting client\n");
            exit(1);
        }

        printf("Client connected\n");

        while (1)
        {
            bytes_received = recv(client_socket[0], buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0)
            {
                printf("Client disconnected\n");
                close(client_socket[0]);
                break;
            }

            buffer[bytes_received] = '\0';

            printf("Received message: %s\n", buffer);

            send(client_socket[0], buffer, strlen(buffer), 0);
        }
    }

    return 0;
}