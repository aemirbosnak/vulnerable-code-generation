//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];

    if (argc!= 5) {
        printf("Usage:./pop3_client <server_ip> <server_port> <username> <password>\n");
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char auth_str[BUF_SIZE];
    sprintf(auth_str, "USER %s\r\n", username);
    send(sockfd, auth_str, strlen(auth_str), 0);

    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);
    n = recv(sockfd, response, BUF_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        return 1;
    }

    if (strstr(response, "+OK")) {
        sprintf(auth_str, "PASS %s\r\n", password);
        send(sockfd, auth_str, strlen(auth_str), 0);

        memset(response, 0, BUF_SIZE);
        n = recv(sockfd, response, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving response\n");
            return 1;
        }

        if (strstr(response, "+OK")) {
            printf("Authentication successful\n");
        } else {
            printf("Authentication failed\n");
            return 1;
        }
    } else {
        printf("Authentication failed\n");
        return 1;
    }

    close(sockfd);
    return 0;
}