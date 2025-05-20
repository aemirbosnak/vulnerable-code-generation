//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    // Check if the user has provided the hostname of the POP3 server
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Create a socket for communicating with the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set up the address of the POP3 server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the USER command to the POP3 server
    char buf[1024];
    snprintf(buf, sizeof(buf), "USER %s\r\n", "username");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the POP3 server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Check if the USER command was successful
    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Authentication failed: %s", buf);
        return 1;
    }

    // Send the PASS command to the POP3 server
    snprintf(buf, sizeof(buf), "PASS %s\r\n", "password");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the POP3 server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Check if the PASS command was successful
    if (strncmp(buf, "+OK", 3) != 0) {
        printf("Authentication failed: %s", buf);
        return 1;
    }

    // Send the STAT command to the POP3 server
    snprintf(buf, sizeof(buf), "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the POP3 server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Parse the STAT response
    int num_messages;
    int total_size;
    sscanf(buf, "+OK %d %d", &num_messages, &total_size);

    // Print the number of messages and the total size of the messages
    printf("Number of messages: %d\n", num_messages);
    printf("Total size of messages: %d\n", total_size);

    // Send the LIST command to the POP3 server
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the POP3 server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Parse the LIST response
    for (int i = 0; i < num_messages; i++) {
        int message_number;
        int message_size;
        sscanf(buf, "%d %d", &message_number, &message_size);

        // Print the message number and size
        printf("Message %d: %d bytes\n", message_number, message_size);
    }

    // Send the QUIT command to the POP3 server
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}