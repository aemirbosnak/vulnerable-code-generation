//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define PORT 21
#define MAXBUF 1024

int main(int argc, char** argv) {
    // The uncanny valley of networking
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAXBUF];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s <hostname> <filename>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Can't open socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Can't find host %s\n", argv[1]);
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Can't connect to host");
        exit(1);
    }

    // The twilight zone of data transfer
    bzero(buffer, MAXBUF);
    sprintf(buffer, "USER anonymous\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Can't send data");
        exit(1);
    }

    bzero(buffer, MAXBUF);
    sprintf(buffer, "PASS guest@example.com\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Can't send data");
        exit(1);
    }

    bzero(buffer, MAXBUF);
    sprintf(buffer, "RETR %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Can't send data");
        exit(1);
    }

    int file = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file < 0) {
        perror("Can't open file");
        exit(1);
    }

    while ((n = read(sockfd, buffer, MAXBUF)) > 0) {
        write(file, buffer, n);
    }
    if (n < 0) {
        perror("Can't receive data");
        exit(1);
    }

    close(file);
    close(sockfd);

    return 0;
}