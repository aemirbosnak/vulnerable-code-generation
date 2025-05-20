//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 110
#define HOST "pop.example.com"
#define USER "username"
#define PASS "password"

int main() {
    int sockfd, valread;
    struct hostent *server;
    struct sockaddr_in servaddr;

    char buf[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(HOST);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&servaddr.sin_addr.s_addr,
         server->h_length);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Enter message number to download: ");
    scanf("%d", &valread);

    sprintf(buf, "USER %s\r\n", USER);
    write(sockfd, buf, strlen(buf));
    valread = read(sockfd, buf, 100);

    if (strcmp(buf, "331 ")!= 0) {
        perror("ERROR, user not accepted");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "PASS %s\r\n", PASS);
    write(sockfd, buf, strlen(buf));
    valread = read(sockfd, buf, 100);

    if (strcmp(buf, "230 ")!= 0) {
        perror("ERROR, password not accepted");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "STAT\r\n");
    write(sockfd, buf, strlen(buf));
    valread = read(sockfd, buf, 100);

    if (strcmp(buf, "OK")!= 0) {
        perror("ERROR, unable to get mailbox status");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "LIST\r\n");
    write(sockfd, buf, strlen(buf));
    valread = read(sockfd, buf, 100);

    if (strcmp(buf, "OK")!= 0) {
        perror("ERROR, unable to get message list");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "%d OK\r\n", valread);
    write(sockfd, buf, strlen(buf));

    printf("Message number: %s\n", buf);

    close(sockfd);

    return 0;
}