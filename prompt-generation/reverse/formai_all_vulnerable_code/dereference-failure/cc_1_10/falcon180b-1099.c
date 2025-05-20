//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT "80"

void print_usage() {
    fprintf(stderr, "Usage:./qos_monitor <IP address>\n");
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage();
    }

    char* ip_address = argv[1];
    struct addrinfo hints, *servinfo;
    int rv;
    int sockfd;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(ip_address, PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)!= 0) {
        perror("connect");
        exit(1);
    }

    send(sockfd, "GET / HTTP/1.1\r\nHost:\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost:\r\nConnection: close\r\n\r\n"), 0);

    memset(recv_buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        perror("recv");
        exit(1);
    }

    close(sockfd);

    struct tm* current_time;
    time_t now = time(NULL);
    current_time = localtime(&now);

    printf("QoS monitor report for %s at %d-%02d-%02d %02d:%02d:%02d\n", ip_address, current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday, current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

    return 0;
}