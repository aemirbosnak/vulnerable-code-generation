//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 21
#define MAX_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[MAX_SIZE];
    char recv_buffer[MAX_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("FTP client connected to server\n");

    while(1) {
        printf("Enter command (USER, PASS, LIST, RETR, QUIT): ");
        scanf("%s", send_buffer);

        n = send(sockfd, send_buffer, strlen(send_buffer), 0);

        memset(recv_buffer, 0, MAX_SIZE);

        n = recv(sockfd, recv_buffer, MAX_SIZE, 0);

        printf("Server response: %s\n", recv_buffer);

        if(strcmp(send_buffer, "QUIT") == 0) {
            break;
        }
    }

    close(sockfd);

    return 0;
}