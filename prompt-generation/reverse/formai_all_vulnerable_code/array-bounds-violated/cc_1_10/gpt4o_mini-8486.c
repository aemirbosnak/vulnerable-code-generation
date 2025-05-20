//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define POP3_PORT 110

typedef struct {
    char *hostname;
    char *username;
    char *password;
} POP3Client;

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("Received: %s", buffer);
        if (strstr(buffer, "+OK") != NULL) {
            break; // Exit if we receive a positive response
        }
    }
}

void pop3_connect(POP3Client *client) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    
    if (inet_pton(AF_INET, client->hostname, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server at %s\n", client->hostname);

    receive_response(sockfd); // Receive welcome message

    char command[BUFFER_SIZE];

    // Authenticate
    snprintf(command, sizeof(command), "USER %s\r\n", client->username);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", client->password);
    send_command(sockfd, command);
    receive_response(sockfd);

    // List messages
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Retrieve a specific email, e.g., the first one
    snprintf(command, sizeof(command), "RETR 1\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Quit session
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    POP3Client client;
    client.hostname = argv[1];
    client.username = argv[2];
    client.password = argv[3];

    pop3_connect(&client);

    return EXIT_SUCCESS;
}