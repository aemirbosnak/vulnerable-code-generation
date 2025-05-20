//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUFFER_SIZE];
    char recv_buf[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./pop3_client <server_ip> <username> <password>\n");
        return 1;
    }

    strcpy(send_buf, "USER ");
    strcat(send_buf, argv[2]);
    strcat(send_buf, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    send(sockfd, send_buf, strlen(send_buf), 0);

    while ((n = recv(sockfd, recv_buf, BUFFER_SIZE, 0)) > 0) {
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
    }

    close(sockfd);

    return 0;
}