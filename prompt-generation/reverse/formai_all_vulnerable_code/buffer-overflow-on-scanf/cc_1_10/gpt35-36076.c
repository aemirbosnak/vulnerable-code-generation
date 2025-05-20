//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(){
    //initialize variables
    int sockfd, bytes_read;
    char buffer[1024], recv_buf[2048], *username, *password;
    struct sockaddr_in servaddr;

    //establish socket connection
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bzero(&servaddr, sizeof(servaddr));

    //server details
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);
    inet_pton(AF_INET, "mail.server.com", &servaddr.sin_addr);

    //connect to server
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        perror("Connection Failed.");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));   //clear buffers
    memset(recv_buf, 0, sizeof(recv_buf));

    printf("Enter your username: \n");
    scanf("%s", username);
    printf("Enter your password: \n");
    scanf("%s", password);

    //authenticate user
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));

    //retrieve emails
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    bytes_read = read(sockfd, recv_buf, 1024);

    //process emails
    //.....

    //close connection
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    memset(buffer, 0, sizeof(buffer));
    close(sockfd);

    return 0;
}