//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <errno.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <netdb.h>  
  
#define MAXLINE 4096  
  
int main(int argc, char **argv)  
{  
    int listenfd, connfd;  
    struct sockaddr_in servaddr;  
  
    if(argc != 2){  
        printf("usage: ./http_proxy <port_number> \n");  
        exit(1);  
    }  
  
    listenfd = socket(AF_INET, SOCK_STREAM, 0);  
    if(listenfd == -1){  
        perror("socket");  
        exit(1);  
    }  
  
    bzero(&servaddr,sizeof(struct sockaddr_in));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_port = htons(atoi(argv[1]));  
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  
    
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(struct sockaddr_in))==-1){  
        perror("bind");  
        exit(1);  
    }  
  
    if(listen(listenfd, 20) == -1){  
        perror("listen");  
        exit(1);  
    }  
  
    printf("HTTP proxy started on port %s\n", argv[1]);  
  
    char request[MAXLINE], method[MAXLINE], url[MAXLINE], protocol[MAXLINE];  
    char hostname[MAXLINE], path[MAXLINE];  
    char buffer[MAXLINE], res[MAXLINE];  
    struct hostent *host;  
  
    while(1){  
        printf("\nWaiting for request...\n");  
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);  
        bzero(request, MAXLINE);  
        bzero(method, MAXLINE);  
        bzero(url, MAXLINE);  
        bzero(hostname, MAXLINE);  
        bzero(path, MAXLINE);  
        bzero(protocol, MAXLINE);  
        bzero(buffer, MAXLINE);  
        bzero(res, MAXLINE);  
  
        if(recv(connfd, request, MAXLINE, 0) == -1){  
            perror("recv");  
            exit(1);  
        }  
  
        printf("Request from %s:%d\n%s\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port), request);  
  
        sscanf(request, "%s %s %s", method, url, protocol);  
        if(strncmp(url, "http://", 7) == 0){  
            strcpy(url, url+7);  
        }  
        sscanf(url, "%[^/]/%s", hostname, path);  
  
        int port = 80;  
        char* portpos = strchr(hostname, ':');  
        if(portpos != NULL){  
            *portpos = '\0';  
            port = atoi(portpos+1);  
        }  
  
        host = gethostbyname(hostname);  
        if(host == NULL){  
            printf(" cannot resolve '%s'\n", hostname);  
            exit(1);  
        }  
  
        struct sockaddr_in serv_addr;  
        bzero(&serv_addr, sizeof(struct sockaddr_in));  
        serv_addr.sin_family = AF_INET;  
        serv_addr.sin_port = htons(port);  
        serv_addr.sin_addr = *((struct in_addr *)host->h_addr);  
  
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);  
        if(sockfd == -1){  
            perror("socket");  
            exit(1);  
        }  
  
        if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr_in)) == -1){  
            perror("connect");  
            exit(1);  
        }  
  
        sprintf(buffer, "%s /%s %s\r\nHost: %s\r\n", method, path, protocol, hostname);  
        for(int i=0; i<strlen(request); i++){  
            if(strncmp(&request[i], "\r\n", 2) == 0){  
                break;  
            }  
            if(strncmp(&request[i], "User-Agent:", 11) == 0){  
                continue;  
            }  
            if(strncmp(&request[i], "Connection:", 11) == 0){  
                sprintf(&buffer[strlen(buffer)], "Connection: close\r\n");  
                i += 11;  
            }  
            sprintf(&buffer[strlen(buffer)], "%c", request[i]);  
        }  
        sprintf(&buffer[strlen(buffer)], "\r\n");  
  
        printf("Client Request: \n%s\n", buffer);  
  
        if(send(sockfd, buffer, strlen(buffer), 0) == -1){  
            perror("send");  
            exit(1);  
        }  
  
        bzero(buffer, MAXLINE);  
        bzero(res, MAXLINE);  
        int n;  
        while((n = recv(sockfd, buffer, MAXLINE, 0)) > 0){  
            if(n == -1){  
                perror("recv");  
                exit(1);  
            }  
            strcat(res, buffer);  
        }  
  
        printf("Server Response: \n%s\n", res);  
  
        if(send(connfd, res, strlen(res), 0) == -1){  
            perror("send");  
            exit(1);  
        }  
  
        printf("Closing Connection...\n\n");  
        close(sockfd);  
        close(connfd);  
    }  
    return 0;  
}