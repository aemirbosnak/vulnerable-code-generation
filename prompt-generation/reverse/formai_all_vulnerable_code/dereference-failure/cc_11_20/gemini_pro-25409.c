//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21
#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create a socket for communicating with the FTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the FTP server
    char buf[MAX_BUF_SIZE];
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the USER command to the FTP server
    snprintf(buf, MAX_BUF_SIZE, "USER anonymous\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the PASS command to the FTP server
    snprintf(buf, MAX_BUF_SIZE, "PASS anonymous@example.com\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the TYPE command to the FTP server
    snprintf(buf, MAX_BUF_SIZE, "TYPE I\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the FTP server
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RETR command to the FTP server
    snprintf(buf, MAX_BUF_SIZE, "RETR %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Open a file for writing the downloaded data
    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the data from the FTP server and write it to the file
    while (1) {
        int n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
        if (n < 0) {
            perror("recv");
            return EXIT_FAILURE;
        } else if (n == 0) {
            break;
        }
        fwrite(buf, 1, n, fp);
    }

    // Close the file
    fclose(fp);

    // Send the QUIT command to the FTP server
    snprintf(buf, MAX_BUF_SIZE, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}