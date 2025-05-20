//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_SIZE 2048

int build_http_request(char *url, char *request) {
    char *hostname, *path, *temp;
    int i, port = 80; // default HTTP port

    // parse the URL and extract hostname, path and port
    hostname = strstr(url, "://");
    if (hostname == NULL) {
        hostname = url;
    } else {
        hostname += 3;
    }
    temp = strchr(hostname, ':');
    if (temp != NULL) {
        *temp++ = '\0';
        port = atoi(temp);
    }
    path = strchr(hostname, '/');
    if (path != NULL) {
        *path++ = '\0';
    } else {
        path = "/";
    }

    // prepare the HTTP request
    sprintf(request, "GET %s HTTP/1.1\r\n", path);
    sprintf(request + strlen(request), "Host: %s\r\n", hostname);
    sprintf(request + strlen(request), "Connection: close\r\n");
    sprintf(request + strlen(request), "\r\n");
    
    return port;
}

int main(int argc, char *argv[]) {
    int sockfd, n, port;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char url[MAX_SIZE], request[MAX_SIZE], response[MAX_SIZE];

    // get the URL from user input
    printf("Enter the URL to retrieve: ");
    fgets(url, MAX_SIZE, stdin);
    url[strlen(url)-1] = '\0';

    // build the HTTP request
    port = build_http_request(url, request);

    // resolve hostname to IP address
    if ((host = gethostbyname(url)) == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", url);
        exit(1);
    }

    // create TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // connect to server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // send HTTP request to server
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // receive HTTP response from server
    memset(response, 0, MAX_SIZE);
    n = read(sockfd, response, MAX_SIZE-1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    // print HTTP response to console
    printf("%s", response);

    close(sockfd);

    return 0;
}