//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110
#define SERVER "localhost"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUFFER_SIZE];
    char recv_buf[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(send_buf, argv[1]);
    strcat(send_buf, "\r\n");
    strcat(send_buf, argv[2]);
    strcat(send_buf, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    send(sockfd, send_buf, strlen(send_buf), 0);
    memset(recv_buf, 0, BUFFER_SIZE);

    while ((n = recv(sockfd, recv_buf, BUFFER_SIZE, 0)) > 0) {
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
        memset(recv_buf, 0, BUFFER_SIZE);
    }

    close(sockfd);
    return 0;
}