//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[MAX_LINE];
    int n;

    // Receive the banner
    if ((n = read(sockfd, buf, MAX_LINE)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the USER command
    snprintf(buf, MAX_LINE, "USER %s\r\n", "sherlock.holmes");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Receive the USER response
    if ((n = read(sockfd, buf, MAX_LINE)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the PASS command
    snprintf(buf, MAX_LINE, "PASS %s\r\n", "elementary");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Receive the PASS response
    if ((n = read(sockfd, buf, MAX_LINE)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the STAT command
    snprintf(buf, MAX_LINE, "STAT\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Receive the STAT response
    if ((n = read(sockfd, buf, MAX_LINE)) < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the LIST command
    snprintf(buf, MAX_LINE, "LIST\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Receive the LIST response
    while ((n = read(sockfd, buf, MAX_LINE)) > 0) {
        printf("%s", buf);
    }
    if (n < 0) {
        perror("read");
        return 1;
    }

    // Send the RETR command
    snprintf(buf, MAX_LINE, "RETR %s\r\n", "case-of-the-dancing-men.txt");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Receive the RETR response
    FILE *fp = fopen("case-of-the-dancing-men.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    while ((n = read(sockfd, buf, MAX_LINE)) > 0) {
        fwrite(buf, 1, n, fp);
    }
    if (n < 0) {
        perror("read");
        return 1;
    }
    fclose(fp);

    // Send the QUIT command
    snprintf(buf, MAX_LINE, "QUIT\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}