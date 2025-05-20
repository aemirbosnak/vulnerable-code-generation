//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024], message[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Error creating socket\n");
        return -1;
    }

    printf("SMTP Client started!!!\n");

    printf("Enter the Port Number: ");
    scanf("%d", &portno);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
    {
        printf("Connection Failed!!\n");
        return -1;
    }

    printf("Connected Successfully!!!\n");

    // recv greeting message from server
    printf("\nWaiting for server's greeting message ...\n");
    bzero(buffer,1024);
    n = recv(sockfd, buffer, 1024, 0);
    if(n>0)
    {
        printf("Server: %s", buffer);
    }

    // send HELO message to server
    printf("\nSending HELO message to the server ...\n");
    bzero(message,1024);
    sprintf(message, "HELO localhost\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if(n>0)
    {
        printf("Client: %s", message);
    }

    // recv response for HELO message from server
    printf("\nWaiting for server's response for HELO message ...\n");
    bzero(buffer,1024);
    n = recv(sockfd, buffer, 1024, 0);
    if(n>0)
    {
        printf("Server: %s", buffer);
    }

    // send MAIL FROM message to server
    printf("\nSending MAIL FROM message to the server ...\n");
    bzero(message,1024);
    sprintf(message, "MAIL FROM: <xyz@gmail.com>\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if(n>0)
    {
        printf("Client: %s", message);
    }

    // recv response for MAIL FROM message from server
    printf("\nWaiting for server's response for MAIL FROM message ...\n");
    bzero(buffer,1024);
    n = recv(sockfd, buffer, 1024, 0);
    if(n>0)
    {
        printf("Server: %s", buffer);
    }

    // send RCPT TO message to server
    printf("\nSending RCPT TO message to the server ...\n");
    bzero(message,1024);
    sprintf(message, "RCPT TO: <abc@gmail.com>\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if(n>0)
    {
        printf("Client: %s", message);
    }

    // recv response for RCPT TO message from server
    printf("\nWaiting for server's response for RCPT TO message ...\n");
    bzero(buffer,1024);
    n = recv(sockfd, buffer, 1024, 0);
    if(n>0)
    {
        printf("Server: %s", buffer);
    }

    // send DATA message to server
    printf("\nSending DATA message to the server ...\n");
    bzero(message,1024);
    sprintf(message, "DATA\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if(n>0)
    {
        printf("Client: %s", message);
    }

    // recv response for DATA message from server
    printf("\nWaiting for server's response for DATA message ...\n");
    bzero(buffer,1024);
    n = recv(sockfd, buffer, 1024, 0);
    if(n>0)
    {
        printf("Server: %s", buffer);
    }

    // send email content to server
    printf("\nEnter the email content (press '.' and Enter key to send):\n");
    while(1)
    {
        bzero(buffer, 1024);
        fgets(buffer, 1024, stdin);
        if(buffer[0] == '.' && buffer[1] == '\n')
            break;
        send(sockfd, buffer, strlen(buffer), 0);
    }

    // send QUIT message to server
    printf("\nSending QUIT message to the server ...\n");
    bzero(message, 1024);
    sprintf(message, "QUIT\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if(n>0)
    {
        printf("Client: %s", message);
    }

    // recv response for QUIT message from server
    printf("\nWaiting for server's response for QUIT message ...\n");
    bzero(buffer,1024);
    n = recv(sockfd, buffer, 1024, 0);
    if(n>0)
    {
        printf("Server: %s", buffer);
    }

    printf("\nDisconnected from SMTP Server!!!\n");

    close(sockfd);

    return 0;
}