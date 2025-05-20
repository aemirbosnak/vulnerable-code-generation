//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_RULES 100
#define MAX_RULE_SIZE 100
#define DEFAULT_PORT 8080

typedef struct {
    char *ip;
    int port;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, port;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[256];

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cli_addr);

        // Accept a connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        // Get the client's IP address and port
        char *client_ip = inet_ntoa(cli_addr.sin_addr);
        int client_port = ntohs(cli_addr.sin_port);

        // Check if the client's IP address and port are allowed
        int allowed = 0;
        for (int i = 0; i < num_rules; i++) {
            if (strcmp(client_ip, rules[i].ip) == 0 && client_port == rules[i].port) {
                allowed = 1;
                break;
            }
        }

        // If the client's IP address and port are not allowed, send an error message
        if (!allowed) {
            char *error_message = "You are not allowed to access this server.\n";
            send(newsockfd, error_message, strlen(error_message), 0);
            close(newsockfd);
            continue;
        }

        // Receive data from the client
        memset(buffer, 0, sizeof(buffer));
        int n = recv(newsockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        // Send data back to the client
        char *response = "Hello, world!\n";
        send(newsockfd, response, strlen(response), 0);

        // Close the connection
        close(newsockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}