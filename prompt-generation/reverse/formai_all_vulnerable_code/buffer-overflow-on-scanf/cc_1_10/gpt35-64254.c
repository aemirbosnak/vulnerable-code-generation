//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

// Constants
#define BUF_SIZE 1024
#define FTP_PORT 21

// Function prototypes
void connectToServer(int *socketFd, char *ipAddress);
void getResponse(int socketFd, char *response);
void sendCommand(int socketFd, char *command);
void loginToServer(int socketFd, char *username, char *password);
void downloadFile(int socketFd, char *filename);
void quit(int socketFd);

int main(int argc, char **argv) {
    int socketFd;
    char ipAddress[16];
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    char filename[BUF_SIZE];

    // Get server IP address from user input
    printf("Enter the IP address of the FTP server: ");
    scanf("%s", ipAddress);

    // Connect to server
    connectToServer(&socketFd, ipAddress);

    // Get login credentials from user input
    printf("Enter your FTP username: ");
    scanf("%s", username);
    printf("Enter your FTP password: ");
    scanf("%s", password);

    // Login to server
    loginToServer(socketFd, username, password);

    // Get file name and download file
    printf("Enter the name of the file to download: ");
    scanf("%s", filename);
    downloadFile(socketFd, filename);

    // Quit connection
    quit(socketFd);

    return 0;
}

void connectToServer(int *socketFd, char *ipAddress) {
    struct sockaddr_in serverAddr;

    *socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (*socketFd < 0) {
        perror("Error: Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(FTP_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress);

    if (connect(*socketFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error: Unable to connect to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at IP address: %s\n", ipAddress);

    // Get initial server response
    char response[BUF_SIZE];
    getResponse(*socketFd, response);
    printf("%s", response);
}

void getResponse(int socketFd, char *response) {
    char buffer[BUF_SIZE];
    memset(response, 0, BUF_SIZE);
    memset(buffer, 0, BUF_SIZE);

    // Keep reading socket until newline character is received
    while (strstr(response, "\n") == NULL) {
        int bytesReceived = recv(socketFd, buffer, BUF_SIZE, 0);
        if (bytesReceived < 0) {
            perror("Error: Unable to receive response from server");
            exit(EXIT_FAILURE);
        }
        strcat(response, buffer);
    }
}

void sendCommand(int socketFd, char *command) {
    if (send(socketFd, command, strlen(command), 0) < 0) {
        perror("Error: Unable to send command to server");
        exit(EXIT_FAILURE);
    }
}

void loginToServer(int socketFd, char *username, char *password) {
    char response[BUF_SIZE];

    // Send user command
    sendCommand(socketFd, "USER ");
    sendCommand(socketFd, username);
    sendCommand(socketFd, "\r\n");
    getResponse(socketFd, response);
    printf("%s", response);

    // Send pass command
    sendCommand(socketFd, "PASS ");
    sendCommand(socketFd, password);
    sendCommand(socketFd, "\r\n");
    getResponse(socketFd, response);
    printf("%s", response);
}

void downloadFile(int socketFd, char *filename) {
    char response[BUF_SIZE];

    // Send pasv command to enter passive mode
    sendCommand(socketFd, "PASV\r\n");
    getResponse(socketFd, response);
    printf("%s", response);

    // Parse response to get IP address and port for data transfer
    char *ipStart = strstr(response, "(");
    char *ipEnd = strstr(response, ",");
    char ipAddress[16];
    memset(ipAddress, 0, 16);
    strncat(ipAddress, ipStart+1, ipEnd-ipStart-1);

    char *portStart = ipEnd+1;
    char *portEnd = strstr(response, ")\r\n");
    int port1 = atoi(portStart);
    int port2 = atoi(portEnd+1);
    int port = port1*256 + port2;

    // Connect to server for data transfer
    int dataSocketFd;
    struct sockaddr_in dataServerAddr;

    dataSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (dataSocketFd < 0) {
        perror("Error: Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&dataServerAddr, 0, sizeof(dataServerAddr));
    dataServerAddr.sin_family = AF_INET;
    dataServerAddr.sin_port = htons(port);
    dataServerAddr.sin_addr.s_addr = inet_addr(ipAddress);

    if (connect(dataSocketFd, (struct sockaddr *)&dataServerAddr, sizeof(dataServerAddr)) < 0) {
        perror("Error: Unable to connect to server");
        exit(EXIT_FAILURE);
    }

    // Send retr command to retrieve file
    sendCommand(socketFd, "RETR ");
    sendCommand(socketFd, filename);
    sendCommand(socketFd, "\r\n");
    getResponse(socketFd, response);
    printf("%s", response);

    // Create file for writing downloaded data
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error: Unable to create file");
        exit(EXIT_FAILURE);
    }

    // Read and write data from server
    char buffer[BUF_SIZE];
    int bytesRead = 0;
    while ((bytesRead = recv(dataSocketFd, buffer, BUF_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesRead, file);
    }

    fclose(file);

    printf("File downloaded successfully\n");
}

void quit(int socketFd) {
    char response[BUF_SIZE];

    sendCommand(socketFd, "QUIT\r\n");
    getResponse(socketFd, response);
    printf("%s", response);

    close(socketFd);
}