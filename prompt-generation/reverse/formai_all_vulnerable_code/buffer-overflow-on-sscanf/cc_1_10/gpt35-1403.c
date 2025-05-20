//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

#define MAXSIZE 4096

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc,char* argv[])
{
    char username[MAXSIZE];
    char pwd[MAXSIZE];
    char buf[MAXSIZE];
    int sock;
    struct sockaddr_in pop3server;
    int port=110;
    char message[100];
    char server_reply[MAXSIZE];

    //Creating the socket
    sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock==-1)
    {
        error("Failed to create socket");
    }
    puts("Socket created");

    //Initialising the server socket address
    pop3server.sin_addr.s_addr=inet_addr("127.0.0.1");
    pop3server.sin_family=AF_INET;
    pop3server.sin_port=htons(port);

    //Connecting to the server
    if(connect(sock,(struct sockaddr*)&pop3server,sizeof(pop3server))<0)
    {
        error("Connect Failed");
        return 1;
    }

    puts("Connected to POP Server");

    //Receiving server's welcome message
    if(recv(sock,server_reply,MAXSIZE,0)<0)
    {
        error("Recv failed");
    }

    puts(server_reply);

    //Sending username to server
    printf("Enter username: ");
    fgets(username,MAXSIZE,stdin);
    sprintf(message,"USER %s",username);
    if(send(sock,message,strlen(message),0)<0)
    {
        error("Send failed");
    }

    //Receiving response from server
    if(recv(sock,server_reply,MAXSIZE,0)<0)
    {
        error("Recv failed");
    }
    puts(server_reply);

    //Sending password to server
    printf("Enter password: ");
    fgets(pwd,MAXSIZE,stdin);
    sprintf(message,"PASS %s",pwd);
    if(send(sock,message,strlen(message),0)<0)
    {
        error("Send failed");
    }

    //Receiving response from server
    if(recv(sock,server_reply,MAXSIZE,0)<0)
    {
        error("Recv failed");
    }
    puts(server_reply);

    //Sending the command to list all the messages
    if(send(sock,"LIST\r\n",strlen("LIST\r\n"),0)<0)
    {
        error("Send failed");
    }

    //Receiving response from server
    if(recv(sock,server_reply,MAXSIZE,0)<0)
    {
        error("Recv failed");
    }
    puts(server_reply);

    //Parsing the server response to get the number of messages
    int msgcount;
    char* ptr=strstr(server_reply,".");
    sscanf(ptr+1,"%d",&msgcount);

    //Reading the messages one by one
    int i;
    for(i=1;i<=msgcount;++i)
    {
        sprintf(message,"RETR %d\r\n",i);
        if(send(sock,message,strlen(message),0)<0)
        {
            error("Send failed");
        }

        //Reading the message
        while(recv(sock,buf,MAXSIZE,0)>0)
        {
            printf("%s",buf);
            memset(buf,0,MAXSIZE);
        }
        printf("\n");
    }

    //Closing the socket
    close(sock);
    return 0;
}