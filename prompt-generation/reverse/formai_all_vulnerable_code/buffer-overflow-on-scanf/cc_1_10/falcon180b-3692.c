//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<errno.h>

#define PORT 8080
#define MAX 1024

void die(char *s)
{
    perror(s);
    exit(1);
}

int create_socket()
{
    int sockfd;
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
        die("socket failed");
    return sockfd;
}

struct sockaddr_in create_addr(char *ip,int port)
{
    struct sockaddr_in serv_addr;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    inet_pton(AF_INET,ip,&serv_addr.sin_addr);
    serv_addr.sin_port=htons(port);
    return serv_addr;
}

int connect_server(int sockfd,struct sockaddr_in serv_addr)
{
    if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
        die("connect failed");
    return sockfd;
}

void read_line(int fd,char *line,int max)
{
    char *p=line;
    int n=0;
    while(n<max-1)
    {
        if((read(fd,p,1))==-1)
            die("read failed");
        if(*p=='\n')
        {
            *p='\0';
            break;
        }
        p++;
        n++;
    }
}

int main()
{
    int sockfd,newsockfd;
    struct sockaddr_in serv_addr,cli_addr;
    char buffer[MAX];
    char ip[MAX];
    int port=PORT;
    printf("Enter IP Address:");
    scanf("%s",ip);
    printf("Enter Port Number:");
    scanf("%d",&port);
    if((sockfd=create_socket())==-1)
        die("socket failed");
    serv_addr=create_addr(ip,port);
    if((connect_server(sockfd,serv_addr))==-1)
        die("connect failed");
    printf("Connected to Server\n");
    while(1)
    {
        bzero(buffer,MAX);
        read_line(sockfd,buffer,MAX);
        printf("%s",buffer);
        bzero(buffer,MAX);
        if(strcmp(buffer,"bye")==0)
        {
            close(sockfd);
            exit(0);
        }
    }
    return 0;
}