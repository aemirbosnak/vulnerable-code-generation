//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/socket.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define PORT "7"

struct hostent *host;

int thread_create(void *arg);

int main(int argc, char *argv[])
{
    int i,j,sock[MAX],res[MAX],num;
    char *ip[MAX];
    pthread_t thread_id[MAX];

    printf("Enter Number of IP's : ");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        printf("Enter IP %d : ",i+1);
        scanf("%s",ip[i]);
    }

    for(i=0;i<num;i++)
    {
        res[i] = gethostbyname(ip[i]);

        if(res[i] == NULL)
        {
            printf("IP not found : %s\n",ip[i]);
            exit(0);
        }

        host = res[i];

        for(j=0;j<host->h_length;j++)
        {
            sock[i] = socket(AF_INET,SOCK_STREAM,0);

            if(sock[i] < 0)
            {
                printf("Socket Creation Failed\n");
                exit(0);
            }
        }
    }

    for(i=0;i<num;i++)
    {
        pthread_create(&thread_id[i],NULL,thread_create,(void *)&sock[i]);
    }

    for(i=0;i<num;i++)
    {
        pthread_join(thread_id[i],NULL);
    }

    return 0;
}

int thread_create(void *arg)
{
    int sock = *(int *)arg;

    struct sockaddr_in server;
    struct timeval timeout;

    memset(&server,0,sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET,inet_ntoa(*(struct in_addr *)host->h_addr),&server.sin_addr);

    setsockopt(sock,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(timeout));

    if(connect(sock,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("Connect Failed\n");
        exit(0);
    }

    close(sock);
}