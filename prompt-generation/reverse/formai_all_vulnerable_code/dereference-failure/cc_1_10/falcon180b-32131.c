//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT "80"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./qos_monitor <IP Address> <QoS Type>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    if (strcmp(argv[2], "throughput") == 0) {
        sprintf(send_buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    } else if (strcmp(argv[2], "latency") == 0) {
        sprintf(send_buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: keep-alive\r\n\r\n", argv[1]);
    } else {
        printf("Invalid QoS type\n");
        exit(1);
    }

    send(sockfd, send_buffer, strlen(send_buffer), 0);

    recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    printf("Response:\n%s\n", recv_buffer);

    close(sockfd);

    return 0;
}