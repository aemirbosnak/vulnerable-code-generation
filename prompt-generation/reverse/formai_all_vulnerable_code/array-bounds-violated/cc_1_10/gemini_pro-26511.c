//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define MAX_DATA_SIZE 1024

struct client_info {
    int sockfd;
    char username[MAX_DATA_SIZE];
    char password[MAX_DATA_SIZE];
    char current_directory[MAX_DATA_SIZE];
};

struct server_info {
    int sockfd;
    struct sockaddr_in addr;
    int num_clients;
    struct client_info clients[MAX_CLIENTS];
};

int main() {
    struct server_info server;

    // Create a socket for the server.
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd == -1) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Set the server's address and port.
    server.addr.sin_family = AF_INET;
    server.addr.sin_port = htons(21);
    server.addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server's address.
    if (bind(server.sockfd, (struct sockaddr *)&server.addr, sizeof(server.addr)) == -1) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections.
    if (listen(server.sockfd, 5) == -1) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections.
    while (1) {
        int new_sockfd;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        new_sockfd = accept(server.sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_sockfd == -1) {
            perror("accept() failed");
            continue;
        }

        // Add the new client to the server's list of clients.
        server.clients[server.num_clients].sockfd = new_sockfd;
        server.clients[server.num_clients].username[0] = '\0';
        server.clients[server.num_clients].password[0] = '\0';
        server.clients[server.num_clients].current_directory[0] = '/';
        server.num_clients++;

        // Send a welcome message to the new client.
        char welcome_message[] = "Welcome to the FTP server.\n";
        send(new_sockfd, welcome_message, strlen(welcome_message), 0);
    }

    // Close the server's socket.
    close(server.sockfd);

    return 0;
}