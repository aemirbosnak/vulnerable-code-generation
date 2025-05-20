//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_RESPONSE_SIZE 102400  // max size of HTTP response

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // parse url into hostname and path
    char *url = argv[1];
    char *http = strstr(url, "http://");
    if(http != url){
        printf("Error: URL must start with 'http://'\n");
        return 1;
    }
    char *hostname = http + 7;
    char *path = strchr(hostname, '/');
    if(path == NULL){
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    // resolve hostname to IP address
    struct hostent *he = gethostbyname(hostname);
    if(he == NULL){
        herror("gethostbyname");
        return 1;
    }
    char *ip = inet_ntoa(*((struct in_addr*)he->h_addr_list[0]));

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("socket");
        return 1;
    }

    // connect to server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if(inet_pton(AF_INET, ip, &server_address.sin_addr) != 1){
        perror("inet_pton");
        return 1;
    }
    if(connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1){
        perror("connect");
        return 1;
    }

    // send HTTP request
    char request[1024];
    snprintf(request, sizeof(request), "GET /%s HTTP/1.1\r\n"
                                         "Host: %s\r\n"
                                         "Connection: close\r\n"
                                         "\r\n",
             path, hostname);
    if(send(sockfd, request, strlen(request), 0) == -1){
        perror("send");
        return 1;
    }

    // receive HTTP response
    char response[MAX_RESPONSE_SIZE];
    int received = 0;
    while(received < MAX_RESPONSE_SIZE-1){
        int bytes = recv(sockfd, response+received, MAX_RESPONSE_SIZE-received-1, 0);
        if(bytes == -1){
            perror("recv");
            return 1;
        } else if(bytes == 0){
            break;
        }
        received += bytes;
    }
    response[received] = '\0';

    // print HTTP response
    printf("%s\n", response);

    // close socket
    close(sockfd);

    return 0;
}