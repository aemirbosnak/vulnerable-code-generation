//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Introspective FTP client
int main(int argc, char **argv) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server IP address\n");
        return EXIT_FAILURE;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send USER command
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "USER anonymous\r\n");
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive response
    char resp[1024];
    int resp_len = recv(sockfd, resp, sizeof(resp) - 1, 0);
    if (resp_len < 0) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }
    resp[resp_len] = '\0';
    printf("Response: %s", resp);

    // Send PASS command
    snprintf(cmd, sizeof(cmd), "PASS \r\n");
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive response
    resp_len = recv(sockfd, resp, sizeof(resp) - 1, 0);
    if (resp_len < 0) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }
    resp[resp_len] = '\0';
    printf("Response: %s", resp);

    // Send LIST command
    snprintf(cmd, sizeof(cmd), "LIST\r\n");
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive response
    resp_len = recv(sockfd, resp, sizeof(resp) - 1, 0);
    if (resp_len < 0) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }
    resp[resp_len] = '\0';
    printf("Response: %s", resp);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}