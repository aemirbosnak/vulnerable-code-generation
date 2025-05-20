//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1)
    {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port 8080\n");

    while (1)
    {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1)
        {
            printf("Error accepting connection\n");
            continue;
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        while (1)
        {
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0)
            {
                printf("Client disconnected\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1)
            {
                printf("Error sending data\n");
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);
}