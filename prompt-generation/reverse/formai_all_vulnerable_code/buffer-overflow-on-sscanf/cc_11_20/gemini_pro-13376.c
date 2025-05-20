//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <user>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server = argv[1];
    char *user = argv[2];

    // Create a socket for the POP3 connection.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command to the POP3 server.
    char buf[1024];
    snprintf(buf, sizeof(buf), "USER %s\r\n", user);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the USER command was successful.
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the PASS command to the POP3 server.
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the PASS command was successful.
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the STAT command to the POP3 server.
    snprintf(buf, sizeof(buf), "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the number of messages and the total size of the messages.
    int num_messages, total_size;
    sscanf(buf, "+OK %d %d", &num_messages, &total_size);
    printf("Number of messages: %d\n", num_messages);
    printf("Total size of messages: %d\n", total_size);

    // Send the LIST command to the POP3 server.
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the POP3 server.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the list of messages.
    char *p = buf;
    while (*p != '\0') {
        int message_number, message_size;
        sscanf(p, "%d %d", &message_number, &message_size);
        printf("Message %d: %d bytes\n", message_number, message_size);
        p += strlen(p) + 1;
    }

    // Send the QUIT command to the POP3 server.
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}