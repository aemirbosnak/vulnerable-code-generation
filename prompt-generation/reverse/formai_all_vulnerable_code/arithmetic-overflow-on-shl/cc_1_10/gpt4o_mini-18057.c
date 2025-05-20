//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define FTP_PORT 21

// Structure for FTP Control Connection
typedef struct {
    int controlSocket;
    char serverResponse[BUFSIZE];
} FTPClient;

// Function to establish a control connection to the FTP server
int connectToServer(FTPClient *client, const char *serverIp) {
    struct sockaddr_in serverAddr;
    client->controlSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->controlSocket < 0) {
        perror("Error creating socket");
        return -1;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, serverIp, &serverAddr.sin_addr) <= 0) {
        perror("Invalid address");
        close(client->controlSocket);
        return -1;
    }

    if (connect(client->controlSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        close(client->controlSocket);
        return -1;
    }

    return 0;
}

// Function to send commands to the FTP server and receive responses
void sendCommand(FTPClient *client, const char *command) {
    send(client->controlSocket, command, strlen(command), 0);
    send(client->controlSocket, "\r\n", 2, 0);
    recv(client->controlSocket, client->serverResponse, BUFSIZE, 0);
}

// Function to log in to the FTP server
int login(FTPClient *client, const char *username, const char *password) {
    char command[BUFSIZE];
    
    snprintf(command, sizeof(command), "USER %s", username);
    sendCommand(client, command);
    printf("Server Response: %s\n", client->serverResponse);

    snprintf(command, sizeof(command), "PASS %s", password);
    sendCommand(client, command);
    printf("Server Response: %s\n", client->serverResponse);

    return (strstr(client->serverResponse, "230") ? 0 : -1);
}

// Function to list files on the FTP server
void listFiles(FTPClient *client) {
    sendCommand(client, "PASV");
    printf("Server Response: %s\n", client->serverResponse);

    // Extract IP and port from response
    int p1, p2, port;
    char ip[16];
    sscanf(client->serverResponse, "%*[^()] (%[^,],%[^,],%[^,],%[^,],%d,%d)", 
           &ip, &ip + 1, &ip + 2, &ip + 3, &p1, &p2);
    
    port = (p1 << 8) + p2;
    struct sockaddr_in dataAddr;
    dataAddr.sin_family = AF_INET;
    dataAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &dataAddr.sin_addr);

    int dataSocket = socket(AF_INET, SOCK_STREAM, 0);
    connect(dataSocket, (struct sockaddr *)&dataAddr, sizeof(dataAddr));

    sendCommand(client, "LIST");
    printf("Server Response: %s\n", client->serverResponse);

    // Receive the list of files
    char buffer[BUFSIZE];
    int bytesRead;
    while ((bytesRead = recv(dataSocket, buffer, BUFSIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, stdout);
    }

    close(dataSocket);
}

// Function to quit the FTP session
void quit(FTPClient *client) {
    sendCommand(client, "QUIT");
    printf("Server Response: %s\n", client->serverResponse);
    close(client->controlSocket);
}

int main() {
    FTPClient client;
    const char *serverIp = "127.0.0.1"; // Replace with your FTP server IP
    const char *username = "your_username"; // Replace with your username
    const char *password = "your_password"; // Replace with your password

    if (connectToServer(&client, serverIp) < 0) {
        exit(EXIT_FAILURE);
    }

    sendCommand(&client, "USER anonymous");
    printf("Server Response: %s\n", client.serverResponse);

    if (login(&client, username, password) < 0) {
        fprintf(stderr, "Login failed\n");
        close(client.controlSocket);
        exit(EXIT_FAILURE);
    }

    listFiles(&client);
    
    quit(&client);
    return 0;
}