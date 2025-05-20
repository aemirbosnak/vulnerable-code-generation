//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<ctype.h>

#define BUFSIZE 8192

int main(int argc, char *argv[]) {
    char *url = argv[1];                    // Taking URL from command-line argument
    char *http = "http";                    // HTTP is string to be concatenated
    char *domain;                           // Domain name will be extracted from URL
    char *page;                             // Path will be extracted from URL
    struct hostent *server;                 // Hostent struct is used to store IP address of the server
    struct sockaddr_in serv_addr;           // Struct socket will store the details of the remote server
    int sockfd, bytes, sent, received, total, filesize, i, j=0;

    /* Extracting domain name and path from the URL */
    if(strlen(url) > 7 && strncmp(http, url, strlen(http)) == 0)
        url += 7;                           // Removing "http://"
    domain = strchr(url, '/');
    if(domain) {
        page = domain + 1;
        *domain = '0';
        domain = url;
    } else {
        page = "";
        domain = url;
    }

    /* Creating socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    /* Host Lookup */
    server = gethostbyname(domain);
    if(server == NULL) {
        perror("Error in gethostbyname");
        return 1;
    }

    /* Setting up socket */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = *(long*)(server->h_addr);

    /* Connect to remote server */
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error in connect");
        return 1;
    }

    /* Sending request to the server */
    char request[BUFSIZE];
    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", page, domain);
    total = strlen(request);
    sent = 0;
    do {
        bytes = write(sockfd, request+sent, total-sent);
        if(bytes < 0) {
            perror("Error in sending request");
            return 1;
        }
        if(bytes == 0) break;
        sent += bytes;
    } while(sent < total);

    /* Receiving response from server */
    char response[BUFSIZE];
    memset(response, 0, sizeof(response));
    total = sizeof(response)-1;
    received = 0;
    do {
        bytes = read(sockfd, response+received, total-received);
        if(bytes < 0) {
            perror("Error in receiving response");
            return 1;
        }
        if(bytes == 0) break;
        received += bytes;
    } while(received < total);

    /* Closing the socket */
    close(sockfd);

    /* Printing the response */
    printf("%s\n", response);
    
    return 0;
}