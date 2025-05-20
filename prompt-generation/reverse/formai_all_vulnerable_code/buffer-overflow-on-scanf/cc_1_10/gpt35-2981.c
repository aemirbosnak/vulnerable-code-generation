//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    int socket_desc;
    struct sockaddr_in server, client;
    char message[1000], response[2000];
     
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
     
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
     
    printf("Socket created\n");
     
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
     
    // Bind
    if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
        // print the error message
        perror("bind failed. Error");
        return 1;
    }
     
    printf("bind done\n");
     
    // Listen
    listen(socket_desc, 3);
     
    // Accept and incoming connection
    printf("Waiting for incoming connections...\n");
    int c = sizeof(struct sockaddr_in);
    int client_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);
     
    if (client_socket < 0) {
        perror("accept failed");
        return 1;
    }
     
    printf("Connection accepted\n");

    // Send and receive messages
    while (1) {
        printf("Your message: ");
        scanf("%s", message);
         
        // Send the message to the server
        if (send(client_socket, message, strlen(message), 0) < 0) {
            perror("Send failed");
            return 1;
        }
         
        // Receive a reply from the server
        if (recv(client_socket, response, 2000, 0) < 0) {
            perror("recv failed");
            break;
        }
         
        printf("Server reply: %s\n", response);
    }
     
    close(socket_desc);
    return 0;
}