//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    char buf[BUFSIZE];
    strcpy(buf, "USER anonymous\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive a response from the server
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the response
    printf("%s", buf);

    // Send a message to the server
    strcpy(buf, "PASS anonymous@example.com\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive a response from the server
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the response
    printf("%s", buf);

    // Send a message to the server
    strcpy(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive a response from the server
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Print the response
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}