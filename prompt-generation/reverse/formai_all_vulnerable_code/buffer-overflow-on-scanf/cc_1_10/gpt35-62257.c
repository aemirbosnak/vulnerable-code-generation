//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define READ_BUFF_SIZE 4096

void handleResponse(char *response)
{
    printf("%s",response);
}

int main(int argc, char* argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    char server_address[100];
    int server_port;
    char user_name[100];
    char password[100];
    char command[500];
    
    printf("Enter the server address: ");
    scanf("%s",server_address);
    
    printf("Enter the server port: ");
    scanf("%d",&server_port);
    
    printf("Enter the username: ");
    scanf("%s",user_name);
    
    printf("Enter the password: ");
    scanf("%s",password);
    
    int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    
    if(sockfd<0)
    {
        printf("Unable to create socket\n");
        return 0;
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_address);
    
    if(connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
    {
        printf("Unable to connect to server\n");
        return 0;
    }
    
    char read_buf[READ_BUFF_SIZE];
    memset(read_buf,0,READ_BUFF_SIZE);
    
    if(read(sockfd,read_buf,READ_BUFF_SIZE)<0)
    {
        printf("Error while reading from server\n");
        return 0;
    }
    
    handleResponse(read_buf);
    
    sprintf(command,"USER %s\r\n",user_name);
    if(write(sockfd,command,strlen(command))<0)
    {
        printf("Error while writing command to server\n");
        return 0;
    }
    
    memset(read_buf,0,READ_BUFF_SIZE);
    if(read(sockfd,read_buf,READ_BUFF_SIZE)<0)
    {
        printf("Error while reading from server\n");
        return 0;
    }
    
    handleResponse(read_buf);
    
    sprintf(command,"PASS %s\r\n",password);
    if(write(sockfd,command,strlen(command))<0)
    {
        printf("Error while writing command to server\n");
        return 0;
    }
    
    memset(read_buf,0,READ_BUFF_SIZE);
    if(read(sockfd,read_buf,READ_BUFF_SIZE)<0)
    {
        printf("Error while reading from server\n");
        return 0;
    }
    
    handleResponse(read_buf);
    
    sprintf(command,"LIST\r\n");
    if(write(sockfd,command,strlen(command))<0)
    {
        printf("Error while writing command to server\n");
        return 0;
    }
    
    memset(read_buf,0,READ_BUFF_SIZE);
    if(read(sockfd,read_buf,READ_BUFF_SIZE)<0)
    {
        printf("Error while reading from server\n");
        return 0;
    }
    
    handleResponse(read_buf);
    
    sprintf(command,"QUIT\r\n");
    if(write(sockfd,command,strlen(command))<0)
    {
        printf("Error while writing command to server\n");
        return 0;
    }
    
    memset(read_buf,0,READ_BUFF_SIZE);
    if(read(sockfd,read_buf,READ_BUFF_SIZE)<0)
    {
        printf("Error while reading from server\n");
        return 0;
    }
    
    handleResponse(read_buf);
    
    close(sockfd);
    
    return 0;
}