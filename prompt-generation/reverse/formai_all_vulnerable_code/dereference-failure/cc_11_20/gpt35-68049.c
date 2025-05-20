//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct addrinfo hints, *servinfo, *p;
    char buf[BUF_SIZE];
    char command[BUF_SIZE];
    char *ftp_host, *ftp_port, *filename;

    if (argc != 4) {
        printf("Usage: %s ftp_host ftp_port filename\n", argv[0]);
        exit(1);
    }

    ftp_host = argv[1];
    ftp_port = argv[2];
    filename = argv[3];

    // Set up hints struct for getaddrinfo call
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ftp_host, ftp_port, &hints, &servinfo) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", strerror(errno));
        exit(1);
    }

    // Loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            fprintf(stderr, "socket error: %s\n", strerror(errno));
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            fprintf(stderr, "connect error: %s\n", strerror(errno));
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect to %s:%s\n", ftp_host, ftp_port);
        exit(1);
    }

    freeaddrinfo(servinfo); // all done with this structure

    // Receive initial welcome message from FTP server
    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // Login to FTP server with username and password
    printf("Username: ");
    fgets(buf, BUF_SIZE, stdin);
    sprintf(command, "USER %s", buf);
    send(sockfd, command, strlen(command) - 1, 0);

    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    printf("Password: ");
    fgets(buf, BUF_SIZE, stdin);
    sprintf(command, "PASS %s", buf);
    send(sockfd, command, strlen(command) - 1, 0);

    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // Send command to set transfer mode to binary
    sprintf(command, "TYPE I");
    send(sockfd, command, strlen(command), 0);

    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // Send command to retrieve file
    sprintf(command, "RETR %s", filename);
    send(sockfd, command, strlen(command), 0);

    // Open file for writing
    FILE *file;
    if ((file = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "fopen error: %s\n", strerror(errno));
        exit(1);
    }

    // Receive file data from server and write to file
    while ((numbytes = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        fwrite(buf, 1, numbytes, file);
    }

    fclose(file);

    if (numbytes == -1) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }

    // Send command to quit
    sprintf(command, "QUIT");
    send(sockfd, command, strlen(command), 0);

    if ((numbytes = recv(sockfd, buf, BUF_SIZE-1, 0)) == -1) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    close(sockfd);

    return 0;
}