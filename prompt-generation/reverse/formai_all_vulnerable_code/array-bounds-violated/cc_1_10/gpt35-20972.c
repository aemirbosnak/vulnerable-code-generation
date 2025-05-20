//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd = 0, n = 0;
    char recv_buffer[BUFFER_SIZE], send_buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    if(argc != 3) {
        printf("Usage: imap-client <IP address> <port number>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Error: Invalid address or address not supported");
        return 1;
    }

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send login credentials
    sprintf(send_buffer, "TAG1 LOGIN %s %s\n", "username", "password");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    
    // Receive server response
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = 0;
    printf("%s\n", recv_buffer);
    
    // Send select mailbox command
    sprintf(send_buffer, "TAG2 SELECT INBOX\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    
    // Receive server response
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    recv_buffer[n] = 0;
    printf("%s\n", recv_buffer);

    // Close the connection
    close(sockfd);
    return 0;
}