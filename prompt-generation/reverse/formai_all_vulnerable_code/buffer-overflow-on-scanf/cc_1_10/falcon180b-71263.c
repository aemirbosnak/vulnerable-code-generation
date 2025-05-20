//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

struct sockaddr_in server_addr;
int sockfd;

int main() {
    int n;
    char buffer[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        exit(0);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        exit(0);
    }
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter a message: ");
        scanf("%s", buffer);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n == -1) {
            printf("Message send failed\n");
            exit(0);
        }
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n == -1) {
            printf("Message receive failed\n");
            exit(0);
        }
        printf("Received message: %s\n", buffer);
    }
    close(sockfd);
    return 0;
}