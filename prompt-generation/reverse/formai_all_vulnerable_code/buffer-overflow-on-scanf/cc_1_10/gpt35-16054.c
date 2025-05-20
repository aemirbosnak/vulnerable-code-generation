//FormAI DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#define PORT 8080 

int main() 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char buffer[1024] = {0}; 

    // Creating socket file descriptor 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    printf("Welcome to the Chatroom!\n\n");
    printf("Enter your name: ");
    scanf("%s", buffer);

    printf("\n%s has entered the chat.\n", buffer);

    while(1) 
    {   
        char message[1024] = {0};
        
        printf("%s: ", buffer);
        scanf("%s", message);
        
        send(sock, message, strlen(message), 0); 

        if(strcmp(message, "exit") == 0) 
        {   
            printf("\n%s has left the chat.\n", buffer);
            break;
        }

        valread = read(sock, buffer, 1024);
        printf("Server: %s\n", buffer);
    }
    close(sock);
    return 0; 
}