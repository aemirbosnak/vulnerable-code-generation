//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ctype.h>
#include <math.h>

// Function to send a message to the server
int send_message(int sockfd, char *message) {
    // Send the length of the message
    int len = strlen(message);
    if (send(sockfd, &len, sizeof(int), 0) == -1) {
        perror("send");
        return -1;
    }

    // Send the message
    if (send(sockfd, message, len, 0) == -1) {
        perror("send");
        return -1;
    }

    return 0;
}

// Function to receive a message from the server
char *receive_message(int sockfd) {
    // Receive the length of the message
    int len;
    if (recv(sockfd, &len, sizeof(int), 0) == -1) {
        perror("recv");
        return NULL;
    }

    // Receive the message
    char *message = malloc(len + 1);
    if (recv(sockfd, message, len, 0) == -1) {
        perror("recv");
        free(message);
        return NULL;
    }

    // Null-terminate the message
    message[len] = '\0';

    return message;
}

// Function to close the socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is given
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get the hostname and port number
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Get the server's address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        return 1;
    }

    // Create the server's address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the username
    char username[256];
    printf("Enter your username: ");
    scanf("%s", username);
    if (send_message(sockfd, username) == -1) {
        return 1;
    }

    // Send the password
    char password[256];
    printf("Enter your password: ");
    scanf("%s", password);
    if (send_message(sockfd, password) == -1) {
        return 1;
    }

    // Main loop
    while (1) {
        // Receive a message from the server
        char *message = receive_message(sockfd);
        if (message == NULL) {
            break;
        }

        // Null-terminate the message
        message[strlen(message)] = '\0';

        // Print the message
        printf("%s\n", message);

        // Free the message
        free(message);

        // Send a message to the server
        char input[256];
        printf("Enter a message: ");
        scanf("%s", input);
        if (send_message(sockfd, input) == -1) {
            break;
        }
    }

    // Close the socket
    close_socket(sockfd);

    return 0;
}