//FormAI DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>   
#include <sys/socket.h>  
#include <arpa/inet.h>   
#include <unistd.h>  

int main()  
{  
    int socket_desc, client_sock, c, read_size;  
    struct sockaddr_in server, client;  
    char client_message[2000], response[2000];  
    
    // Create socket  
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);  
    if (socket_desc == -1)  
    {  
        perror("Could not create socket");  
        return 1;  
    }  
    puts("Socket created");  
    
    // Set up the server sockaddr_in structure  
    server.sin_family = AF_INET;  
    server.sin_addr.s_addr = INADDR_ANY;  
    server.sin_port = htons(8888);  
    
    // Bind  
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)  
    {  
        perror("Bind failed. Error");  
        return 1;  
    }  
    puts("Bind done");  
    
    // Listen  
    listen(socket_desc, 3);  
    
    // Accept incoming connections  
    puts("Waiting for incoming connections...");  
    c = sizeof(struct sockaddr_in);  
    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)))  
    {  
        puts("Connection accepted");  
        
        // Read data from client  
        while((read_size = recv(client_sock, client_message, 2000, 0)) > 0 )  
        {  
            // null-terminate the message received from the client  
            client_message[read_size] = '\0';  
            
            // Handle client commands  
            if(!strcmp(client_message, "exit"))  
            {  
                break;  
            }  
            else  
            {  
                // Prepare response  
                sprintf(response, "Received: %s", client_message);  
                write(client_sock, response, strlen(response));  
            }  
        }  
        
        // Close connection when client sends "exit" command  
        if(read_size == 0)  
        {  
            puts("Client disconnected");  
            fflush(stdout);  
        }  
        else if(read_size == -1)  
        {  
            perror("recv failed");  
        }  
        
        // Clear buffer  
        memset(client_message, 0, 2000);  
    }  
    
    return 0;  
}