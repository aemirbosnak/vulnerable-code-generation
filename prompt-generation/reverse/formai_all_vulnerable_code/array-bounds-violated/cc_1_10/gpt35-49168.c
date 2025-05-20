//FormAI DATASET v1.0 Category: Socket programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9000 // Define communication port for socket programming

int main(int argc, char *argv[]) {
    int socket_desc, client_sock, read_size;
    struct sockaddr_in server, client;
    char *message, client_message[2000];
     
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    // Define server address and port
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
     
    // Bind socket to address and port
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        return 1;
    }
    puts("bind done");
     
    // Listen for incoming connections
    listen(socket_desc, 3);
     
    // Accept incoming connection
    puts("Waiting for incoming connections...");
    int c = sizeof(struct sockaddr_in);
     
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
     
    // Send welcome message to client
    message = "Hello Client, I have received your connection. Your message is:\n";
    write(client_sock, message, strlen(message));
     
    // Receive message from client and send back response
    while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
        // Add null termination to client_message string
        client_message[read_size] = '\0';

        // Respond to client with their message
        write(client_sock, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        puts("Client disconnected");
    }
    else if (read_size == -1) {
        perror("recv failed");
    }
     
    return 0;
}