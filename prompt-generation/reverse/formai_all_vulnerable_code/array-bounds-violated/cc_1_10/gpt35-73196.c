//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char** argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF_SIZE];
    
    if(argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);
    
    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    // Send HTTP request
    char* request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char req_buf[MAX_BUF_SIZE];
    snprintf(req_buf, MAX_BUF_SIZE, request, argv[1]);
    n = send(sockfd, req_buf, strlen(req_buf), 0);
    if(n < 0) {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }
    
    // Receive HTTP response
    char res_buf[MAX_BUF_SIZE];
    while((n = recv(sockfd, res_buf, MAX_BUF_SIZE-1, 0)) > 0) {
        res_buf[n] = '\0';
        printf("%s", res_buf);
    }
    if(n < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    
    close(sockfd);
    return 0;
}