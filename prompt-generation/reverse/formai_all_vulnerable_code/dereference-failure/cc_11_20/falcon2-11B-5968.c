//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 10
#define MAX_PORT 65535

int main() {
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    struct servent *server_info;
    struct sockaddr_in client_addr;
    int sockfd;
    int port_no = 0;
    int n;
    int opt = 1;
    char *hostname = "localhost";

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error setting socket option");
        exit(1);
    }

    // Get server host information
    server_host = gethostbyname(hostname);
    if (server_host == NULL) {
        fprintf(stderr, "Error: hostname could not be resolved\n");
        exit(1);
    }

    // Fill server_addr structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_no);
    bcopy((char *)server_host->h_addr, (char *)&server_addr.sin_addr.s_addr, server_host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        printf("Waiting for incoming connection...\n");

        // Create a client socket
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Error creating socket");
            exit(1);
        }

        // Set socket options
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
            perror("Error setting socket option");
            exit(1);
        }

        // Fill client_addr structure
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(MAX_PORT);
        client_addr.sin_addr.s_addr = INADDR_ANY;

        // Bind to a free port
        if (bind(sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
            perror("Error binding to port");
            exit(1);
        }

        // Listen for incoming connections
        if (listen(sockfd, MAX_CONNECTIONS) < 0) {
            perror("Error listening for connections");
            exit(1);
        }

        // Accept the incoming connection
        if ((n = accept(sockfd, NULL, NULL)) < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        // Process the incoming connection
        printf("Incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        close(sockfd);
    }

    return 0;
}