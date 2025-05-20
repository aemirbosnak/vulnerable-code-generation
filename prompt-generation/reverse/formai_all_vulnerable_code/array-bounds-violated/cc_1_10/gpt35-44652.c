//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define BUFSIZE 1024

int main(int argc,char* argv[]) {

    int sockfd,connfd;
    struct sockaddr_in my_addr;
    char recvbuffer[BUFSIZE],sendbuffer[BUFSIZE];
    memset(&my_addr,0,sizeof(my_addr));
    my_addr.sin_family = AF_INET;  
    my_addr.sin_addr.s_addr = INADDR_ANY;  
    my_addr.sin_port = htons(8080);

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        perror("socket creation failed\n");
        exit(0);
    }

    if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(my_addr))!=0){
        perror("socket binding failed");
        exit(0);
    }

    if(listen(sockfd,5)!=0){
        perror("listen failed");
        exit(0);
    }

    printf("Welcome to the server\n");

    while(1){
        connfd = accept(sockfd,(struct sockaddr*)NULL,NULL);
        if(connfd<0){
            perror("connection failed");
            exit(0);
        }
        printf("Connected with the client\n");

        while(1){

            printf("\nMessage from the client: ");
            int n=recv(connfd,recvbuffer,BUFSIZE,0);
            recvbuffer[n]='\0';
            printf("%s\n",recvbuffer);

            printf("\nEnter the message to be sent: ");
            fgets(sendbuffer,sizeof(sendbuffer),stdin);
            send(connfd,sendbuffer,strlen(sendbuffer),0);

            if(strcmp(sendbuffer,"exit\n")==0){
                printf("Disconnected with the client\n");
                break;
            }
        }

        close(connfd);
    }

    return 0;
}