//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

// FTP server details
#define PORT 21
#define HOST "ftp://example.com"
#define USER "username"
#define PASSWORD "password"

// Function to connect to FTP server
int connectFTP(int *sockfd, char *hostaddr) {
    struct sockaddr_in serveraddr;
    struct hostent* host;
    int addr;
    char message[1024];
    int code;

    // Getting FTP server address
    host = gethostbyname(hostaddr);
    if (host == NULL) {
        printf("Error: Unable to get FTP server address\n");
        return -1;
    }

    // Setting up server address details
    addr = inet_addr(inet_ntoa(*(struct in_addr*)*host->h_addr_list));
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = addr;

    // Connecting to the FTP server
    if((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Socket creation failed\n");
        return -1;
    }
    if(connect(*sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: Unable to connect to the server\n");
        return -1;
    }
    printf("Connected to FTP server %s on port %d\n", HOST, PORT);

    // Receiving initial response from the server
    recv(*sockfd, message, sizeof(message), 0);
    printf("%s", message);

    // Entering username to login
    sprintf(message, "USER %s\r\n", USER);
    send(*sockfd, message, strlen(message), 0);
    recv(*sockfd, message, sizeof(message), 0);
    sscanf(message, "%d", &code);
    if(code != 331) {
        printf("Error: Unable to enter username\n");
        return -1;
    }
    printf("%s", message);

    // Entering password to login
    sprintf(message, "PASS %s\r\n", PASSWORD);
    send(*sockfd, message, strlen(message), 0);
    recv(*sockfd, message, sizeof(message), 0);
    sscanf(message, "%d", &code);
    if(code != 230) {
        printf("Error: Unable to enter password\n");
        return -1;
    }
    printf("%s", message);

    return 0; // Success
}

// Function to download file from FTP server
int downloadFile(int sockfd, char *filename) {
    char message[1024];
    char buffer[1024];
    FILE *file;
    int code;
    int bytes;

    // Sending request to download file
    sprintf(message, "RETR %s\r\n", filename);
    send(sockfd, message, strlen(message), 0);

    // Checking if file exists on server
    recv(sockfd, message, sizeof(message), 0);
    sscanf(message, "%d", &code);
    if(code != 150) {
        printf("Error: Unable to download file: %s\n", filename);
        return -1;
    }

    // Creating local file and writing data to it
    file = fopen(filename, "wb");
    while((bytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes, file);
    }
    fclose(file);

    // Receiving response from server after file download
    recv(sockfd, message, sizeof(message), 0);
    sscanf(message, "%d", &code);
    if(code != 226) {
        printf("Error: Unable to receive response from server after downloading file: %s\n", filename);
        return -1;
    }
    printf("File %s downloaded successfully\n", filename);

    return 0; // Success
}

int main() {
    int sockfd;
    char filename[128];

    // Connecting to FTP server
    if(connectFTP(&sockfd, HOST) == -1) {
        return -1;
    }

    // Downloading file from FTP server
    printf("Enter filename to download: ");
    scanf("%s", filename);
    downloadFile(sockfd, filename);

    // Closing connection to FTP server
    close(sockfd);
    printf("Connection closed\n");

    return 0;
}