//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: energetic
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    //create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1){
        printf("Could not create socket");
    }
    puts("Socket created");

    //prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    //bind
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0){
        //print the error message
        perror("Bind failed. Error");
        return 1;
    }
    puts("Bind done");

    //listen
    listen(socket_desc, 3);

    //accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0){
        perror("Accept failed");
        return 1;
    }
    puts("Connection accepted");

    //receive a message from client
    while((read_size = recv(client_sock, client_message, 2000, 0)) > 0){
        //end of string marker
        client_message[read_size] = '\0';

        //send the message back to client
        write(client_sock, client_message, strlen(client_message));
    }

    if(read_size == 0){
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1){
        perror("Recv failed");
    }

    return 0;
}