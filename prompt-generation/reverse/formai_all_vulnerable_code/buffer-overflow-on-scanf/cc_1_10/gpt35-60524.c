//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_RECV_BUF 4096

int main(int argc, char *argv[]) {
    // Initialize variables and structures
    char recv_buf[MAX_RECV_BUF];
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char server_ip[20];
    char username[100];
    char password[100];
    char command[100];

    // Get server IP address from user input
    printf("Enter POP3 server IP address: ");
    scanf("%s", server_ip);

    // Open socket to connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(110); // POP3 port

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    printf("Connected to POP3 server %s\n", server_ip);

    // Get username and password from user input
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Send username and password to server
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    write(sockfd, command, strlen(command));
    memset(recv_buf, 0, MAX_RECV_BUF);
    read(sockfd, recv_buf, MAX_RECV_BUF);
    if (recv_buf[0] != '+') {
        printf("Username not accepted by server\n");
        exit(1);
    }
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    write(sockfd, command, strlen(command));
    memset(recv_buf, 0, MAX_RECV_BUF);
    read(sockfd, recv_buf, MAX_RECV_BUF);
    if (recv_buf[0] != '+') {
        printf("Password not accepted by server\n");
        exit(1);
    }

    // List emails on server
    snprintf(command, sizeof(command), "LIST\r\n");
    write(sockfd, command, strlen(command));
    memset(recv_buf, 0, MAX_RECV_BUF);
    read(sockfd, recv_buf, MAX_RECV_BUF);
    printf("%s", recv_buf);

    // Quit connection
    snprintf(command, sizeof(command), "QUIT\r\n");
    write(sockfd, command, strlen(command));
    memset(recv_buf, 0, MAX_RECV_BUF);
    read(sockfd, recv_buf, MAX_RECV_BUF);

    // Close socket
    close(sockfd);

    return 0;
}