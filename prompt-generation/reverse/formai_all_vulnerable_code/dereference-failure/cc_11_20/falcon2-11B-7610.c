//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>

int main(int argc, char *argv[])
{
    struct addrinfo hints, *res;
    int sockfd;
    struct sockaddr_in server;
    char buffer[100];
    char hostname[100];
    int port;
    int count = 0;
    char message[100];
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (gethostname(hostname, 100) < 0) {
        printf("Failed to get hostname\n");
        return 1;
    }

    if (getaddrinfo(hostname, "80", &hints, &res) < 0) {
        printf("Failed to get address information\n");
        return 1;
    }

    for (res = res; res!= NULL; res = res->ai_next) {
        port = res->ai_addr->sa_family == AF_INET? ntohs(*((unsigned short*)res->ai_addr)) : 0;
        if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }
        if (port) {
            if (send(sockfd, "GET / HTTP/1.0\r\n\r\n", 41, 0) == -1) {
                perror("send");
                close(sockfd);
                continue;
            }
            if (port!= ntohs(*((unsigned short*)res->ai_addr))) {
                printf("%s:%d is not a web server\n", inet_ntoa(res->ai_addr), port);
                close(sockfd);
                continue;
            }
            printf("%s:%d is a web server\n", inet_ntoa(res->ai_addr), port);
            close(sockfd);
        } else {
            if (send(sockfd, "HEAD / HTTP/1.0\r\n\r\n", 30, 0) == -1) {
                perror("send");
                close(sockfd);
                continue;
            }
            if (port!= ntohs(*((unsigned short*)res->ai_addr))) {
                printf("%s:%d is not a web server\n", inet_ntoa(res->ai_addr), port);
                close(sockfd);
                continue;
            }
            printf("%s:%d is a web server\n", inet_ntoa(res->ai_addr), port);
            close(sockfd);
        }
    }
    return 0;
}