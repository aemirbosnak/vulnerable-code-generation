//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int len;

    if (argc!= 4) {
        printf("Usage:./client <server_ip> <server_port> <message>\n");
        return 0;
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 0;
    }

    printf("Connected to server\n");

    strcpy(send_buffer, argv[3]);
    len = strlen(send_buffer);

    send(sockfd, send_buffer, len, 0);

    printf("Message sent to server\n");

    memset(recv_buffer, 0, BUFFER_SIZE);
    len = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    printf("Received from server: %s\n", recv_buffer);

    close(sockfd);

    return 0;
}