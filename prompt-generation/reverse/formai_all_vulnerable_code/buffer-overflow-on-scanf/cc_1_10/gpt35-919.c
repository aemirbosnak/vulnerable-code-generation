//FormAI DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[]) {
    int sockfd, ret;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error in connection.\n");
        exit(1);
    }
    printf("Socket successfully created..\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0) {
        printf("Error in connection...\n");
        exit(1);
    }
    printf("Connected to the server...\n");

    while(1) {
        char buffer[1024];
        printf("Client: ");
        scanf("%s", &buffer[0]);
        send(sockfd, buffer, strlen(buffer), 0);

        if(strcmp(buffer, ":exit") == 0) {
            close(sockfd);
            printf("Closing the connection.\n");
            exit(1);
        }

        if(recv(sockfd, buffer, 1024, 0) < 0) {
            printf("Error in receiving data from the server.\n");
        } else {
            printf("Server: %s\n", buffer);
        }
    }
    return 0;
}