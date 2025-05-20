//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    // Check arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <port> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get host and port
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Get username and password
    char *username = argv[3];
    char *password = argv[4];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get host information
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)hostent->h_addr;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send USER command
    char buf[1024];
    sprintf(buf, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check server response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send PASS command
    sprintf(buf, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check server response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send STAT command
    sprintf(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check server response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Server error: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Parse server response
    int num_messages;
    int total_size;
    sscanf(buf, "+OK %d %d", &num_messages, &total_size);

    // Print number of messages and total size
    printf("Number of messages: %d\n", num_messages);
    printf("Total size: %d\n", total_size);

    // Send QUIT command
    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}