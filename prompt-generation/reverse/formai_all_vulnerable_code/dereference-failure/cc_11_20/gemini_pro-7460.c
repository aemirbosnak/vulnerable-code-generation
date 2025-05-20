//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <file>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *file = argv[2];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the FTP server.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the USER command.
    char buf[1024];
    sprintf(buf, "USER anonymous\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the PASS command.
    sprintf(buf, "PASS \r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the CWD command.
    sprintf(buf, "CWD /\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the RETR command.
    sprintf(buf, "RETR %s\r\n", file);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Open a file to write the data to.
    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    // Read the data from the socket and write it to the file.
    while (1) {
        int n = recv(sockfd, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("recv");
            return 1;
        } else if (n == 0) {
            break;
        }
        fwrite(buf, 1, n, fp);
    }

    // Close the file.
    fclose(fp);

    // Close the socket.
    close(sockfd);

    return 0;
}