//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUF_SIZE 1024

int connectToServer(const char* server, const char* port) {
    struct addrinfo hints, *res;
    int sockfd;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(server, port, &hints, &res) != 0) {
        return -1;
    }
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        return -1;
    }
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        return -1;
    }
    freeaddrinfo(res);
    return sockfd;
}

void sendCommand(int sockfd, const char* command) {
    char buffer[BUF_SIZE];
    strcpy(buffer, command);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
}

void receiveResponse(int sockfd) {
    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sockfd, buffer, BUF_SIZE, 0) <= 0) {
            break;
        }
        printf("%s", buffer);
        if (buffer[strlen(buffer) - 1] == '\n') {
            break;
        }
    }
}

void receiveMessage(int sockfd) {
    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sockfd, buffer, BUF_SIZE, 0) <= 0) {
            break;
        }
        printf("%s", buffer);
        if (strstr(buffer, "BODY[TEXT]") != NULL) {
            break;
        }
    }
}

void downloadAttachment(int sockfd) {
    FILE* file = fopen("attachment.txt", "wb");
    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sockfd, buffer, BUF_SIZE, 0) <= 0) {
            break;
        }
        if (strstr(buffer, "\r\n.\r\n") != NULL) {
            fwrite(buffer, sizeof(char), strlen(buffer) - 5, file);
            break;
        }
        fwrite(buffer, sizeof(char), strlen(buffer), file);
    }
    fclose(file);
}

int main() {
    char username[100], password[100], server[100], port[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter server: ");
    scanf("%s", server);
    printf("Enter port: ");
    scanf("%s", port);
    int sockfd = connectToServer(server, port);
    if (sockfd == -1) {
        printf("Could not connect to server\n");
        return 1;
    }
    receiveResponse(sockfd);
    sendCommand(sockfd, "a001 LOGIN ");
    sendCommand(sockfd, username);
    sendCommand(sockfd, password);
    receiveResponse(sockfd);
    sendCommand(sockfd, "a002 SELECT INBOX");
    receiveResponse(sockfd);
    sendCommand(sockfd, "a003 FETCH 1 BODY[TEXT]");
    receiveMessage(sockfd);
    sendCommand(sockfd, "a004 FETCH 1 BODY[TEXT]");
    downloadAttachment(sockfd);
    sendCommand(sockfd, "a005 LOGOUT");
    receiveResponse(sockfd);
    close(sockfd);
    return 0;
}