//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host, *username, *password;
    int port;
    char buffer[BUF_SIZE];
    FILE *fp;

    // Check for valid command line arguments
    if (argc!= 6) {
        printf("Usage:./ftp_client <host> <port> <username> <password> <file>\n");
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];
    fp = fopen(argv[5], "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        return 1;
    }

    // Send login credentials
    char login[BUF_SIZE];
    sprintf(login, "USER %s\r\n", username);
    send(sockfd, login, strlen(login), 0);

    char pass[BUF_SIZE];
    sprintf(pass, "PASS %s\r\n", password);
    send(sockfd, pass, strlen(pass), 0);

    // Receive server response
    memset(buffer, 0, BUF_SIZE);
    recv(sockfd, buffer, BUF_SIZE, 0);
    printf("Server response: %s", buffer);

    // Send file contents
    while (fgets(buffer, BUF_SIZE, fp)!= NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
    }

    // Close file and socket
    fclose(fp);
    close(sockfd);

    return 0;
}