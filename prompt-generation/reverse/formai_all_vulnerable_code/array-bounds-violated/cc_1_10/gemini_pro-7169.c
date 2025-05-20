//GEMINI-pro DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 10

typedef struct client {
    int sockfd;
    struct sockaddr_in addr;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void send_message(int sockfd, char *msg) {
    int n = send(sockfd, msg, strlen(msg), 0);
    if (n < 0) {
        error("send");
    }
}

void handle_client(int sockfd) {
    char buffer[256];
    int n;

    // Receive message from client
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        error("recv");
    }

    // Process message and send response
    printf("Received message: %s\n", buffer);
    char *response = "Hello from server!\n";
    send_message(sockfd, response);

    // Close client connection
    close(sockfd);
}

int main(int argc, char **argv) {
    int sockfd, newsockfd;
    socklen_t addrlen;
    struct sockaddr_in serv_addr, cli_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket");
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("bind");
    }

    // Listen for clients
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        error("listen");
    }

    // Accept clients
    while (1) {
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);
        if (newsockfd < 0) {
            error("accept");
        }

        // Add client to list
        clients[num_clients].sockfd = newsockfd;
        clients[num_clients].addr = cli_addr;
        num_clients++;

        // Handle client in separate thread
        if (fork() == 0) {
            handle_client(newsockfd);
            exit(0);
        }
    }

    // Close server socket
    close(sockfd);

    return 0;
}