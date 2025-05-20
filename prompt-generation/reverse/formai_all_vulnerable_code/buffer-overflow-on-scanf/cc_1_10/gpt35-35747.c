//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    int portno;
    char buffer[200];
    char *client_name;
    
    if(argc< 3) 
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    
    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
    {
        perror("ERROR connecting");
        exit(1);
    }
    
    printf("Enter your name: ");
    scanf("%s",buffer);
    client_name = buffer;
    
     do
     {
        printf("Enter message: ");
        bzero(buffer,200);
        fgets(buffer,200,stdin);
      
        write(sockfd,buffer,strlen(buffer));
        bzero(buffer,200);
        read(sockfd,buffer,199);
        printf("%s: %s\n",client_name,buffer);
    }while(strcmp(buffer,"Exit"));
    
    close(sockfd);
    return 0;
}