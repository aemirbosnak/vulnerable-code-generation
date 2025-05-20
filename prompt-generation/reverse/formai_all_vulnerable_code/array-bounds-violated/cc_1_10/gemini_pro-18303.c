//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNECTIONS 100
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} connection_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;

void handle_connection(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        // Handle the received data
        printf("Received %d bytes from %s:%d\n", bytes_received, inet_ntoa(connections[sockfd].addr.sin_addr), ntohs(connections[sockfd].addr.sin_port));

        // Check for malicious activity
        if (strstr(buffer, "malicious") != NULL) {
            printf("Detected malicious activity from %s:%d\n", inet_ntoa(connections[sockfd].addr.sin_addr), ntohs(connections[sockfd].addr.sin_port));

            // Block the connection
            close(sockfd);

            // Remove the connection from the list
            for (int i = 0; i < num_connections; i++) {
                if (connections[i].sockfd == sockfd) {
                    connections[i] = connections[num_connections - 1];
                    num_connections--;
                    break;
                }
            }
        }
    }

    // The connection has been closed
    printf("Connection from %s:%d closed\n", inet_ntoa(connections[sockfd].addr.sin_addr), ntohs(connections[sockfd].addr.sin_port));

    // Remove the connection from the list
    for (int i = 0; i < num_connections; i++) {
        if (connections[i].sockfd == sockfd) {
            connections[i] = connections[num_connections - 1];
            num_connections--;
            break;
        }
    }
}

int main() {
    int sockfd, newsockfd, port;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind the socket to the address and port
    port = 8080;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        return 1;
    }

    printf("Intrusion detection system listening on port %d\n", port);

    // Accept connections
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Add the connection to the list
        connections[num_connections].sockfd = newsockfd;
        connections[num_connections].addr = cli_addr;
        num_connections++;

        // Handle the connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handle_connection, (void *) newsockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}