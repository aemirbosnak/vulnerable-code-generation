//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char message[100];

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Socket creation error \n");
        return -1;
    }

    // Configure server address 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address to binary format and assign to server address 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("Please enter a message to send to the server: ");
    gets(message);

    // Send message to server 
    send(sock, message, strlen(message), 0);

    // Receive message from server 
    valread = read(sock, buffer, 1024);
    printf("Message received from server: %s\n", buffer);

    // Close socket 
    close(sock);

    return 0;
}