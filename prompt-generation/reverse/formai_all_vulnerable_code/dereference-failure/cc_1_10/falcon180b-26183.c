//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_line[MAX_LINE];
    char recv_line[MAX_LINE];

    if (argc!= 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(send_line, "USER ");
    strcat(send_line, argv[2]);
    strcat(send_line, "\r\n");

    strcpy(send_line, "PASS ");
    strcat(send_line, argv[3]);
    strcat(send_line, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    send(sockfd, send_line, strlen(send_line), 0);

    while (1) {
        memset(recv_line, 0, MAX_LINE);
        if (recv(sockfd, recv_line, MAX_LINE, 0) <= 0) {
            printf("Disconnected\n");
            break;
        }
        printf("%s", recv_line);
    }

    close(sockfd);
    return 0;
}