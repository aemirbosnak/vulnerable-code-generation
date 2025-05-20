//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define SERVER "localhost"
#define USER "anonymous"
#define PASS "anonymous@example.com"

int main() {
    int sockfd, newsockfd, portno, clilen, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    FILE* fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    portno = PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", USER);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", PASS);
    send(sockfd, buffer, strlen(buffer), 0);

    while (1) {
        bzero(buffer, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n == 0) {
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}