//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

struct client {
    int sockfd;
    struct sockaddr_in addr;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int sockfd) {
    char buf[MAX_MSG_SIZE];
    int n;

    while ((n = read(sockfd, buf, MAX_MSG_SIZE)) > 0) {
        buf[n] = '\0';
        printf("Received message: %s\n", buf);

        if (strcmp(buf, "on") == 0) {
            printf("Turning on light\n");
            // Send a message to the light to turn it on
        } else if (strcmp(buf, "off") == 0) {
            printf("Turning off light\n");
            // Send a message to the light to turn it off
        } else {
            printf("Unknown command: %s\n", buf);
            // Send an error message back to the client
        }
    }

    if (n == 0) {
        printf("Client disconnected\n");
        close(sockfd);
    } else {
        printf("Error reading from client\n");
        close(sockfd);
    }
}

int main() {
    int sockfd, newsockfd, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    printf("Enter port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (newsockfd < 0) {
            perror("Error accepting client");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Max clients reached\n");
            close(newsockfd);
            continue;
        }

        clients[num_clients].sockfd = newsockfd;
        clients[num_clients].addr = client_addr;
        num_clients++;

        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client(newsockfd);
    }

    close(sockfd);

    return 0;
}