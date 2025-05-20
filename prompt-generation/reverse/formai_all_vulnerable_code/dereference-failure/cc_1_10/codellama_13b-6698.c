//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Setup the server address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock < 0) {
        perror("accept");
        exit(1);
    }

    // Setup the client information
    char *client_name = inet_ntoa(client_addr.sin_addr);
    int client_port = ntohs(client_addr.sin_port);

    // Print the client information
    printf("Client connected from %s:%d\n", client_name, client_port);

    // Setup the select() timeout
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    // Loop to receive messages from the client
    while (1) {
        // Setup the file descriptors for select()
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(client_sock, &fds);

        // Wait for incoming messages from the client
        int ready = select(client_sock + 1, &fds, NULL, NULL, &timeout);
        if (ready == 0) {
            printf("Client %s:%d timed out\n", client_name, client_port);
            break;
        }
        else if (ready < 0) {
            perror("select");
            exit(1);
        }

        // Receive the message from the client
        char buffer[1024];
        int bytes = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes < 0) {
            perror("recv");
            exit(1);
        }
        else if (bytes == 0) {
            printf("Client %s:%d disconnected\n", client_name, client_port);
            break;
        }

        // Print the message from the client
        printf("Client %s:%d sent: %s\n", client_name, client_port, buffer);
    }

    // Close the client socket
    close(client_sock);

    // Close the server socket
    close(sock);

    return 0;
}