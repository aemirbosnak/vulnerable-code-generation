//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    FILE *fp;

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        exit(0);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error : Unable to create socket\n");
        exit(0);
    }

    // Resolve server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error : No such host\n");
        exit(0);
    }

    // Fill server structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error : Unable to connect\n");
        exit(0);
    }

    // Authenticate with username and password
    sprintf(buffer, "USER %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    sprintf(buffer, "PASS %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Change working directory
    sprintf(buffer, "CWD /\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Retrieve file list
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Open local file for writing
    fp = fopen(argv[3], "w");
    if (fp == NULL) {
        printf("Error : Unable to open file\n");
        exit(0);
    }

    // Download file
    while (1) {
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (strncmp(buffer, "226", 3) == 0) {
            break;
        }
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    // Close connections and exit
    fclose(fp);
    close(sockfd);
    exit(0);
}