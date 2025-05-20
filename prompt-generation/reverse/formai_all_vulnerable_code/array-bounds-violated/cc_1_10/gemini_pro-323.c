//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_socket) {
    char buffer[1024];
    while (1) {
        // Receive data from the client
        int len = recv(client_socket, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            // Client has disconnected
            close(client_socket);
            client_sockets[client_socket] = -1;
            num_clients--;
            break;
        }

        // Process the data (e.g., validate the temperature reading)

        // Send data back to the client
        send(client_socket, buffer, len, 0);
    }
}

void handle_sigint(int signum) {
    // Clean up and exit
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != -1) {
            close(client_sockets[i]);
        }
    }
    close(server_socket);
    exit(0);
}

int main() {
    // Create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the server socket to the port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Set up signal handler to handle Ctrl-C
    signal(SIGINT, handle_sigint);

    // Main loop: accept incoming connections and handle them in a separate thread
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Add the client socket to the list of client sockets
        client_sockets[num_clients] = client_socket;
        num_clients++;

        // Create a new thread to handle the client
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *) handle_client, (void *) client_socket) != 0) {
            perror("pthread_create");
            close(client_socket);
            client_sockets[num_clients] = -1;
            num_clients--;
        }
    }

    return 0;
}