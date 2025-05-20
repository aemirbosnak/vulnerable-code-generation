//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: expert-level
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define PORT 8888 
#define MAXLINE 1024 

int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    struct sockaddr_in servaddr, cliaddr; 
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
        perror("socket creation failed"); 
        return 0; 
    } 
    
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
    
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
    
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) { 
        perror("bind failed"); 
        return 0; 
    } 
    
    int len, n; 
    len = sizeof(cliaddr); 
    
    while(1) { 
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len); 
        buffer[n] = '\0'; 
        printf("Client : %s\n", buffer); 
        if(strcmp(buffer, "exit") == 0) 
            break; 
        printf("Server : "); 
        memset(buffer, 0, sizeof(buffer)); 
        fgets(buffer, MAXLINE, stdin); 
        sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len); 
    } 
    
    close(sockfd); 
    
    return 0; 
}