//FormAI DATASET v1.0 Category: Client Server Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char *argv[]) {

    int sock_desc, new_sock, c;
    struct sockaddr_in server, client;
    char *message, client_reply[2000];
     
    //Create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
     
    //Bind
    if (bind(sock_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(sock_desc , 3);
     
    //Accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    new_sock = accept(sock_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (new_sock < 0) {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
     
    //Reply to client
    message = "Hello Client, I have received your request.\n";
    write(new_sock, message, strlen(message));
     
    //Receive a reply from client
    while (1) {
        memset(client_reply, 0, sizeof(client_reply));
        if(recv(new_sock, client_reply, 2000, 0) == 0){
            printf("Client disconnected");
            fflush(stdout);
            break;
        }
        printf("Client: %s\n", client_reply);
         
        //Send a reply to client
        printf("Enter a message for the client: ");
        scanf("%s", message);
        if(send(new_sock, message, strlen(message), 0) < 0) {
            perror("send failed");
            return 1;
        }   
    }
     
    return 0;
}