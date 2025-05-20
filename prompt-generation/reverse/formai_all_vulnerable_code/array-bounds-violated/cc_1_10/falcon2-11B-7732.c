//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_URL_LENGTH 1024

int main() {
    char url[MAX_URL_LENGTH];
    char response[MAX_URL_LENGTH];
    char error[MAX_URL_LENGTH];
    char* pch;
    int sockfd, n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    struct hostent* server;
    server = gethostbyname("www.example.com");

    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    struct sockaddr_in address;
    bzero((char*) &address, sizeof(address));

    address.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &address.sin_addr.s_addr, server->h_length);
    address.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    sprintf(url, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    send(sockfd, url, strlen(url), 0);

    bzero(response, MAX_URL_LENGTH);
    bzero(error, MAX_URL_LENGTH);

    n = recv(sockfd, response, MAX_URL_LENGTH - 1, 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    response[n] = '\0';

    pch = strstr(response, "HTTP/1.1 200 OK");
    if (pch!= NULL) {
        printf("Response code: %s\n", pch + strlen("HTTP/1.1 200 OK"));
        printf("Response message: %s\n", response);
    } else {
        printf("Error: %s\n", error);
    }

    close(sockfd);
    return 0;
}