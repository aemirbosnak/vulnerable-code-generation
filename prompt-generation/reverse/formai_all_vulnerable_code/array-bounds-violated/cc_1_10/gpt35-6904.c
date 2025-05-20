//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

// Function to send the FTP commands to the server
void sendFTPCommand(int sockfd, const char* cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

// Function to receive the response from the server
void recvFTPResponse(int sockfd) {
    char buffer[1024];
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[n] = '\0';
    printf("Received: %s", buffer);
}

int main(int argc, char *argv[]) {

    // Check for correct number of arguments
    if (argc != 4) {
        printf("Usage: ./ftpclient <IP address> <Username> <Password>\n");
        return 0;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(21);

    // Connect to server
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Receive welcome message
    recvFTPResponse(sockfd);

    // Send username
    char usercmd[100];
    sprintf(usercmd, "USER %s\r\n", argv[2]);
    sendFTPCommand(sockfd, usercmd);
    recvFTPResponse(sockfd);

    // Send password
    char passcmd[100];
    sprintf(passcmd, "PASS %s\r\n", argv[3]);
    sendFTPCommand(sockfd, passcmd);
    recvFTPResponse(sockfd);

    // Change to binary mode
    sendFTPCommand(sockfd, "TYPE I\r\n");
    recvFTPResponse(sockfd);

    // Enter passive mode
    sendFTPCommand(sockfd, "PASV\r\n");
    char buffer[1024];
    recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[strlen(buffer)] = '\0';

    // Parse the IP and port numbers from the response
    char *start = strchr(buffer, '(') + 1;
    char *end = strchr(start, ')');
    *end = '\0';
    char *tok = strtok(start, ",");
    char ip[20];
    sprintf(ip, "%s.%s.%s.%s", tok, strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","));
    int port = atoi(strtok(NULL, ",")) * 256 + atoi(strtok(NULL, ","));

    // Connect to data port
    struct sockaddr_in dataaddr;
    memset(&dataaddr, 0, sizeof(dataaddr));
    dataaddr.sin_family = AF_INET;
    dataaddr.sin_addr.s_addr = inet_addr(ip);
    dataaddr.sin_port = htons(port);

    int dataport = socket(AF_INET, SOCK_STREAM, 0);
    connect(dataport, (struct sockaddr *)&dataaddr, sizeof(dataaddr));

    // Request file list
    sendFTPCommand(sockfd, "LIST\r\n");
    recvFTPResponse(sockfd);

    // Print file list
    char filebuf[1024];
    int nbytes;
    while ((nbytes = recv(dataport, filebuf, sizeof(filebuf), 0)) > 0) {
        fwrite(filebuf, nbytes, 1, stdout);
    }
    recvFTPResponse(sockfd);

    // Close connections
    close(dataport);
    close(sockfd);

    return 0;
}