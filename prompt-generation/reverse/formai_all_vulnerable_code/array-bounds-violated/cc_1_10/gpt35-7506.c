//FormAI DATASET v1.0 Category: Socket programming ; Style: real-life
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080  
#define MAXLINE 1024  

int main()  
{  
    int sockfd;  
    struct sockaddr_in servaddr;  
    char buffer[MAXLINE];  
    char *hello = "Hello from client";  
    int len, n;  
    
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM,0)) < 0) {  
        printf("\n Socket creation error!\n");  
        return -1;  
    } 
    
    memset(&servaddr,0,sizeof(servaddr));  
    
    // Setting up socket address structure
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  
    servaddr.sin_port = htons(PORT);  
    
    // Attempting connection
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {  
        printf("Connection failed!\n");  
        return -1;  
    }  
    
    printf("Successfully connected to the server!\n");  
    
    // Sending message to the server
    send(sockfd, hello, strlen(hello), 0);  
    printf("Message sent to the server!\n");  
    
    // Receiving server's reply
    n = recv(sockfd, buffer, MAXLINE, 0);  
    buffer[n] = '\0';  
    
    printf("Server's reply: %s\n\n", buffer);  
    
    // Closing the socket
    close(sockfd);  
    printf("Socket closed!\n");  
    
    return 0;  
}