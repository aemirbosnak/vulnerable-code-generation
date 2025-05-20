//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

#define MAXDATASIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct sockaddr_in their_addr;
    struct timeval timeout;
    fd_set read_fds;
    char *username = "exampleuser";
    char *password = "examplepassword";
    
    if(argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(atoi(argv[2]));
    their_addr.sin_addr.s_addr = inet_addr(argv[1]);
    memset(their_addr.sin_zero, '\0', sizeof(their_addr.sin_zero));
    
    if(connect(sockfd, (struct sockaddr *)&their_addr, sizeof(their_addr)) == -1) {
        perror("connect");
        exit(1);
    }
    
    // Check if server is ready
    if(recv(sockfd, buf, MAXDATASIZE-1, 0) == -1) {
        perror("recv");
        exit(1);
    }
    if(strcmp(buf, "READY") != 0) {
        printf("Server is not ready for IMAP connection\n");
        exit(1);
    }
    
    // Send LOGIN command
    snprintf(buf, MAXDATASIZE-1, "LOGIN %s %s\r\n", username, password);
    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }
    if(recv(sockfd, buf, MAXDATASIZE-1, 0) == -1) {
        perror("recv");
        exit(1);
    }
    if(strncmp(buf, "OK", 2) != 0) {
        printf("Login failed\n");
        exit(1);
    }
    
    // Send SELECT command to select inbox folder
    snprintf(buf, MAXDATASIZE-1, "SELECT INBOX\r\n");
    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }
    if(recv(sockfd, buf, MAXDATASIZE-1, 0) == -1) {
        perror("recv");
        exit(1);
    }
    if(strncmp(buf, "* OK", 4) != 0) {
        printf("Failed to select inbox\n");
        exit(1);
    }
    
    // Send SEARCH command to search for all messages
    snprintf(buf, MAXDATASIZE-1, "SEARCH ALL\r\n");
    if(send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }
    
    // Wait for response
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    if(select(sockfd+1, &read_fds, NULL, NULL, &timeout) == -1) {
        perror("select");
        exit(1);
    }
    
    // Read response
    if(FD_ISSET(sockfd, &read_fds)) {
        if((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        buf[numbytes] = '\0';
        printf("Messages:\n%s\n", buf);
    } else {
        printf("Timeout waiting for messages\n");
    }
    
    close(sockfd);
    
    return 0;
}