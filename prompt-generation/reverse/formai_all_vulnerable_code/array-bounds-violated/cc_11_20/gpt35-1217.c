//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 21

int main(int argc, char *argv[]) {
    char serverIP[16];
    char username[20];
    char password[20];
    char filepath[20];
    printf("Enter the server IP Address\n");
    scanf("%s", serverIP);
    printf("Enter Username\n");
    scanf("%s", username);
    printf("Enter Password\n");
    scanf("%s", password);
    printf("Enter filepath\n");
    scanf("%s", filepath);
    // Create socket
    int socketfd, n = 0;
    char recvBuff[1024], sendBuff[1024];
    struct sockaddr_in server_addr;
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd < 0) {
        perror("Error: could not create socket");
        return EXIT_FAILURE;
    }
    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(serverIP);
    server_addr.sin_port = htons(SERVER_PORT);
    // Connect to server
    if(connect(socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: could not connect");
        return EXIT_FAILURE;
    }
    // Receive server response
    n = recv(socketfd, recvBuff, sizeof(recvBuff)-1, 0);
    if(n < 0) {
        perror("Error: could not receive data");
        return EXIT_FAILURE;
    }
    recvBuff[n] = 0; // Terminate received message
    printf("%s", recvBuff); // Print server message
    // Send Username
    sprintf(sendBuff, "USER %s\r\n", username);
    if(send(socketfd, sendBuff, strlen(sendBuff), 0) != strlen(sendBuff)) {
        perror("Error: could not send data");
        return EXIT_FAILURE;
    }
    n = recv(socketfd, recvBuff, sizeof(recvBuff)-1, 0);
    if(n < 0) {
        perror("Error: could not receive data");
        return EXIT_FAILURE;
    }
    recvBuff[n] = 0;
    printf("%s", recvBuff); // Print server response to username
    // Send Password
    sprintf(sendBuff, "PASS %s\r\n", password);
    if(send(socketfd, sendBuff, strlen(sendBuff), 0) != strlen(sendBuff)) {
        perror("Error: could not send data");
        return EXIT_FAILURE;
    }
    n = recv(socketfd, recvBuff, sizeof(recvBuff)-1, 0);
    if(n < 0) {
        perror("Error: could not receive data");
        return EXIT_FAILURE;
    }
    recvBuff[n] = 0;
    printf("%s", recvBuff); // Print server response to password
    // Switch to Passive Mode
    if(send(socketfd, "PASV\r\n", strlen("PASV\r\n"), 0) != strlen("PASV\r\n")) {
        perror("Error: could not send data");
        return EXIT_FAILURE;
    }
    n = recv(socketfd, recvBuff, sizeof(recvBuff)-1, 0);
    if(n < 0) {
        perror("Error: could not receive data");
        return EXIT_FAILURE;
    }
    recvBuff[n] = 0;
    printf("%s", recvBuff); // Print server response to passive mode
    // Get File Size
    sprintf(sendBuff, "SIZE %s\r\n", filepath);
    if(send(socketfd, sendBuff, strlen(sendBuff), 0) != strlen(sendBuff)) {
        perror("Error: could not send data");
        return EXIT_FAILURE;
    }
    n = recv(socketfd, recvBuff, sizeof(recvBuff)-1, 0);
    if(n < 0) {
        perror("Error: could not receive data");
        return EXIT_FAILURE;
    }
    recvBuff[n] = 0;
    printf("%s", recvBuff); // Print server response to file size
    // Retrieve File
    sprintf(sendBuff, "RETR %s\r\n", filepath);
    if(send(socketfd, sendBuff, strlen(sendBuff), 0) != strlen(sendBuff)) {
        perror("Error: could not send data");
        return EXIT_FAILURE;
    }
    n = recv(socketfd, recvBuff, sizeof(recvBuff)-1, 0);
    if(n < 0) {
        perror("Error: could not receive data");
        return EXIT_FAILURE;
    }
    recvBuff[n] = 0;
    printf("%s", recvBuff); // Print server response to retrieve file
    // Download File
    FILE *fp = fopen(filepath, "wb");
    if(fp == NULL) {
        perror("Error: could not open file");
        return EXIT_FAILURE;
    }
    while((n = recv(socketfd, recvBuff, sizeof(recvBuff)-1, 0)) > 0) {
        fwrite(recvBuff, sizeof(char), n, fp);
    }
    if(n < 0) {
        perror("Error: could not receive data");
        return EXIT_FAILURE;
    }
    fclose(fp);
    close(socketfd);
    return EXIT_SUCCESS;
}