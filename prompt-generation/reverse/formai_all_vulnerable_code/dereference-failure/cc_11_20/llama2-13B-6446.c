//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define MAX_MESSAGE_LENGTH 1024

struct client_info {
    int sock;
    char username[50];
};

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_MESSAGE_LENGTH];
    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    int i;

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set address and port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    // Bind the server socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept an incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // Create a new client structure
        struct client_info *client = (struct client_info *)malloc(sizeof(struct client_info));
        client->sock = client_fd;
        gets(client->username, sizeof(client->username), stdin);

        // Add the client to the list of connected clients
        for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            if (clients[i].sock == 0) {
                clients[i].sock = client_fd;
                clients[i].username[0] = 0;
                break;
            }
        }

        // Handle client messages
        while (1) {
            printf("Server> ");
            fgets(buffer, MAX_MESSAGE_LENGTH, stdin);
            if (strcmp(buffer, "QUIT") == 0) {
                break;
            }

            // Send the message to all connected clients
            for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
                if (clients[i].sock != client_fd) {
                    send(clients[i].sock, buffer, strlen(buffer), 0);
                }
            }
        }

        // Close the client socket
        close(client_fd);

        // Remove the client from the list of connected clients
        for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            if (clients[i].sock == client_fd) {
                clients[i].sock = 0;
                break;
            }
        }
    }

    return 0;
}