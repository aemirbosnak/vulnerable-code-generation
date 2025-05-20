//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    int sock, n;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];
    
    // Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    
    // Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
    
    // Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    
    puts("Connected to server");
    
    // Keep sending and receiving messages
    while(1)
    {
        // Send message to the server
        printf("Enter message : ");
        scanf("%s" , message);
        if( send(sock , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
        
        // Receive response from server
        if( (n = recv(sock , server_reply , 2000 , 0)) < 0)
        {
            puts("recv failed");
            break;
        }
        
        server_reply[n] = '\0';
        puts("Server reply :");
        puts(server_reply);
    }
    
    close(sock);
    return 0;
}