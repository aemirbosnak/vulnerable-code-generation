//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

int send_http_request(char* url) {
    int sockfd, portno, bytes_read;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // get server address information
    if ((server = gethostbyname(url)) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    // fill in server_addr struct with the address information
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80); // default port for HTTP

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // send the HTTP GET request
    if (send(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive the response
    bzero(buffer, 1024);
    bytes_read = recv(sockfd, buffer, 1024, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // print the response code
    printf("Response code: %d\n", bytes_read);

    // close the socket
    close(sockfd);

    return 0;
}

int main() {
    char url[128];

    // get the URL from the user
    printf("Enter the URL: ");
    scanf("%s", url);

    // send the HTTP GET request
    send_http_request(url);

    return 0;
}