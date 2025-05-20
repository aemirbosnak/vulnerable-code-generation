//Falcon-180B DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket_desc)
{
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(*((int *) socket_desc), buffer, BUFFER_SIZE, 0)) > 0)
    {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", *((int *) socket_desc), buffer);
        for (int i = 0; i < client_count; i++)
        {
            if (i!= *((int *) socket_desc))
            {
                send(client_sockets[i], buffer, bytes_received, 0);
            }
        }
    }

    close(*((int *) socket_desc));
    client_sockets[client_count - 1] = 0;
    client_count--;
}

int main()
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_socket, MAX_CLIENTS);

    printf("Chat server started on port %d\n", PORT);

    while (1)
    {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_count >= MAX_CLIENTS)
        {
            send(client_socket, "Server is full. Please try later.\n", strlen("Server is full. Please try later.\n"), 0);
            close(client_socket);
        }
        else
        {
            client_sockets[client_count] = client_socket;
            client_count++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        }
    }

    return 0;
}