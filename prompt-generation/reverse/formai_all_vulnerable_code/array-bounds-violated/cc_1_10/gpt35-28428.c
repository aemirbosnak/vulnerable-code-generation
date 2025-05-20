//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

int sockfd = 0, n = 0;
char recvBuff[1024];
struct sockaddr_in serv_addr;

void error(char *msg) {
    fprintf(stderr, "[ERROR] %s\n", msg);
    exit(1);
}

void connect_server() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("socket");

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        error("inet_pton");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect");

    printf("Connected to Server\n");
}

void send_message(char *message) {
    if (send(sockfd, message, strlen(message), 0) < 0)
        error("send");
}

void receive_message() {
    memset(recvBuff, '0', sizeof(recvBuff));
    if ((n = recv(sockfd, recvBuff, sizeof(recvBuff) - 1, 0)) < 0)
        error("recv");
    recvBuff[n] = '\0';
    printf("%s\n", recvBuff);
}

int main(void) {
    connect_server();
    send_message("Hello Server");
    receive_message();
    close(sockfd);
    return 0;
}