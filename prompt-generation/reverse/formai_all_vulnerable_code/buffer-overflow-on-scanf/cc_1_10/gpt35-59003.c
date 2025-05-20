//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_MSG_LEN], username[MAX_MSG_LEN], password[MAX_MSG_LEN];
   
    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }
   
    // set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("pop3.server.com");
    servaddr.sin_port = htons(110);
   
    // connect to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }
   
    // receive server greeting
    recv(sockfd, buffer, MAX_MSG_LEN, 0);
    printf("%s\n", buffer);
   
    // login
    printf("Enter username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_MSG_LEN, 0);
    printf("%s", buffer);
   
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_MSG_LEN, 0);
    printf("%s", buffer);
   
    // list messages
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_MSG_LEN, 0);
    printf("%s", buffer);
   
    // retrieve message
    printf("Enter message number: ");
    int message_num;
    scanf("%d", &message_num);
    sprintf(buffer, "RETR %d\r\n", message_num);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_MSG_LEN, 0);
    printf("%s", buffer);
   
    // logout
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_MSG_LEN, 0);
    printf("%s", buffer);
   
    // close socket
    close(sockfd);
   
    return 0;
}