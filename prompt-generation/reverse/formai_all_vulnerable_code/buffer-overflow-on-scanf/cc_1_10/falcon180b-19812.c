//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", send_buffer);
        n = send(sockfd, send_buffer, strlen(send_buffer), 0);
        if (n <= 0) {
            printf("Failed to send command\n");
            break;
        }

        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Failed to receive response\n");
            break;
        }

        printf("Response: %s", recv_buffer);
    }

    close(sockfd);
    return 0;
}