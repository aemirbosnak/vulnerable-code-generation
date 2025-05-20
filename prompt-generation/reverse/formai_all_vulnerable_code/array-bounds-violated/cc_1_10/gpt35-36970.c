//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define PORT 7000

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    int option = 1;
    struct sockaddr_in serv_addr, local_addr;

    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];

    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }

    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(PORT);

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1) {
        error_handling("setsockopt() error");
    }

    if (bind(sock, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        error_handling("bind() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(PORT);

    while (1) {
        printf("Input message: ");
        fgets(send_buf, BUF_SIZE, stdin);
        
        sendto(sock, send_buf, strlen(send_buf), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        socklen_t addr_size = sizeof(serv_addr);
        ssize_t recv_size = recvfrom(sock, recv_buf, BUF_SIZE, 0, (struct sockaddr *)&serv_addr, &addr_size);
        if (recv_size == -1) {
            error_handling("recvfrom() error");
        }
        recv_buf[recv_size] = '\0';

        printf("Received message: %s", recv_buf);
    }

    close(sock);

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}