//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 110
#define BUFFER_SIZE 1024
#define USERNAME "sherlock.holmes"
#define PASSWORD "elementary"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Could not create socket : %d\n", errno);
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "localhost", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Could not connect to server : %d\n", errno);
        exit(0);
    }

    printf("Connected to server\n");

    sprintf(send_buffer, "USER %s\r\n", USERNAME);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    if (n > 0) {
        printf("Received from server : %s\n", recv_buffer);
    }

    sprintf(send_buffer, "PASS %s\r\n", PASSWORD);
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    if (n > 0) {
        printf("Received from server : %s\n", recv_buffer);
    }

    close(sockfd);

    return 0;
}