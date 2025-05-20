//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#define MAXSIZE 1024

int main(int argc , char *argv[]){
    int sockfd, bytes_received;
    struct sockaddr_in servaddr;
    char recv_buff[MAXSIZE], message[MAXSIZE];
    char username[MAXSIZE], password[MAXSIZE], email[MAXSIZE];
    
    if (argc < 3) {
       printf("usage: ./pop3client <IP address> <port number>\n");
       exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // initializing server address to connect to
    bzero(&servaddr,sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Connect");
        exit(1);
    }
    printf("Connection established.\n");

    // login to server
    printf("Enter username: ");
    fgets(username, MAXSIZE, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Enter password: ");
    fgets(password, MAXSIZE, stdin);
    password[strcspn(password, "\n")] = 0;
    sprintf(message, "USER %s\r\n", username);
    send(sockfd, message, strlen(message),0);
    bzero(recv_buff,MAXSIZE);
    bytes_received = recv(sockfd, recv_buff, MAXSIZE, 0);
    recv_buff[bytes_received] = '\0';
    printf("%s", recv_buff);
    sprintf(message, "PASS %s\r\n", password);
    send(sockfd, message, strlen(message),0);
    bzero(recv_buff,MAXSIZE);
    bytes_received = recv(sockfd, recv_buff, MAXSIZE, 0);
    recv_buff[bytes_received] = '\0';
    printf("%s", recv_buff);

    while(1){
        printf("Enter command: ");
        fgets(message, MAXSIZE, stdin);
        message[strcspn(message, "\n")] = 0;
        send(sockfd, message, strlen(message),0);
        bzero(recv_buff,MAXSIZE);
        bytes_received = recv(sockfd, recv_buff, MAXSIZE, 0);
        recv_buff[bytes_received] = '\0';

        if(strstr(message,"RETR") != NULL)
        {
            printf("%s",recv_buff);
            bzero(recv_buff,MAXSIZE);
            bytes_received = recv(sockfd, recv_buff, MAXSIZE, 0);
            recv_buff[bytes_received] = '\0';
            printf("%s", recv_buff);
            bzero(recv_buff,MAXSIZE);
            bytes_received = recv(sockfd, recv_buff, MAXSIZE, 0);
            recv_buff[bytes_received] = '\0';
            printf("%s", recv_buff);
        }

        if(strstr(recv_buff,"QUIT") != NULL)
            break;

        printf("%s\n", recv_buff);
    }

    close(sockfd);

    return 0;
}