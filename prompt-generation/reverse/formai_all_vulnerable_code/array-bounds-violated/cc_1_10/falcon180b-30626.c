//Falcon-180B DATASET v1.0 Category: Firewall ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main()
{
    int server_socket, client_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

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

    printf("Server started on port %d\n", SERVER_PORT);

    while (1)
    {
        addrlen = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1)
        {
            printf("Error accepting connection\n");
            continue;
        }

        if (client_count >= MAX_CLIENTS)
        {
            close(client_socket);
            printf("Maximum number of clients reached\n");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        client_count++;

        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0)
            {
                printf("Client disconnected\n");
                close(client_socket);
                client_count--;
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0)
            {
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}