//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[])
{
    int listen_socket, client_socket, bytes_read;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc!= 3)
    {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1)
    {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1)
    {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1)
        {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1)
        {
            bytes_read = recv(client_socket, buffer, MAX_LINE, 0);
            if (bytes_read <= 0)
            {
                printf("Client disconnected\n");
                break;
            }

            buffer[bytes_read] = '\0';
            printf("Received: %s\n", buffer);

            send(client_socket, buffer, bytes_read, 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}