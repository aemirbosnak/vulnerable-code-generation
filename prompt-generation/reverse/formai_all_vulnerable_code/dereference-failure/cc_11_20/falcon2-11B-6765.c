//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main() {
    struct addrinfo hints, *servinfo, *p;
    int sockfd, portno, n;
    char buffer[BUFFER_SIZE];
    char *hostname;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("example.com", "21", &hints, &servinfo);

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    portno = servinfo->ai_addrlen;
    if (connect(sockfd, servinfo->ai_addr, portno) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    printf("Connected to FTP server\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            fprintf(stderr, "Error receiving data\n");
            exit(1);
        }
        if (strstr(buffer, "220")!= NULL) {
            printf("220: %s\n", buffer);
        } else if (strstr(buffer, "500")!= NULL) {
            printf("500: %s\n", buffer);
        } else if (strstr(buffer, "200")!= NULL) {
            printf("200: %s\n", buffer);
        } else if (strstr(buffer, "230")!= NULL) {
            printf("230: %s\n", buffer);
        } else if (strstr(buffer, "331")!= NULL) {
            printf("331: %s\n", buffer);
        } else if (strstr(buffer, "332")!= NULL) {
            printf("332: %s\n", buffer);
        } else if (strstr(buffer, "230")!= NULL) {
            printf("230: %s\n", buffer);
        } else if (strstr(buffer, "125")!= NULL) {
            printf("125: %s\n", buffer);
        } else if (strstr(buffer, "226")!= NULL) {
            printf("226: %s\n", buffer);
        } else if (strstr(buffer, "425")!= NULL) {
            printf("425: %s\n", buffer);
        } else if (strstr(buffer, "450")!= NULL) {
            printf("450: %s\n", buffer);
        } else if (strstr(buffer, "530")!= NULL) {
            printf("530: %s\n", buffer);
        } else if (strstr(buffer, "421")!= NULL) {
            printf("421: %s\n", buffer);
        } else if (strstr(buffer, "503")!= NULL) {
            printf("503: %s\n", buffer);
        } else {
            printf("Unknown response: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}