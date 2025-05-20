//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 21

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) == -1) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[1024];

    // Send USER command
    sprintf(buffer, "USER anonymous\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    // Check response
    if (strncmp(buffer, "331", 3) != 0) {
        fprintf(stderr, "Error: Invalid response from server: %s\n", buffer);
        exit(1);
    }

    // Send PASS command
    sprintf(buffer, "PASS \r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    // Check response
    if (strncmp(buffer, "230", 3) != 0) {
        fprintf(stderr, "Error: Invalid response from server: %s\n", buffer);
        exit(1);
    }

    // Send LIST command
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) == -1) {
        perror("recv");
        exit(1);
    }

    // Print response
    printf("%s", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}