//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char *server_name;
    char buffer[BUF_SIZE];
    int optval = 1;
    int rc;

    if (argc!= 3) {
        printf("Usage: %s <server_name> <port_number>\n", argv[0]);
        exit(1);
    }

    server_name = argv[1];
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, server_name, &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    rc = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof(optval));
    if (rc == -1) {
        perror("setsockopt");
        exit(1);
    }

    rc = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (rc == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", server_name, atoi(argv[2]));

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        rc = recv(sock, buffer, BUF_SIZE, 0);
        if (rc == -1) {
            perror("recv");
            exit(1);
        }

        if (rc == 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("Received %d bytes from server\n", rc);
        printf("Data: %s\n", buffer);
    }

    close(sock);
    exit(0);
}