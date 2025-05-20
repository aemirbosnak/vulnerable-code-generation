//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server> <port> <user> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get server address and port
    struct sockaddr_in server_addr;
    const char *server_name = argv[1];
    int port = atoi(argv[2]);
    if (inet_pton(AF_INET, server_name, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address: %s\n", server_name);
        return EXIT_FAILURE;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the USER command
    char buf[1024];
    snprintf(buf, sizeof(buf), "USER %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Error sending USER command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive the server response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Check the server response code
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Server did not accept USER command: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[4]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Error sending PASS command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive the server response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Check the server response code
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: Server did not accept PASS command: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Error sending LIST command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Receive the server response
    int num_messages = 0;
    while (1) {
        if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
            fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        if (strncmp(buf, "+OK", 3) == 0) {
            // End of LIST response
            break;
        }

        if (strncmp(buf, " ", 1) == 0) {
            // This is a message number
            num_messages++;
        }
    }

    printf("Number of messages: %d\n", num_messages);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Error sending QUIT command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Close the socket
    if (close(sockfd) < 0) {
        fprintf(stderr, "Error closing socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}