//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555
#define MAX_CONNECTIONS 10

typedef struct {
    int fd;
    struct sockaddr_in addr;
    socklen_t addr_len;
    time_t last_activity;
} connection_t;

connection_t connections[MAX_CONNECTIONS];
int num_connections = 0;

void handle_connection(int fd) {
    char buf[1024];
    int n;

    while ((n = recv(fd, buf, sizeof(buf), 0)) > 0) {
        // Do something with the data
        printf("Received data from %s:%d: %s\n", inet_ntoa(connections[fd].addr.sin_addr), ntohs(connections[fd].addr.sin_port), buf);

        // Update the last activity time
        connections[fd].last_activity = time(NULL);
    }

    // The connection has been closed
    close(fd);
    connections[fd].fd = -1;
    num_connections--;
}

void check_connections() {
    time_t now = time(NULL);

    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].fd != -1 && (now - connections[i].last_activity) > 300) {
            // The connection has been idle for too long, close it
            close(connections[i].fd);
            connections[i].fd = -1;
            num_connections--;
        }
    }
}

int main() {
    int sockfd, newsockfd;

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept a new connection
        newsockfd = accept(sockfd, (struct sockaddr *)&connections[num_connections].addr, &connections[num_connections].addr_len);
        if (newsockfd == -1) {
            perror("accept");
            continue;
        }

        // Add the new connection to the list of connections
        connections[num_connections].fd = newsockfd;
        num_connections++;

        // Spawn a new thread to handle the connection
        pthread_t thread;
        pthread_create(&thread, NULL, (void *)handle_connection, (void *)newsockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}