//FormAI DATASET v1.0 Category: Browser Plugin ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HEADER_SIZE 4096
#define BODY_SIZE 1048576

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[HEADER_SIZE + BODY_SIZE];

    if(argc < 2) {
        fprintf(stderr,"usage %s url\n", argv[0]);
        exit(1);
    }

    // parse url
    char host[1024], path[1024];
    if(sscanf(argv[1], "http://%[^/]/%s", host, path) == 2) {
        portno = 80;
    } else if(sscanf(argv[1], "https://%[^/]/%s", host, path) == 2) {
        portno = 443;
    } else {
        fprintf(stderr, "unsupported protocol\n");
        exit(1);
    }
    printf("host: %s, path: %s\n", host, path);

    // connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("ERROR opening socket");
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(host);
    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // construct request
    int request_len = sprintf(buffer, "GET /%s HTTP/1.0\r\n", path);
    request_len += sprintf(buffer + request_len, "Host: %s\r\n", host);
    request_len += sprintf(buffer + request_len, "Accept: */*\r\n");
    request_len += sprintf(buffer + request_len, "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.90 Safari/537.36\r\n");
    request_len += sprintf(buffer + request_len, "\r\n");
    printf("request:\n%s\n", buffer);

    // send request
    n = write(sockfd, buffer, request_len);
    if(n < 0) {
        error("ERROR writing to socket");
    }

    // receive response
    int size = 0;
    while((n = read(sockfd, buffer + size, HEADER_SIZE + BODY_SIZE - size)) > 0) {
        size += n;
    }
    if(n < 0) {
        error("ERROR reading from socket");
    }

    // print response
    printf("response:\n%s\n", buffer);

    // close connection
    close(sockfd);

    return 0;
}