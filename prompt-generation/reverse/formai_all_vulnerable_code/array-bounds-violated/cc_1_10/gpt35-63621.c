//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXSIZE 1024

void ftpClient(int);

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error in creating socket!");
        exit(1);
    }
    printf("[INFO] Client socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(21);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int connection = connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(connection == -1) {
        perror("[ERROR] Connection failed!");
        close(sockfd);
        exit(1);
    }
    printf("[INFO] Connection successful!\n");

    ftpClient(sockfd);

    close(sockfd);
    return 0;
}

void ftpClient(int sockfd) {
    char message[MAXSIZE], recvMsg[MAXSIZE];
    int recvBytes;

    recvBytes = recv(sockfd, recvMsg, sizeof(recvMsg), 0);
    recvMsg[recvBytes] = '\0';
    printf("%s", recvMsg);

    while(1) {
        printf("> ");
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, strlen(message), 0);
        recvBytes = recv(sockfd, recvMsg, sizeof(recvMsg), 0);
        recvMsg[recvBytes] = '\0';
        printf("%s", recvMsg);
    }
}