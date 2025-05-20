//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct sockaddr_in server_addr, client_addr;
int server_fd, client_fd;
char buffer[1024];
int addr_len;

int main() {
    // Create a server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept a client connection
    addr_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
    if (client_fd == -1) {
        perror("accept");
        exit(1);
    }

    // Receive data from the client
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = recv(client_fd, buffer, sizeof(buffer), 0);
        if (n == -1) {
            perror("recv");
            exit(1);
        } else if (n == 0) {
            printf("Client disconnected\n");
            break;
        }

        // Process the data
        char *reversed = malloc(n + 1);
        for (int i = 0; i < n; i++) {
            reversed[i] = buffer[n - i - 1];
        }
        reversed[n] = '\0';

        // Send the data back to the client
        if (send(client_fd, reversed, strlen(reversed), 0) == -1) {
            perror("send");
            exit(1);
        }

        free(reversed);
    }

    // Close the client and server sockets
    close(client_fd);
    close(server_fd);

    return 0;
}