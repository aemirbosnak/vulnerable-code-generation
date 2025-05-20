//Falcon-180B DATASET v1.0 Category: Email Client ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdbool.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

#define MAX 1000
#define PORT 8080
#define SERVER "localhost"

int sockfd;
struct sockaddr_in serv_addr;
char buffer[MAX];
char username[50],password[50];
char message[MAX];
int n;

void *thread(void *ptr)
{
    char *message_copy = (char *)ptr;
    send(sockfd,message_copy,strlen(message_copy),0);
}

int main()
{
    char hostname[100];
    char *ptr;
    FILE *fp;
    char ch;
    int i=0;

    gethostname(hostname,100);
    strcat(hostname,".txt");

    fp = fopen(hostname,"r");

    if(fp==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
        {
            username[i]='\0';
            i=0;
        }
        else
        {
            username[i++]=ch;
        }
    }

    fclose(fp);

    fp = fopen(hostname,"r");

    if(fp==NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
        {
            password[i]='\0';
            i=0;
        }
        else
        {
            password[i++]=ch;
        }
    }

    fclose(fp);

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd<0)
    {
        printf("Socket creation failed\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(PORT);

    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
    {
        printf("Connection failed\n");
        exit(0);
    }

    pthread_t thread_id;
    pthread_create(&thread_id,NULL,thread,(void *)message);

    while(1)
    {
        bzero(buffer,sizeof(buffer));
        n = read(sockfd,buffer,sizeof(buffer));

        if(n<0)
        {
            printf("Reading from socket failed\n");
            exit(0);
        }

        buffer[n] = '\0';
        printf("%s\n",buffer);

        if(strcmp(buffer,"Login successful")==0)
        {
            break;
        }
    }

    close(sockfd);

    return 0;
}