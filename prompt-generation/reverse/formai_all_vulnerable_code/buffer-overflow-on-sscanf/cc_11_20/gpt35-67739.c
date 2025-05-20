//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char* argv[]) {
    if(argc != 4) {
        fprintf(stderr, "Usage: %s ftp://[<user>:<password>@]<host>/<url-path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Parse command line arguments
    char* ftpURL = argv[1];
    char* userPwd = strtok(ftpURL + 6, "@");
    char* hostName = strtok(NULL, "/");
    char* pathName = strtok(NULL, "");
    char* userName = strtok(userPwd, ":");
    char* password = strtok(NULL, ":");
    if(!password) password = ""; //password may be empty

    //Initialize Socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    //Connect to FTP server
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(21);
    if(inet_pton(AF_INET, hostName, &servAddr.sin_addr) <= 0) {
        perror("Error parsing IP address");
        exit(EXIT_FAILURE);
    }
    if(connect(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0) {
        perror("Error connecting to FTP server");
        exit(EXIT_FAILURE);
    }

    //Login by sending username and password
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "USER %s\r\n", userName);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending username");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "PASS %s\r\n", password);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending password");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    //Enter passive mode and list directory
    int dataSockfd;
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "PASV\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error entering passive mode");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    unsigned int addr[6];
    sscanf(buffer, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)",
        &addr[0], &addr[1], &addr[2], &addr[3], &addr[4], &addr[5]);

    char ipAddress[20];
    memset(ipAddress, 0, 20);
    sprintf(ipAddress, "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
    int port = addr[4] * 256 + addr[5];

    struct sockaddr_in dataAddr;
    dataAddr.sin_family = AF_INET;
    dataAddr.sin_port = htons(port);
    if(inet_pton(AF_INET, ipAddress, &dataAddr.sin_addr) <= 0) {
        perror("Error parsing IP address");
        exit(EXIT_FAILURE);
    }

    dataSockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(dataSockfd < 0) {
        perror("Error opening data socket");
        exit(EXIT_FAILURE);
    }
    if(connect(dataSockfd, (struct sockaddr*)&dataAddr, sizeof(dataAddr)) < 0) {
        perror("Error connecting to data socket");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "LIST\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending LIST command");
        exit(EXIT_FAILURE);
    }

    //Receive and print server response
    memset(buffer, 0, BUFFER_SIZE);
    if(recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    //Receive and print directory listing
    memset(buffer, 0, BUFFER_SIZE);
    if(recv(dataSockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving directory listing");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    close(dataSockfd);
    close(sockfd);
    return 0;
}