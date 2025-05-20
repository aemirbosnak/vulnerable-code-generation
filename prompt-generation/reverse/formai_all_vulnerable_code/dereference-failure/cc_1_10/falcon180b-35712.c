//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        exit(1);
    }

    strcpy(send_buffer, "HELO ");
    strcat(send_buffer, argv[3]);
    strcat(send_buffer, "\r\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    send(sockfd, send_buffer, strlen(send_buffer), 0);

    while (1) {
        memset(recv_buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            break;
        }
        fprintf(stdout, "%s", recv_buffer);
    }

    close(sockfd);

    return 0;
}