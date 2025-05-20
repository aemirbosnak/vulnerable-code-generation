//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
/*
FTP Client Program
Author: [Your Name]
Date: [Date]

This program builds an FTP client that connects to an FTP server,
logs in using username and password provided by the user, and downloads a file
from the server. In this example, the user is prompted to enter the file name to download.

Note: This program is designed to work with servers that support the passive mode.
If the server requires active mode transfer, the program needs to be modified accordingly.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ftpclient <hostname> <port>");
        return 1;
    }
    // Get Hostname and Port Number
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create Socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket Creation Failed");
        return 1;
    }

    // Get Host IP Address
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        perror("Host Not Found");
        return 1;
    }

    // Setup Server Address Structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he -> h_addr);
    server_addr.sin_port = htons(port);

    // Connect to Server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection Failed");
        return 1;
    }

    // Verify Connection
    char status[MAX_SIZE];
    if (recv(sockfd, status, MAX_SIZE, 0) == -1) {
        perror("Verification Failed");
        return 1;
    }
    printf("%s\n", status);

    // Get Login Details
    char username[MAX_SIZE], password[MAX_SIZE];
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    // Send Username to Server
    char user[MAX_SIZE];
    snprintf(user, MAX_SIZE, "USER %s\r\n", username);
    if (send(sockfd, user, strlen(user), 0) == -1) {
        perror("Sending Username Failed");
        return 1;
    }

    // Verify Username
    if (recv(sockfd, status, MAX_SIZE, 0) == -1) {
        perror("Verification Failed");
        return 1;
    }
    printf("%s\n", status);

    // Send Password to Server
    char pass[MAX_SIZE];
    snprintf(pass, MAX_SIZE, "PASS %s\r\n", password);
    if (send(sockfd, pass, strlen(pass), 0) == -1) {
        perror("Sending Password Failed");
        return 1;
    }

    // Verify Password
    if (recv(sockfd, status, MAX_SIZE, 0) == -1) {
        perror("Verification Failed");
        return 1;
    }
    printf("%s\n", status);

    // Enter Passive Mode
    if (send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0) == -1) {
        perror("Entering Passive Mode Failed");
        return 1;
    }

    // Receive Passive Mode Address
    char response[MAX_SIZE];
    if (recv(sockfd, response, MAX_SIZE, 0) == -1) {
        perror("Receiving Passive Mode Address Failed");
        return 1;
    }
    printf("%s\n", response);

    // Parse Passive Mode Address
    char *ip_addr_s = strtok(response, ",") + 1;
    char *port_s = strtok(NULL, ",") + 1;
    for (int i = 0; i < 3; i++) {
        strtok(NULL, ",");
    }
    int port_i = atoi(port_s) * 256 + atoi(strtok(NULL, ","));

    // Connect to Passive Mode
    struct sockaddr_in passive_addr;
    passive_addr.sin_family = AF_INET;
    passive_addr.sin_port = htons(port_i);
    if (inet_pton(AF_INET, ip_addr_s, &passive_addr.sin_addr) != 1) {
        perror("Passive Mode Address Conversion Failed");
        return 1;
    }
    int pasv_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (pasv_sockfd == -1) {
        perror("Passive Mode Socket Creation Failed");
        return 1;
    }
    if (connect(pasv_sockfd, (struct sockaddr *)&passive_addr, sizeof(passive_addr)) == -1) {
        perror("Passive Mode Connection Failed");
        return 1;
    }

    // Get File Name
    char filename[MAX_SIZE];
    printf("Enter File Name: ");
    scanf("%s", filename);

    // Request File from Server
    char retr[MAX_SIZE];
    snprintf(retr, MAX_SIZE, "RETR %s\r\n", filename);
    if (send(sockfd, retr, strlen(retr), 0) == -1) {
        perror("Requesting File Failed");
        return 1;
    }

    // Verify File Request
    if (recv(sockfd, status, MAX_SIZE, 0) == -1) {
        perror("Verification Failed");
        return 1;
    }
    printf("%s\n", status);

    // Receive File
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("File Creation Failed");
        return 1;
    }
    char buffer[MAX_SIZE];
    int bytes_recv = 0;
    while ((bytes_recv = read(pasv_sockfd, buffer, MAX_SIZE)) > 0) {
        fwrite(buffer, sizeof(char), bytes_recv, fp);
    }
    fclose(fp);

    printf("File Downloaded Successfully!\n");

    // Close Connection
    close(pasv_sockfd);
    close(sockfd);

    return 0;
}