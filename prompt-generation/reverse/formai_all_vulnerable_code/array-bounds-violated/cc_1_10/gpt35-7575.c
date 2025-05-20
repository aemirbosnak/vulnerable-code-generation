//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_REQUEST_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    // check if sufficient arguments have been provided
    if (argc < 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    int portno = atoi(argv[2]);

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR opening socket");
    }

    // define server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    
    // convert address from text to binary form
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0){
        error("Address not supported.");
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        error("Connection failed.");
    }
    
    // send http request
    char request[MAX_REQUEST_SIZE] = {0};
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    if(send(sockfd, request, strlen(request), 0) < 0){
        error("Failed to send request.");
    }

    // receive and print server response
    char response[MAX_REQUEST_SIZE] = {0};
    int nread;
    while ((nread = recv(sockfd, response, sizeof(response)-1, 0)) > 0) {
        response[nread] = '\0';
        printf("%s", response);
    }

    // clean up
    close(sockfd);
    return 0;
}