//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFSIZE 8096

//Function to handle HTTP requests
void handle_request(int connfd) {
    char buffer[BUFFSIZE], method[255], url[255], protocol[255];
    int i, j, k;
    ssize_t recv_size;
    char *hostname;
    struct addrinfo hints, *res;
    int sockfd;
    
    recv_size = recv(connfd, buffer, BUFFSIZE, 0); //receive client request 
    if(recv_size > 0) {
        //Parse request into method, url and protocol
        sscanf(buffer, "%s%s%s", method, url, protocol);
        //Check if method is GET and protocol is HTTP/1.0 or HTTP/1.1
        if(strcasecmp(method, "GET") == 0 && ((strcasecmp(protocol, "HTTP/1.0") == 0) || (strcasecmp(protocol, "HTTP/1.1") == 0))) {
            //Check if URL contains "http://" to remove it
            if(strncmp(url, "http://", 7) == 0) {
                hostname = strdup(url + 7);
                for(i = 0; hostname[i] != '\0'; i++) {
                    if(hostname[i] == '/') {
                        hostname[i] = '\0';
                        break;
                    }
                }
            } else {
                hostname = strdup(url);
                for(i = 0; hostname[i] != '\0'; i++) {
                    if(hostname[i] == '/') {
                        hostname[i] = '\0';
                        break;
                    }
                }
            }
            char *path = strdup(url + i);
            //Resolve hostname to IP address
            memset(&hints, 0, sizeof(struct addrinfo));
            hints.ai_family = AF_UNSPEC;
            hints.ai_socktype = SOCK_STREAM;
            if(getaddrinfo(hostname, "80", &hints, &res) != 0) {
                perror("getaddrinfo() error");
                exit(1);
            }
            sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
            if(sockfd < 0) {
                perror("socket() error");
                exit(1);
            }
            //Connect to remote server
            if(connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
                perror("connect() error");
                exit(1);
            }
            printf("\n\nConnected to %s  IP - %s\n", hostname, inet_ntoa(*(struct in_addr*) res->ai_addr));
            snprintf(buffer, sizeof(buffer), "GET /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", path, protocol, hostname);
            //Send request to remote server
            if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
                perror("send() error");
                exit(1);
            }
            else {
                i = 0, j = 0;
                char *ptr = buffer;
                //Read response from remote server and send to client browser
                while((recv_size = recv(sockfd, ptr, BUFFSIZE, 0)) > 0) {
                    i = 0;
                    while(buffer[i] != '\0' && i < recv_size) {
                        if(buffer[i] == '\r' || buffer[i] == '\n') {
                            buffer[i] = '\0';
                            if(j == 0)
                                printf("\n%s", buffer);
                            j = (buffer[i+1] == '\r' || buffer[i+1] == '\n') ? 0 : 1;
                            send(connfd, buffer, strlen(buffer), j);
                            ptr = buffer;
                            memset(ptr, 0, sizeof(buffer));
                            i++;
                            continue;
                        }
                        i++;
                    }
                    memset(ptr, 0, sizeof(buffer));
                }
            }
            close(sockfd);
        } 
        else {
            printf("Not a GET request or protocol not supported\n");
        }
    }

    shutdown(connfd, SHUT_RDWR);
    close(connfd);
}

int main(int argc, char *argv[]) {
    int listenfd, connfd, port, clilen;
    struct sockaddr_in servaddr, cliaddr;

    if(argc != 2) {
        printf("\nUsage: %s <Port Number>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0) {
        perror("socket() error");
        exit(1);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if(bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind() error");
        exit(1);
    }
    if(listen(listenfd, 10) < 0) {
        perror("listen() error");
        exit(1);
    }

    printf("\nSimple HTTP Proxy Server running on Port %d\n\n", port);
    while(1) {
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
        if(connfd < 0) {
            perror("accept() error");
            continue;
        }
        printf("\n\nAccepted connection from %s : %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        handle_request(connfd);
    }
    return 0;
}