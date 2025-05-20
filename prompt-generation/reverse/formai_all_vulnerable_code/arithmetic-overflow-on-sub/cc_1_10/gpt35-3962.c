//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // create the socket
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    
    // handle any errors
    if(socketFd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // define the server address and port
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(8080);
    
    // connect to the server
    int connectionStatus = connect(socketFd, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    
    // handle any errors
    if(connectionStatus < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    // send a message to the server
    char *message = "Hello server!";
    int messageLength = strlen(message);
    
    // the send() function returns the number of bytes actually sent, so we need to make sure we send all the bytes
    int bytesSent = 0;
    
    while(bytesSent < messageLength) {
        int sendMessageStatus = send(socketFd, message + bytesSent, messageLength - bytesSent, 0);
        
        // handle any errors
        if(sendMessageStatus < 0) {
            perror("Error sending message to server");
            exit(EXIT_FAILURE);
        }
        
        bytesSent += sendMessageStatus;
    }
    
    // receive a message from the server
    char serverResponse[1024];
    
    // the recv() function returns the number of bytes actually received
    int bytesReceived = 0;
    
    while(bytesReceived == 0) {
        bytesReceived = recv(socketFd, serverResponse, 1024, 0);
    }
    
    // print the server's response
    printf("Server response: %s\n", serverResponse);
    
    // close the socket
    close(socketFd);
    
    return 0;
}