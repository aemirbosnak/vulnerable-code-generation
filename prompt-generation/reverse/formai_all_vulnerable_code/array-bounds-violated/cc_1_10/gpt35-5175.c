//FormAI DATASET v1.0 Category: Networking ; Style: automated
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 

#define PORT 8080

int main() 
{ 
    int sockfd; 
    struct sockaddr_in servaddr, cliaddr; 

    // Creating socket file descriptor 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
    if (sockfd < 0) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 

    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 

    // Bind the socket with the server address 
    if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr))) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    int len, n; 
    char buffer[1024]; 

    len = sizeof(cliaddr);  // len is value/resuslt 
   
    // infinite loop for receiving datagrams 
    while (1) { 
        n = recvfrom(sockfd, (char*)buffer, 1024, MSG_WAITALL, (struct sockaddr*)&cliaddr, &len); 
        buffer[n] = '\0'; 
        printf("Client : %s\n", buffer); 
        sendto(sockfd, (const char*)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr*)&cliaddr, len); 
        printf("Message sent back to the client.\n"); 
    } 

    return 0; 
}