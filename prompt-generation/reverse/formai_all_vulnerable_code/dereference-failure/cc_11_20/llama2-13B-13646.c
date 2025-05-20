//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct user {
    char *name;
    char *message;
};

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[256];
    struct user users[5];
    int i;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the server socket
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Chat server listening on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_sock = accept(sock, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Add the client to the list of users
        for (i = 0; i < sizeof(users) / sizeof(users[0]); i++) {
            if (strcmp(users[i].name, "") == 0) {
                break;
            }
        }
        users[i].name = strdup(client.sin_addr.s_addr == INADDR_ANY ? " anonymous" : inet_ntoa(client.sin_addr));
        users[i].message = NULL;

        // Handle incoming messages
        while (1) {
            recv(client_sock, buffer, 255, 0);
            if (buffer[0] == '\0') {
                break;
            }
            users[i].message = strdup(buffer);

            // Broadcast the message to all clients
            sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&server, sizeof(server));
        }

        // Close the client socket
        close(client_sock);
    }

    return 0;
}