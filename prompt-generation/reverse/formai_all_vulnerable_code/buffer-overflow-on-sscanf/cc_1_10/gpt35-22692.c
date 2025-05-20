//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

// Define constants for FTP commands
#define FTP_USER "USER myusername\r\n"
#define FTP_PASS "PASS mypassword\r\n"
#define FTP_QUIT "QUIT\r\n"
#define FTP_BINARY "TYPE I\r\n"
#define FTP_ASCII "TYPE A\r\n"
#define FTP_PASSIVE "PASV\r\n"
#define FTP_LIST "LIST\r\n"
#define FTP_RETR "RETR %s\r\n"

// Define buffer size
#define BUFFER_SIZE 1024

// Define FTP response codes
#define FTP_CODE_READY 220
#define FTP_CODE_PASSIVE_MODE 227
#define FTP_CODE_LOGIN_SUCCESS 230
#define FTP_CODE_FILE_STATUS_OKAY 150
#define FTP_CODE_TRANSFER_COMPLETE 226
#define FTP_CODE_GOODBYE 221
#define FTP_CODE_SUCCESS 250
#define FTP_CODE_REQUESTED_FILE_ACTION_COMPLETED 250
#define FTP_CODE_FILE_NOT_FOUND 550

// Function to connect to FTP server
int connectToServer(const char *address, const int port) {
    // Create a socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check for errors
    if (socketfd == -1) {
        perror("ERROR: Failed to create socket");
        exit(1);
    }

    // Create server address struct
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr)); // Zero-out the memory
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);

    // Convert IP address string to binary form
    if (inet_pton(AF_INET, address, &serveraddr.sin_addr) <= 0) {
        perror("ERROR: Invalid address / Address not supported");
        exit(1);
    }

    // Connect to server
    if (connect(socketfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("ERROR: Failed to connect to server");
        exit(1);
    }

    return socketfd;
}

// Function to read response from the FTP server
int getFTPServerResponse(int socketfd, char *buffer, int bufferSize) {
    // Clear the buffer
    memset(buffer, 0, bufferSize);

    // Read response from server
    int responseSize = recv(socketfd, buffer, bufferSize, 0);

    // Check for errors
    if (responseSize == -1) {
        perror("ERROR: Failed to read from server");
        exit(1);
    }

    return responseSize;
}

// Function to send command to FTP server
void sendFTPCommand(int socketfd, const char *command) {
    if (send(socketfd, command, strlen(command), 0) == -1) {
        perror("ERROR: Failed to send command");
        exit(1);
    }
}

// Function to log in to FTP server
void loginToServer(int socketfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];
    int responseCode;

    // Send username
    sendFTPCommand(socketfd, FTP_USER);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_READY) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    // Send password
    sendFTPCommand(socketfd, FTP_PASS);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_LOGIN_SUCCESS) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    printf("Successfully logged in to server\n");
}

// Function to set binary transfer mode
void setBinaryMode(int socketfd) {
    char buffer[BUFFER_SIZE];
    int responseCode;

    // Send command
    sendFTPCommand(socketfd, FTP_BINARY);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_SUCCESS) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    printf("Binary transfer mode set\n");
}

// Function to set ASCII transfer mode
void setASCIIMode(int socketfd) {
    char buffer[BUFFER_SIZE];
    int responseCode;

    // Send command
    sendFTPCommand(socketfd, FTP_ASCII);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_SUCCESS) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    printf("ASCII transfer mode set\n");
}

// Function to switch to passive mode
int switchToPassiveMode(int socketfd) {
    char buffer[BUFFER_SIZE];
    int responseCode;
    int pasvPort = -1;

    // Send command
    sendFTPCommand(socketfd, FTP_PASSIVE);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d)", &responseCode, &pasvPort);

    // Check for expected response
    if (responseCode != FTP_CODE_PASSIVE_MODE) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    return pasvPort;
}

// Function to get the IP address of the FTP server
char *getServerIP(const char *hostname) {
    struct hostent *he;
    struct in_addr **addr_list;
    char *ip = NULL;

    // Get host by name
    if ((he = gethostbyname(hostname)) == NULL) {
        perror("ERROR: Could not resolve server hostname");
        exit(1);
    }

    // Get list of IP addresses
    addr_list = (struct in_addr **)he->h_addr_list;

    // Copy first IP address to buffer
    if (addr_list[0] != NULL) {
        ip = inet_ntoa(*addr_list[0]);
    } else {
        printf("ERROR: Could not determine server IP address\n");
        exit(1);
    }

    return ip;
}

