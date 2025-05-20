//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/telnet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 10

struct host_info {
    char *host;
    int port;
};

int main() {
    int sock, client_sock;
    struct host_info hosts[MAX_CONNECTIONS];
    socklen_t client_len = sizeof(struct host_info);
    char buffer[256];

    // Initialize the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CONNECTIONS) < 0) {
        perror("listening failed");
        exit(1);
    }

    // Loop through and accept connections
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if ((client_sock = accept(sock, (struct sockaddr *)&server_addr, &client_len)) < 0) {
            perror("accept failed");
            exit(1);
        }

        // Get the host and port from the client
        struct host_info *host = (struct host_info *)buffer;
        recv(client_sock, buffer, 256, 0);
        sscanf(buffer, "%s %d", host->host, &host->port);

        // Print the host and port to the console
        printf("Client connected from %s on port %d\n", host->host, host->port);

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(sock);

    return 0;
}