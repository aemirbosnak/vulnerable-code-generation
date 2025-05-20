//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LEN 1024
#define MAX_MESSAGE_LEN 512

struct client {
    int sock;
    char name[MAX_CLIENT_LEN];
};

int main(int argc, char *argv[]) {
    int listen_sock, client_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char message[MAX_MESSAGE_LEN];

    // Create the listening socket
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1234);

    // Bind the listening socket to the address and port
    if (bind(listen_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", server.sin_port);

    while (1) {
        // Accept an incoming connection
        if ((client_sock = accept(listen_sock, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Read the client's name
        printf("Welcome, %s!", client.sin_addr.s_addr);
        scanf("%s", message);

        // Echo the client's message back to them
        send(client_sock, message, strlen(message), 0);

        // Close the client's socket
        close(client_sock);
    }

    return 0;
}