//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, recv_len;
    char buffer[BUF_SIZE] = {0};
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Error: Invalid server address\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Connection failed\n");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server upon connection
    recv_len = recv(sockfd, buffer, BUF_SIZE, 0);
    if (recv_len > 0) {
        printf("%s\n", buffer);
    }

    // Send user credentials to server
    send(sockfd, "USER username\r\n", strlen("USER username\r\n"), 0);
    recv_len = recv(sockfd, buffer, BUF_SIZE, 0);

    send(sockfd, "PASS password\r\n", strlen("PASS password\r\n"), 0);
    recv_len = recv(sockfd, buffer, BUF_SIZE, 0);

    // Enter passive mode
    send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0);
    recv_len = recv(sockfd, buffer, BUF_SIZE, 0);

    // Parse the IP address and port number from PASV mode reply
    char *p1, *p2;
    int ip1, ip2, ip3, ip4, port1, port2;

    p1 = strchr(buffer, '(') + 1;
    p2 = strrchr(buffer, ')');

    sscanf(p1, "%d,%d,%d,%d,%d,%d", &ip1, &ip2, &ip3, &ip4, &port1, &port2);

    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = htonl((ip1 << 24) | (ip2 << 16) | (ip3 << 8) | ip4);
    data_addr.sin_port = htons((port2 << 8) | port1);

    // Open data connection to server
    int data_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(data_fd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Error: Data connection failed\n");
        exit(EXIT_FAILURE);
    }

    // Send command to list remote files
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    recv_len = recv(sockfd, buffer, BUF_SIZE, 0);

    // Receive list of files over data connection and print to console
    memset(buffer, 0, BUF_SIZE);
    while ((recv_len = recv(data_fd, buffer, BUF_SIZE, 0)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUF_SIZE);
    }

    // Close data connection
    close(data_fd);

    // Send command to terminate session
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv_len = recv(sockfd, buffer, BUF_SIZE, 0);

    // Close control connection
    close(sockfd);

    return 0;
}