//Gemma-7B DATASET v1.0 Category: Chat server ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int client_fd[MAX_CLIENTS] = { -1 };
    int num_clients = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        return 1;
    }

    printf("Server listening on port 8888...\n");

    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

        if (newsockfd < 0)
        {
            perror("Error accepting client");
            continue;
        }

        client_fd[num_clients] = newsockfd;
        num_clients++;

        printf("Client connected: %d\n", client_fd[num_clients - 1]);

        // Send a welcome message to the client
        sprintf(buffer, "Welcome to the chat server, client %d!", num_clients);
        send(client_fd[num_clients - 1], buffer, strlen(buffer), 0);

        // Listen for client messages
        while (1)
        {
            // Receive a message from the client
            int recv_len = recv(client_fd[num_clients - 1], buffer, 1024, 0);

            // If the client has sent a message
            if (recv_len > 0)
            {
                // Broadcast the message to the other clients
                for (int i = 0; i < num_clients; i++)
                {
                    if (client_fd[i] != client_fd[num_clients - 1])
                    {
                        send(client_fd[i], buffer, recv_len, 0);
                    }
                }

                // Echo the message back to the client
                send(client_fd[num_clients - 1], buffer, recv_len, 0);
            }

            // If the client has disconnected, close the connection
            if (recv_len == 0)
            {
                close(client_fd[num_clients - 1]);
                client_fd[num_clients - 1] = -1;
                num_clients--;
                printf("Client disconnected: %d\n", client_fd[num_clients - 1]);
                break;
            }
        }
    }

    return 0;
}