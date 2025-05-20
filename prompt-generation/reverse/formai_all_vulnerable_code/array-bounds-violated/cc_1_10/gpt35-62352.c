//FormAI DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Could not create socket. \n");
    }

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }

    //Listen
    listen(socket_desc, 3);

    //Accept and incoming connection
    printf("Sherlock: Waiting for incoming connections...\n");
    socklen_t clilen = sizeof(client);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, &clilen);
    if(client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    printf("Sherlock: Connection accepted.\n");

    printf("Sherlock: Waiting for client input...\n");
    //Receive a message from client
    while((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
        //end of string marker
        client_message[read_size] = '\0';

        //Send the message back to client
        write(client_sock, client_message, strlen(client_message));
    }

    if(read_size == 0) {
        printf("Sherlock: Client disconnected.\n");
    } else if(read_size == -1) {
        perror("recv failed");
    }

    return 0;
}