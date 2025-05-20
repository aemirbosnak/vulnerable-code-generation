//Falcon-180B DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 8080

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    struct hostent *server;
    char *host;
    int len;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    host = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Error opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        error_handling("Error connecting to server");
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        bzero(buffer, BUF_SIZE);
        ret = recv(sockfd, buffer, BUF_SIZE, 0);
        if (ret < 0) {
            error_handling("Error receiving from server");
        }
        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}

void error_handling(char *message)
{
    perror(message);
    exit(0);
}