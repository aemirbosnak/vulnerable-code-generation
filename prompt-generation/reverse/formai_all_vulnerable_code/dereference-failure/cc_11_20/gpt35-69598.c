//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
// C program for implementing a simple HTTP Proxy server using sockets
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

int main(int argc , char *argv[])
{
    int proxy_sock , client_sock , c , read_size;
    struct sockaddr_in proxy , client;
    char client_message[2000], server_reply[2000];

    //Create socket for the proxy server
    proxy_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (proxy_sock == -1)
    {
        printf("Could not create proxy socket");
    }
    puts("Proxy socket created");
     
    //Prepare the sockaddr_in structure
    proxy.sin_family = AF_INET;
    proxy.sin_addr.s_addr = INADDR_ANY;
    proxy.sin_port = htons( atoi(argv[1]) );
     
    //Bind the proxy server socket to a specific address and port
    if( bind(proxy_sock,(struct sockaddr *)&proxy , sizeof(proxy)) < 0)
    {
        perror("Couldn't bind proxy to provided port");
        return 1;
    }
    puts("Bind successful");
     
    //Listen for incoming connections
    listen(proxy_sock , 3);
     
    //Accept incoming connection request
    puts("Waiting for incoming connections...\n");
    c = sizeof(struct sockaddr_in);
     
    //Accept the connection from client
    client_sock = accept(proxy_sock, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("Error in accepting incoming connection");
        return 1;
    }
    puts("Connection accepted");

    //Read incoming message from client
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    {
        //Forward the message from client to server
        int server_sock;
        struct sockaddr_in server;
     
        server_sock = socket(AF_INET , SOCK_STREAM , 0);
        if (server_sock == -1)
        {
            printf("Could not create server socket");
        }
        puts("Server socket created");

        server.sin_addr.s_addr = inet_addr("192.168.15.10");
        server.sin_family = AF_INET;
        server.sin_port = htons( 80 );
     
        //Connect to remote server
        if (connect(server_sock , (struct sockaddr *)&server , sizeof(server)) < 0)
        {
            perror("Error in connecting to remote server");
            return 1;
        }

        //Send message to server
        if( send(server_sock , client_message , strlen(client_message) , 0) < 0)
        {
            perror("Error in forwarding request to remote server");
            return 1;
        }
         
        //Receive reply from server
        if( recv(server_sock, server_reply , 2000 , 0) < 0)
        {
            perror("Error in receiving reply from remote server");
            return 1;
        }
         
        //Send reply to client
        if( send(client_sock , server_reply , strlen(server_reply) , 0) < 0)
        {
            perror("Error in sending reply to client");
            return 1;
        }

        memset(client_message, 0, sizeof(client_message));
        memset(server_reply, 0, sizeof(server_reply));
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("Error in receiving data from client");
    }

    return 0;
}