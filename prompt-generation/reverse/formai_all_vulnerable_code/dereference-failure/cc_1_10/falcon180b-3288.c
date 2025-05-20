//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    int numbytes;
    FILE *fp;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    fp = fopen("logfile.txt", "w");
    if (fp == NULL) {
        printf("Cannot create log file\n");
        exit(1);
    }

    while(1) {
        memset(send_buf, 0, BUF_SIZE);
        memset(recv_buf, 0, BUF_SIZE);

        numbytes = send(sock, send_buf, BUF_SIZE, 0);
        if (numbytes <= 0) {
            printf("send failed\n");
            exit(1);
        }

        numbytes = recv(sock, recv_buf, BUF_SIZE, 0);
        if (numbytes <= 0) {
            printf("recv failed\n");
            exit(1);
        }

        fprintf(fp, "Received data: %s\n", recv_buf);
        fflush(fp);
    }

    close(sock);
    fclose(fp);

    return 0;
}