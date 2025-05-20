//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main()
{
    int server_socket, client_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(server_socket, BACKLOG) == -1)
    {
        printf("Error listening on socket\n");
        exit(3);
    }

    printf("Server listening on port %d\n", PORT);

    while (1)
    {
        addrlen = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1)
        {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected with IP address %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (fork() == 0)
        {
            close(server_socket);
            handle_client(client_socket);
            exit(0);
        }
        else
        {
            close(client_socket);
        }
    }

    return 0;
}

void handle_client(int client_socket)
{
    char buffer[BUFFER_SIZE];
    int bytes_received, total_bytes = 0;

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0)
        {
            printf("Client disconnected\n");
            break;
        }

        total_bytes += bytes_received;
        printf("Received %d bytes from client (%d bytes in total)\n", bytes_received, total_bytes);

        if (send(client_socket, buffer, bytes_received, 0)!= bytes_received)
        {
            printf("Error sending data to client\n");
            break;
        }
    }

    close(client_socket);
}