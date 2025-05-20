//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int portno = 80; // default HTTP port number

    if (argc < 2) {
        fprintf(stderr,"Please provide the URL of the website to connect to\n");
        exit(1);
    }

    // parse the URL to extract the host and path
    char *url = argv[1];
    char *host = strstr(url, "://");
    if (host == NULL) {
        host = url;
    } else {
        host += 3;
    }
    char *path = strchr(host, '/');
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0'; // terminate the host string
        path += 1;
    }

    // resolve the hostname to an IP address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"Error: could not resolve hostname '%s'\n", host);
        exit(1);
    }

    // initialize the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket\n");
        exit(1);
    }

    // set up the server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(portno);

    // connect to the server
    if (connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
        perror("Error: could not connect to server\n");
        exit(1);
    }

    // construct the HTTP request
    snprintf(buffer, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // send the HTTP request
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error: could not send HTTP request\n");
        exit(1);
    }

    // read the HTTP response
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int n = read(sockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("Error: could not read from server\n");
            exit(1);
        } else if (n == 0) {
            break;
        } else {
            printf("%s", buffer);
        }
    }

    // close the socket
    close(sockfd);

    return 0;
}