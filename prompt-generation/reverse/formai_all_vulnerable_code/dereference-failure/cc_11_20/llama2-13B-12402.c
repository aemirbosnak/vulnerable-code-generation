//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 256

struct client {
    int sock;
    char name[50];
};

int main(void) {
    int server_sock;
    struct client clients[MAX_CLIENTS];
    int i;

    // Create the server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Bind the server socket to a specific address and port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Create a new client structure and store the client's address
        struct client *new_client = malloc(sizeof(struct client));
        new_client->sock = client_sock;
        getnameinfo((struct sockaddr *)&client_sock, sizeof(client_sock),
                    new_client->name, sizeof(new_client->name), NULL, 0, NULL);

        // Add the new client to the list of connected clients
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock == 0) {
                clients[i].sock = client_sock;
                strcpy(clients[i].name, new_client->name);
                break;
            }
        }

        // Handle incoming messages from clients
        while (1) {
            char message[MAX_MESSAGE_LENGTH];
            int bytes_read = read(client_sock, message, MAX_MESSAGE_LENGTH);
            if (bytes_read < 0) {
                perror("read failed");
                break;
            }
            printf("Received message from client: %s\n", message);

            // Broadcast the message to all connected clients
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].sock != client_sock) {
                    send(clients[i].sock, message, bytes_read, 0);
                }
            }
        }

        // Close the client socket and free the client structure
        close(client_sock);
        free(new_client);
    }

    return 0;
}