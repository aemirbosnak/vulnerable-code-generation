//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

#define MAX 10
#define PORT 8080
#define SA struct sockaddr

int g_socket;
sem_t mutex;

void *thread_routine(void *arg)
{
    char buffer[1024];
    int bytes_received;

    while(1)
    {
        sem_wait(&mutex);
        bytes_received = recv(g_socket,buffer,1024,0);
        if(bytes_received <= 0)
        {
            if(errno == ECONNRESET)
            {
                printf("Connection reset by peer\n");
            }
            else if(errno == ECONNABORTED)
            {
                printf("Connection aborted\n");
            }
            else
            {
                printf("Error in recv: %s\n",strerror(errno));
            }
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n",buffer);
        sem_post(&mutex);
    }

    return NULL;
}

int main()
{
    int opt = 1;
    int addrlen;
    struct sockaddr_in server_addr;
    pthread_t thread_id;

    g_socket = socket(AF_INET,SOCK_STREAM,0);
    if(g_socket == -1)
    {
        printf("Error in socket creation\n");
        exit(1);
    }

    setsockopt(g_socket,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(g_socket,(SA*)&server_addr,sizeof(server_addr)) == -1)
    {
        printf("Error in bind\n");
        exit(1);
    }

    if(listen(g_socket,MAX) == -1)
    {
        printf("Error in listen\n");
        exit(1);
    }

    printf("Server started on port %d\n",PORT);

    while(1)
    {
        addrlen = sizeof(server_addr);
        if((g_socket = accept(g_socket,(SA*)&server_addr,&addrlen)) == -1)
        {
            printf("Error in accept\n");
            exit(1);
        }

        pthread_create(&thread_id,NULL,thread_routine,NULL);
    }

    return 0;
}