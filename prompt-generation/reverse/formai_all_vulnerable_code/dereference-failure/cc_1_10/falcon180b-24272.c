//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3)
    {
        printf("Usage:./proxy <server_ip> <server_port>\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1)
    {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))) == -1)
        {
            printf("Error accepting client connection\n");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);

            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0)
            {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            send(server_socket, buffer, strlen(buffer), 0);

            if (recv(server_socket, buffer, BUFFER_SIZE, 0) <= 0)
            {
                printf("Server disconnected\n");
                close(server_socket);
                close(client_socket);
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }
    }

    close(server_socket);
    return 0;
}