//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 10000

// main function
int main(int argc, char **argv) {
    // check for correct arguments
    if(argc != 4) {
        printf("usage: ./proxy <server_ip> <server_port> <local_port>\n");
        exit(0);
    }

    // get server ip and port
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // check for valid port number
    if(server_port < 0 || server_port > 65535) {
        printf("invalid server port number\n");
        exit(0);
    }

    // get local port
    int local_port = atoi(argv[3]);

    // check for valid port number
    if(local_port < 0 || local_port > 65535) {
        printf("invalid local port number\n");
        exit(0);
    }

    // create socket for incoming connections
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0) {
        printf("socket creation failed\n");
        exit(0);
    }

    // bind socket to local port
    struct sockaddr_in servaddr, cliaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(local_port);
    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("bind failed\n");
        exit(0);
    }

    // listen for incoming connections
    if(listen(listenfd, 10) < 0) {
        printf("listen failed\n");
        exit(0);
    }

    // accept incoming connections and handle requests
    while(1) {
        // accept connection
        socklen_t len = sizeof(cliaddr);
        int connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
        if(connfd < 0) {
            printf("accept failed\n");
            continue;
        }

        // read request
        char buf[MAXLINE];
        int n = read(connfd, buf, MAXLINE);
        if(n < 0) {
            printf("read failed\n");
            close(connfd);
            continue;
        }
        buf[n] = '\0';

        // connect to server
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd < 0) {
            printf("socket creation failed\n");
            close(connfd);
            continue;
        }
        struct sockaddr_in servaddr2;
        servaddr2.sin_family = AF_INET;
        servaddr2.sin_addr.s_addr = inet_addr(server_ip);
        servaddr2.sin_port = htons(server_port);
        if(connect(sockfd, (struct sockaddr *)&servaddr2, sizeof(servaddr2)) < 0) {
            printf("connection to server failed\n");
            close(connfd);
            close(sockfd);
            continue;
        }

        // send request to server
        write(sockfd, buf, strlen(buf));

        // read response from server
        char response[MAXLINE];
        int len2 = 0;
        while((n = read(sockfd, response + len2, MAXLINE - 1 - len2)) > 0) {
            len2 += n;
        }
        if(n < 0) {
            printf("read from server failed\n");
            close(connfd);
            close(sockfd);
            continue;
        }
        response[len2] = '\0';

        // send response to client
        write(connfd, response, strlen(response));

        // close connections
        close(connfd);
        close(sockfd);
    }

    // exit program
    return 0;
}