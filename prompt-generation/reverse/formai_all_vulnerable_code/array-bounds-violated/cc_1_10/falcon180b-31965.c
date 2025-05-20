//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SERVER "localhost"
#define PORT 110
#define BUFFER_SIZE 1024
#define USER "username"
#define PASS "password"

int main() {
    int sockfd, newsockfd, portno, clilen, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    char response[100];
    int ret;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Authenticate
    sprintf(username, "USER %s", USER);
    sprintf(password, "PASS %s", PASS);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);
    bzero(buffer, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // Retrieve messages
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret <= 0) {
            printf("Error receiving message\n");
            break;
        }
        buffer[ret] = '\0';
        printf("Message: %s\n", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}