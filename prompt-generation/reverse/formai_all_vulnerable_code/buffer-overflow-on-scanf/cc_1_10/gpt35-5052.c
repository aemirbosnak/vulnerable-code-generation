//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_BUFF_SIZE 1024
#define SERVER_PORT 110 // POP3 port
#define SERVER_IP "192.168.1.1" // Server IP

// Function to receive data from server
void receiveData(int clientSocket, char *buffer) {
    memset(buffer, 0, MAX_BUFF_SIZE);
    recv(clientSocket, buffer, MAX_BUFF_SIZE, 0);
}

// Function to send data to server
void sendData(int clientSocket, char *data) {
    send(clientSocket, data, strlen(data), 0);
}

// Function to connect to POP3 server
int connectToServer(char *serverIPAddress, int serverPort) {
    int clientSocket;
    struct sockaddr_in serverAddr;
    
    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0) {
        printf("Failed to create socket\n");
        return -1;
    }
    
    // Set server address parameters
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = inet_addr(serverIPAddress);
    
    // Connect to server
    if(connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }
    
    // Receive server welcome message
    char buffer[MAX_BUFF_SIZE];
    receiveData(clientSocket, buffer);
    printf("%s", buffer);
    
    return clientSocket;
}

int main() {
    int clientSocket = connectToServer(SERVER_IP, SERVER_PORT);
    if(clientSocket < 0) {
        return -1;
    }
    
    char username[50], password[50];
    
    printf("Enter your username:\n"); // Authenticate user
    scanf("%s", username);
    char data[MAX_BUFF_SIZE];
    sprintf(data, "USER %s\r\n", username);
    sendData(clientSocket, data);
    receiveData(clientSocket, data);
    printf("%s", data);
    
    printf("Enter your password:\n");
    scanf("%s", password);
    sprintf(data, "PASS %s\r\n", password);
    sendData(clientSocket, data);
    receiveData(clientSocket, data);
    printf("%s", data);
    
    // List number of emails in inbox
    sendData(clientSocket, "STAT\r\n");
    receiveData(clientSocket, data);
    printf("%s", data);
    
    // Retrieve first email
    sendData(clientSocket, "RETR 1\r\n");
    receiveData(clientSocket, data);
    printf("%s", data);
    
    close(clientSocket);
    
    return 0;
}