//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// This program is a simple POP3 client.
// It connects to a POP3 server, authenticates with a username and password,
// and then retrieves the first email message.

// The main function.
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments.
    if (argc < 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    printf("Connecting to the POP3 server...\n");
    // Get the hostname and port number from the user's first argument.
    char *hostname = argv[1];
    int port = 110;

    // Create a socket for communicating with the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the POP3 server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected to the POP3 server.\n");

    // Authenticate with the POP3 server.
    char *username = argv[2];
    char *password = argv[3];

    printf("Authenticating with the POP3 server...\n");
    char buf[1024];

    // Send the USER command to the server.
    sprintf(buf, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("Received the server's response: %s\n", buf);

    // Check if the authentication was successful.
    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Authentication failed.\n");
        return 1;
    }

    // Send the PASS command to the server.
    sprintf(buf, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("Received the server's response: %s\n", buf);

    // Check if the authentication was successful.
    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Authentication failed.\n");
        return 1;
    }

    printf("Authentication successful.\n");

    // Retrieve the first email message.
    printf("Retrieving the first email message...\n");

    // Send the RETR command to the server.
    sprintf(buf, "RETR 1\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("Received the server's response: %s\n", buf);

    // Check if the email message was retrieved successfully.
    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Failed to retrieve the email message.\n");
        return 1;
    }

    // Print the email message.
    printf("Email message:\n");

    // Read the email message from the socket.
    while (1) {
        if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            return 1;
        }

        printf("%s", buf);

        // Check if the end of the email message has been reached.
        if (strncmp(buf, "\r\n.\r\n", 5) == 0) {
            break;
        }
    }

    printf("Retrieved the first email message.\n");

    // Close the socket.
    close(sockfd);

    return 0;
}