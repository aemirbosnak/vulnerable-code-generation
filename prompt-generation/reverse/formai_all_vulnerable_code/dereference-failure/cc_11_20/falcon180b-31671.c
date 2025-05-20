//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[64];
    char password[64];
    char buffer[BUF_SIZE];
    int n;
    int port = 110;
    char *hostname = "localhost";
    int user_flag = 0;
    int pass_flag = 0;
    int auth_flag = 0;
    int ret;

    printf("POP3 Client\n");

    // Get username and password from command line arguments
    if (argc >= 3) {
        strcpy(username, argv[1]);
        strcpy(password, argv[2]);
        user_flag = 1;
    }

    // Connect to POP3 server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    // Send USER command
    if (user_flag) {
        ret = send(sockfd, username, strlen(username), 0);
        if (ret == -1) {
            perror("send");
            exit(1);
        }
    }

    // Send PASS command
    if (user_flag && pass_flag) {
        ret = send(sockfd, password, strlen(password), 0);
        if (ret == -1) {
            perror("send");
            exit(1);
        }
    }

    // Send AUTH command
    if (user_flag && auth_flag) {
        ret = send(sockfd, "AUTH LOGIN\r\n", 15, 0);
        if (ret == -1) {
            perror("send");
            exit(1);
        }
    }

    // Receive server response
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    // Send QUIT command
    ret = send(sockfd, "QUIT\r\n", 6, 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}