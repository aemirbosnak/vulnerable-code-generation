//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

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

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    while (1)
    {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (client_socket == -1)
        {
            printf("Error accepting client connection.\n");
            continue;
        }

        printf("Client connected.\n");

        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);

            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0)
            {
                printf("Client disconnected.\n");
                break;
            }

            send(server_socket, buffer, bytes_received, 0);

            int bytes_sent = recv(server_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_sent <= 0)
            {
                printf("Server disconnected.\n");
                break;
            }

            send(client_socket, buffer, bytes_sent, 0);
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}