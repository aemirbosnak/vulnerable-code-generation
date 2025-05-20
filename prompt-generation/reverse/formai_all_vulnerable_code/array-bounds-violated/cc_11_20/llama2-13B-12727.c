//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: protected
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
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_MESSAGE_LENGTH];
    struct client_info clients[MAX_CLIENT_CONNECTIONS];
    int i;

    // Create the server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set address and port number for the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    // Bind the server socket to the address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(server_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        // Accept an incoming client connection
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept failed");
            continue;
        }

        // Store the client information in the clients array
        for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
            if (clients[i].sock == 0) {
                break;
            }
        }
        clients[i].sock = client_sock;
        strcpy(clients[i].username, "Anonymous");

        // Handle client messages
        while (1) {
            recv(client_sock, buffer, MAX_MESSAGE_LENGTH, 0);
            if (buffer[0] == '\0') {
                break;
            }
            printf("Server: %s\n", buffer);

            // Send the message to all other clients
            for (i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
                if (clients[i].sock != client_sock) {
                    send(clients[i].sock, buffer, strlen(buffer), 0);
                }
            }
        }

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(server_sock);

    return 0;
}