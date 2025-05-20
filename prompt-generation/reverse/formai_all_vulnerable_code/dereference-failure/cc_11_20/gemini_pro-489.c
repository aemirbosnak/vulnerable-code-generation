//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
// The Postal Protocol, or POP, is a protocol for retrieving electronic mail messages from a remote server.
// POP3 is a simple, text-based protocol.
// This program is a simple POP3 client.
// It connects to a POP3 server, authenticates with a username and password,
// and retrieves all messages from the server.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server name and username from the command line arguments.
    char *server = argv[1];
    char *username = argv[2];

    // Get the IP address of the server.
    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", server);
        return EXIT_FAILURE;
    }

    // Create a socket and connect to the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return EXIT_FAILURE;
    }

    // Send the USER command.
    char buf[1024];
    sprintf(buf, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send USER command\n");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        return EXIT_FAILURE;
    }

    // Check if the server's response is positive.
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Server's response was not positive: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the PASS command.
    sprintf(buf, "PASS %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send PASS command\n");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        return EXIT_FAILURE;
    }

    // Check if the server's response is positive.
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Server's response was not positive: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the STAT command.
    strcpy(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send STAT command\n");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        return EXIT_FAILURE;
    }

    // Parse the server's response.
    int num_messages;
    int total_size;
    sscanf(buf, "+OK %d %d\r\n", &num_messages, &total_size);

    // Print the number of messages and the total size of the messages.
    printf("Number of messages: %d\n", num_messages);
    printf("Total size of messages: %d\n", total_size);

    // Send the LIST command.
    strcpy(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send LIST command\n");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    int i;
    for (i = 0; i < num_messages; i++) {
        if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
            fprintf(stderr, "Error: Could not receive server's response\n");
            return EXIT_FAILURE;
        }

        // Parse the server's response.
        int message_number;
        int message_size;
        sscanf(buf, "%d %d\r\n", &message_number, &message_size);

        // Print the message number and the message size.
        printf("Message %d: %d bytes\n", message_number, message_size);
    }

    // Send the QUIT command.
    strcpy(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send QUIT command\n");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        return EXIT_FAILURE;
    }

    // Check if the server's response is positive.
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Server's response was not positive: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}