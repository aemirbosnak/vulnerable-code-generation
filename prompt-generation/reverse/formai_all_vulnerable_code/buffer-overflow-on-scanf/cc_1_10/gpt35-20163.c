//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc,char** argv) {

    if(argc != 3) {
        printf("Usage: %s <IP Address> <Port Number>\n",argv[0]);
        return -1;
    }
    struct sockaddr_in clientAddr;
    int sockfd,len;
    char buffer[MAXSIZE];

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        printf("Failed to create socket\n");
        return -1;
    }
    
    bzero(&clientAddr,sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(atoi(argv[2]));
    clientAddr.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sockfd,(struct sockaddr*)&clientAddr,sizeof(clientAddr)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }

    printf("Connection established successfully\n");
    printf("Enter the name of file you want to download : ");
    scanf("%s",buffer);
    write(sockfd,buffer,strlen(buffer));
    bzero(buffer,sizeof(buffer));

    if(read(sockfd,buffer,sizeof(buffer))<0){
        printf("Error reading from socket\n");
        return -1;
    }

    if(strcmp(buffer,"File not found") == 0) {
        printf("File not found on the server\n");
        return -1;
    }
    FILE *fp=fopen(buffer,"wb");
    bzero(buffer,sizeof(buffer));
    while((len=read(sockfd,buffer,sizeof(buffer)))>0) {
        fwrite(buffer,1,len,fp);
        bzero(buffer,sizeof(buffer));
    }

    fclose(fp);
    printf("Download Completed\n");
    close(sockfd);
    return 0;
}