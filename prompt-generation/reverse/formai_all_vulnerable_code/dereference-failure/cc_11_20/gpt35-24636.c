//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char* server_addr;  // POP3 server address
    char* user;         // POP3 user name
    char* pass;         // POP3 password
    int port = 110;     // POP3 port number

    // If server address, user name, and password are not provided as command line arguments
    if(argc != 4) {
        printf("Usage: %s <server_address> <user_name> <password>\n", argv[0]);
        return 1;
    }

    server_addr = argv[1];
    user = argv[2];
    pass = argv[3];

    printf("Connecting to %s:%d...\n", server_addr, port);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Resolve server address
    struct hostent* host = gethostbyname(server_addr);
    if(!host) {
        perror("gethostbyname");
        return 1;
    }

    // Fill in server address and port number
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *(struct in_addr*) host->h_addr;
    serv_addr.sin_port = htons(port);

    // Connect to server
    if(connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read from server
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Send user name and password
    char user_cmd[BUF_SIZE];
    char pass_cmd[BUF_SIZE];
    memset(user_cmd, 0, sizeof(user_cmd));
    memset(pass_cmd, 0, sizeof(pass_cmd));
    sprintf(user_cmd, "USER %s\r\n", user);
    sprintf(pass_cmd, "PASS %s\r\n", pass);
    if(send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("send");
        return 1;
    }
    memset(buf, 0, sizeof(buf));
    if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);
    if(strncmp(buf, "+OK", 3) != 0) {
        printf("Authentication failed. Exiting...\n");
        close(sockfd);
        return 1;
    }
    if(send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("send");
        return 1;
    }
    memset(buf, 0, sizeof(buf));
    if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);
    if(strncmp(buf, "+OK", 3) != 0) {
        printf("Authentication failed. Exiting...\n");
        close(sockfd);
        return 1;
    }

    // List all messages on server
    if(send(sockfd, "LIST\r\n", 6, 0) < 0) {
        perror("send");
        return 1;
    }
    memset(buf, 0, sizeof(buf));
    if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Quit
    if(send(sockfd, "QUIT\r\n", 6, 0) < 0) {
        perror("send");
        return 1;
    }
    memset(buf, 0, sizeof(buf));
    if(recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Close socket
    close(sockfd);
    printf("Disconnected from server.\n");

    return 0;
}