//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buff[BUFF_SIZE];
    int n;

    // Send username
    bzero(buff, BUFF_SIZE);
    strcpy(buff, "USER ");
    strcat(buff, argv[2]);
    strcat(buff, "\r\n");
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read response
    bzero(buff, BUFF_SIZE);
    n = read(sockfd, buff, BUFF_SIZE - 1);
    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buff);

    // Send password
    bzero(buff, BUFF_SIZE);
    strcpy(buff, "PASS ");
    strcat(buff, argv[3]);
    strcat(buff, "\r\n");
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read response
    bzero(buff, BUFF_SIZE);
    n = read(sockfd, buff, BUFF_SIZE - 1);
    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buff);

    // Send CWD command
    bzero(buff, BUFF_SIZE);
    strcpy(buff, "CWD /\r\n");
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read response
    bzero(buff, BUFF_SIZE);
    n = read(sockfd, buff, BUFF_SIZE - 1);
    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buff);

    // Send LIST command
    bzero(buff, BUFF_SIZE);
    strcpy(buff, "LIST\r\n");
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read response
    bzero(buff, BUFF_SIZE);
    n = read(sockfd, buff, BUFF_SIZE - 1);
    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buff);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}