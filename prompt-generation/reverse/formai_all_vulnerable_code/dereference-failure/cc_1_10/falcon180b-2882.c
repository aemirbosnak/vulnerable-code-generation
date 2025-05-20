//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080

void send_data(int sock, const char* data) {
    int len = strlen(data);
    send(sock, data, len, 0);
}

void receive_data(int sock, char* buffer, int buf_size) {
    int len = recv(sock, buffer, buf_size, 0);
    if (len <= 0) {
        printf("Connection closed\n");
        exit(1);
    }
    buffer[len] = '\0';
    printf("%s", buffer);
}

int main() {
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int sockfd;
    char send_buffer[MAX_DATA_SIZE];
    char recv_buffer[MAX_DATA_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            exit(1);
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        printf("Connected to server\n");
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }

    strcpy(send_buffer, "PING");
    send_data(sockfd, send_buffer);

    memset(recv_buffer, 0, sizeof(recv_buffer));
    receive_data(sockfd, recv_buffer, sizeof(recv_buffer));

    close(sockfd);

    return 0;
}