// Function to download a file from the server
void downloadFile(int socketfd, const char *filename) {
    char buffer[BUFFER_SIZE];
    int responseCode;
    FILE *fp;
    int pasvSocketfd;
    int pasvPort;
    struct sockaddr_in pasvServeraddr;
    char *ip;

    // Switch to binary transfer mode
    setBinaryMode(socketfd);

    // Switch to passive mode
    pasvPort = switchToPassiveMode(socketfd);

    // Get IP address of server
    ip = getServerIP("ftp.example.com");

    // Create socket for passive mode
    pasvSocketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (pasvSocketfd == -1) {
        perror("ERROR: Failed to create socket");
        exit(1);
    }

    // Create server address struct for passive mode
    memset(&pasvServeraddr, 0, sizeof(pasvServeraddr)); // Zero-out the memory
    pasvServeraddr.sin_family = AF_INET;
    pasvServeraddr.sin_port = htons(pasvPort);

    // Convert IP address string to binary form for passive server
    if (inet_pton(AF_INET, ip, &pasvServeraddr.sin_addr) <= 0) {
        perror("ERROR: Invalid address / Address not supported");
        exit(1);
    }

    // Connect to server in passive mode
    if (connect(pasvSocketfd, (struct sockaddr *)&pasvServeraddr, sizeof(pasvServeraddr)) == -1) {
        perror("ERROR: Failed to connect to server in passive mode");
        exit(1);
    }

    // Send RETR command to server
    sprintf(buffer, FTP_RETR, filename);
    sendFTPCommand(socketfd, buffer);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_FILE_STATUS_OKAY) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    // Open file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("ERROR: Failed to open file for writing");
        exit(1);
    }

    // Receive file data
    int bytesRead;
    while ((bytesRead = recv(pasvSocketfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesRead, fp);
    }

    // Check for errors
    if (bytesRead == -1) {
        perror("ERROR: Failed to read from server");
        exit(1);
    }

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_TRANSFER_COMPLETE) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    // Close file
    fclose(fp);

    printf("File downloaded successfully\n");
}

// Function to list directory contents
void listDirectory(int socketfd) {
    char buffer[BUFFER_SIZE];
    int responseCode;
    int pasvSocketfd;
    int pasvPort;
    struct sockaddr_in pasvServeraddr;
    char *ip;

    // Switch to ASCII transfer mode
    setASCIIMode(socketfd);

    // Switch to passive mode
    pasvPort = switchToPassiveMode(socketfd);

    // Get IP address of server
    ip = getServerIP("ftp.example.com");

    // Create socket for passive mode
    pasvSocketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (pasvSocketfd == -1) {
        perror("ERROR: Failed to create socket");
        exit(1);
    }

    // Create server address struct for passive mode
    memset(&pasvServeraddr, 0, sizeof(pasvServeraddr)); // Zero-out the memory
    pasvServeraddr.sin_family = AF_INET;
    pasvServeraddr.sin_port = htons(pasvPort);

    // Convert IP address string to binary form for passive server
    if (inet_pton(AF_INET, ip, &pasvServeraddr.sin_addr) <= 0) {
        perror("ERROR: Invalid address / Address not supported");
        exit(1);
    }

    // Connect to server in passive mode
    if (connect(pasvSocketfd, (struct sockaddr *)&pasvServeraddr, sizeof(pasvServeraddr)) == -1) {
        perror("ERROR: Failed to connect to server in passive mode");
        exit(1);
    }

    // Send LIST command to server
    sendFTPCommand(socketfd, FTP_LIST);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_FILE_STATUS_OKAY) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    // Read directory data
    int bytesRead;
    while ((bytesRead = recv(pasvSocketfd, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%.*s", bytesRead, buffer);
    }

    // Check for errors
    if (bytesRead == -1) {
        perror("ERROR: Failed to read from server");
        exit(1);
    }

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_TRANSFER_COMPLETE) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    printf("Directory listing completed\n");
}

int main(int argc, char *argv[]) {
    int socketfd;
    char buffer[BUFFER_SIZE];
    int responseCode;

    // Connect to server
    socketfd = connectToServer("ftp.example.com", 21);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_READY) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    // Log in to server
    loginToServer(socketfd, "myusername", "mypassword");

    // List directory contents
    listDirectory(socketfd);

    // Download a file
    downloadFile(socketfd, "testfile.txt");

    // Quit
    sendFTPCommand(socketfd, FTP_QUIT);

    // Get response
    getFTPServerResponse(socketfd, buffer, BUFFER_SIZE);
    sscanf(buffer, "%d", &responseCode);

    // Check for expected response
    if (responseCode != FTP_CODE_GOODBYE) {
        printf("ERROR: Invalid response from server\n");
        exit(1);
    }

    printf("FTP client complete\n");

    return 0;
}