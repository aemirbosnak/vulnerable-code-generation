//FormAI DATASET v1.0 Category: Socket programming ; Style: innovative
//Welcome to the interactive chatbot program!

//First we will include all the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//Declaring the main function
int main() {
    
    //Creating the socket
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    
    //Check if the socket was created successfully
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }
    
    //Creating the socket structure
    struct sockaddr_in server;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons( 5000 );
    
    //Binding the socket to the port number
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("bind failed");
        return 1;
    }
    puts("bind done");
    
    //Listening for incoming connections
    listen(socket_desc , 3);
    
    //Waiting for incoming connections
    puts("Waiting for incoming connections...");
    
    //Accepting incoming connections
    int c = sizeof(struct sockaddr_in);
    struct sockaddr_in client;
    int client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        puts("accept failed");
        return 1;
    }
    puts("Connection accepted");
    
    //Reply to incoming messages
    char *reply;
    char message[2000] , client_reply[2000];
    
    //Loop to continuously listen for incoming messages
    while(1) {
        memset(client_reply, 0, sizeof(client_reply));
        recv(client_sock, client_reply, 2000, 0);
        printf("Client reply: %s\n", client_reply);
        
        //Checking for quit command and exiting the loop if true
        if(strcmp(client_reply, "Quit") == 0){
            break;
        }
        
        printf("Enter message: ");
        scanf("%s", reply);
        
        //Sending the reply message
        if(send(client_sock, reply, strlen(reply), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        //Printing the chat history
        printf("Server reply: %s\n", reply);
        
    }
    
    //Closing the connection
    close(socket_desc);
    return 0;
}