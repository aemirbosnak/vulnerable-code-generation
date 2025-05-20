//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define SMTP_SERVER_PORT 25

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_SERVER_PORT);

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");
    printf("HELO %s\r\n", argv[1] );

    //Send HELO message to the server
    if( send(sock , "HELO\r\n" , strlen("HELO\r\n") , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);

    //Send MAILFROM command and address
    printf("MAIL FROM:<%s>\r\n",argv[2]);
    sprintf(message,"MAIL FROM:<%s>\r\n", argv[2]);
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);

    //Send RCPTTO command and address
    printf("RCPT TO:<%s>\r\n", argv[3]);
    sprintf(message,"RCPT TO:<%s>\r\n", argv[3]);
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);

    //Send DATA command
    if( send(sock , "DATA\r\n" , strlen("DATA\r\n") , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);

    //Send message content
    printf("Subject: %s\n", argv[4]);
    sprintf(message,"Subject: %s\r\n%s\r\n.\r\n", argv[4], argv[5]);
    if( send(sock , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //Receive a reply from the server
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);

    //Send QUIT command and close socket
    if( send(sock , "QUIT\r\n" , strlen("QUIT\r\n") , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    if( recv(sock , server_reply , 2000 , 0) < 0)
    {
        puts("recv failed");
    }
    puts(server_reply);
    close(sock);
    return 0;
}