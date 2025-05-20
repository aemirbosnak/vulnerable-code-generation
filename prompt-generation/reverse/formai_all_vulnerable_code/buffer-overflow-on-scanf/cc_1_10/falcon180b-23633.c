//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <unistd.h>

#define MAX 100

struct sockaddr_in serv_addr;
int sockfd;
char send_data[MAX];
char recv_data[MAX];

void error(const char* msg) {
    perror(msg);
    exit(0);
}

int main() {
    int opt = 1;
    int addrlen = sizeof(serv_addr);
    char hostname[MAX];
    char service[MAX];
    struct hostent* server;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the service: ");
    scanf("%s", service);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket failed");
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt))) {
        error("setsockopt");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        error("no such host");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(service));

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("connect failed");
    }

    printf("Connected to %s:%s\n", hostname, service);

    while (1) {
        memset(send_data, 0, sizeof(send_data));
        memset(recv_data, 0, sizeof(recv_data));

        printf("Enter the message to send: ");
        scanf("%s", send_data);

        if (send(sockfd, send_data, strlen(send_data), 0) < 0) {
            error("send failed");
        }

        if (recv(sockfd, recv_data, sizeof(recv_data), 0) < 0) {
            error("recv failed");
        }

        printf("Received message: %s\n", recv_data);
    }

    return 0;
}