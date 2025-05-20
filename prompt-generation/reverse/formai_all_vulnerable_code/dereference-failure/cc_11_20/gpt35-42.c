//FormAI DATASET v1.0 Category: Socket programming ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>

#define PORT 8080
#define MAX_CLIENTS 5

int main(){
    int server_fd, client_fd, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int addrlen = sizeof(server_addr), num_clients = 0;;
    fd_set readfds; //set of socket file descriptors

    // Creating server file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options to reuse address and port
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket to server address
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming clients
    if(listen(server_fd, MAX_CLIENTS)<0){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Welcome message
    printf("RETRO SOCKET SERVER\nWaiting for clients...\n");

    // Loop to handle incoming client connections
    while(1){
        // Clearing socket set
        FD_ZERO(&readfds);
        // Adding server fd to set
        FD_SET(server_fd, &readfds);

        // Adding connected client fds to set
        for(int i = 0; i < num_clients; i++){
            FD_SET(client_fd, &readfds);
        }

        // Monitoring set of fds for any activity
        if(select(FD_SETSIZE, &readfds, NULL, NULL, NULL) < 0){
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // If new client connection request is received
        if(FD_ISSET(server_fd, &readfds)){
            // Accepting incoming client connection
            if((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0){
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
            // Incrementing number of clients
            num_clients++;
            // Sending welcome message to client
            char *message = "Welcome to Retro Socket Server!\n";
            send(client_fd, message, strlen(message), 0);
            printf("Client connected! IP: %s, Port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }

        // If a connected client sends a message
        for(int i = 0; i < num_clients; i++){
            if(FD_ISSET(client_fd, &readfds)){
                // Receiving message from client
                int valread = read(client_fd, buffer, 1024);
                // Displaying message on server console
                printf("Client message: %s\n", buffer);
                // Sending acknowledgment to client
                char *message = "Message received by server!\n";
                send(client_fd, message, strlen(message), 0);
            }
        }
    }

    return 0;
}