//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];
    char *hostname = url;
    char *path = "/";
    int port = 80;

    struct hostent *he;
    struct in_addr **addr_list;

    if(strncmp("http://", url, 7) == 0){
        hostname = url + 7;
    }

    char *port_str = strchr(hostname, ':');
    char *path_str = strchr(hostname, '/');

    if(port_str){
        *port_str = '\0';
        port_str++;
        port = atoi(port_str);
    }

    if(path_str){
        *path_str = '\0';
        path = path_str;
    }

    if((he = gethostbyname(hostname)) == NULL){
        printf("Failed to resolve hostname: %s\n", hostname);
        exit(1);
    }

    printf("Resolving %s...\n", hostname);
    printf("Connecting to %s:%d...\n", inet_ntoa(*(struct in_addr*)he->h_addr_list[0]), port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1){
        printf("Failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*)he->h_addr_list[0]);
    bzero(&(server_addr.sin_zero), 8);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1){
        printf("Failed to connect\n");
        exit(1);
    }

    printf("Connected!\n");

    char *request_template =
        "GET %s HTTP/1.0\r\n"
        "Host: %s:%d\r\n"
        "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:127.0) Gecko/20100101 Firefox/127.0\r\n"
        "Accept: */*\r\n"
        "Connection: close\r\n\r\n";

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, request_template, path, hostname, port);

    if(send(sockfd, request, strlen(request), 0) == -1){
        printf("Failed to send request\n");
        exit(1);
    }

    printf("Request sent!\n");

    char response[BUFFER_SIZE];
    int received = 0;
    int bytes_received;

    while((bytes_received = recv(sockfd, response + received, BUFFER_SIZE - received, 0)) > 0){
        received += bytes_received;

        if(received >= BUFFER_SIZE){
            printf("Response too large\n");
            exit(1);
        }
    }

    if(bytes_received == -1){
        printf("Failed to receive response\n");
        exit(1);
    }

    printf("Response received:\n%s\n", response);

    close(sockfd);

    return 0;
}