//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to send and receive data through the socket
void sendData(int sock, char* message) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    strncpy(buffer, message, strlen(message));
    send(sock, buffer, strlen(buffer), 0);
    
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
}

// Function to handle commands sent by the user
void handleCommand(int sock) {
    char message[BUFFER_SIZE];
    memset(message, 0, BUFFER_SIZE);
    fgets(message, BUFFER_SIZE, stdin);
    message[strlen(message) - 1] = '\0';
    sendData(sock, message); // send command to the server
}

// Function to create socket and connect to the server
int connectToServer(char* serverIp, int serverPort) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);

    if (inet_pton(AF_INET, serverIp, &serverAddr.sin_addr) <= 0) {
        printf("Invalid server IP\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Successfully connected to server\n\n");

    return sock;
}

// Recursive function to handle user input and communicate with the server
void handleUserInput(int sock) {
    printf("Enter command: ");
    handleCommand(sock); // handle user command

    handleUserInput(sock); // repeat the process recursively
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./ftpclient <server IP> <server port>\n");
        exit(1);
    }

    char* serverIp = argv[1];
    int serverPort = atoi(argv[2]);

    int sock = connectToServer(serverIp, serverPort); // connect to the server

    handleUserInput(sock); // repeatedly handle user input and communicate with the server

    close(sock); // close the socket
    return 0;
}