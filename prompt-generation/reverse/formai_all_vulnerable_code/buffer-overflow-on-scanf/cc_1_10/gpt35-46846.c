//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("ERROR invalid address");

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    char user[BUF_SIZE], pass[BUF_SIZE];
    printf("User: ");
    scanf("%s", user); 
    sprintf(buffer, "USER %s\r\n", user);
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "PASS %s\r\n", pass);
    write(sockfd, buffer, strlen(buffer)); 
    
    printf("FTP Client connected to %s:%d\n", argv[1], portno);
    printf("%s", buffer);

    while (1) {
        printf("ftp> ");
        bzero(buffer, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);
        if (strcmp(buffer, "quit\n") == 0)
            break;

        write(sockfd, buffer, strlen(buffer));
        bzero(buffer, BUF_SIZE);
        n = read(sockfd, buffer, BUF_SIZE - 1);
        if (n < 0)
            error("ERROR reading from socket");
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}