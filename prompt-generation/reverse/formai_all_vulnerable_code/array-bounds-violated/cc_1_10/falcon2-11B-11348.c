//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed\n");
        return 1;
    }

    // create socket address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect failed\n");
        return 1;
    }

    // send HTTP request
    char request[1024];
    strcpy(request, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("send failed\n");
        return 1;
    }

    // receive response
    char response[4096];
    memset(response, 0, sizeof(response));
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n < 0) {
        printf("recv failed\n");
        return 1;
    }
    response[n] = '\0';

    // close socket
    close(sockfd);

    printf("%s\n", response);

    return 0;
}