//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define PORT 8080

struct client_info {
    int sock;
    char ip[16];
};

int main(void) {
    int listen_sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    int status;
    char buffer[256];
    struct client_info clients[MAX_CLIENTS];
    int i;

    // Create the listen socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the listen socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_sock = accept(listen_sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Get the client IP address and port number
        getpeername(client_sock, (struct sockaddr *)&client, &client_len);
        printf("Client connected from IP address %s and port %d\n",
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Add the client to the list of active clients
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock == 0) {
                clients[i].sock = client_sock;
                strcpy(clients[i].ip, inet_ntoa(client.sin_addr));
                break;
            }
        }

        // Handle incoming data from the client
        while (1) {
            read(client_sock, buffer, 256);
            if (buffer[0] == '\0') {
                break;
            }
            printf("Client message: %s\n", buffer);

            // Send a response back to the client
            char *message = "Hello, client!";
            send(client_sock, message, strlen(message), 0);
        }

        // Close the client socket and remove the client from the list
        close(client_sock);
        for (int j = 0; j < MAX_CLIENTS; j++) {
            if (clients[j].sock == client_sock) {
                clients[j].sock = 0;
                break;
            }
        }
    }

    return 0;
}