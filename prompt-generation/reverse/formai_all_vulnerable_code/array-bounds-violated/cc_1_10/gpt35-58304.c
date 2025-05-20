//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NUMBER 8080
#define BUFFER_SIZE 1024

int main()
{
    printf("Hi there! I am a curious networking chatbot. Let's play a game:\n");
    printf("I will create a simple server-client interaction program for us.\n");
    printf("Do you want to be the server or the client? Enter 's' for server, 'c' for client:\n");
    char choice;
    scanf("%c", &choice);
    
    if(choice == 's') {
        printf("Great! I will be the client and connect to your server.\n");
        
        int server_socket, client_socket, address_length, num_bytes;
        char buffer[BUFFER_SIZE];
        struct sockaddr_in server_address, client_address;
        
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT_NUMBER);
        server_address.sin_addr.s_addr = INADDR_ANY;
        
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        
        if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
            perror("Error: Could not bind to socket");
            exit(1);
        }
        
        listen(server_socket, 1);
        printf("Waiting for connection...\n");
        
        address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&address_length);
        
        if(client_socket < 0) {
            perror("Error: Could not establish connection");
            exit(1);
        }
        
        printf("Connected successfully!\n");
        printf("Enter what you want to tell me: ");
        scanf("%s", buffer);
        
        num_bytes = send(client_socket, buffer, strlen(buffer), 0);
        printf("Sent %d bytes to client.\n", num_bytes);
        
        close(client_socket);
        close(server_socket);
        printf("Disconnected from server. Game over!\n");
        
    } else if(choice ==  'c') {
        printf("Awesome! I will be the server and wait for you to connect.\n");
        
        int client_socket, num_bytes;
        char buffer[BUFFER_SIZE];
        struct sockaddr_in server_address;
        
        memset(&server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(PORT_NUMBER);
        server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
        
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        
        if(connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
            perror("Error: Could not connect to server");
            exit(1);
        }
        
        printf("Connected successfully!\n");
        printf("Waiting for message...\n");
        
        num_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
        buffer[num_bytes] = '\0';
        
        printf("Received message: %s\n", buffer);
        
        close(client_socket);
        printf("Disconnected from server. Game over!\n");
        
    } else {
        printf("Invalid choice! Game over!\n");
    }
    
    return 0;
}