//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendbuf[BUFFER_SIZE], recvbuf[BUFFER_SIZE];
    int n, total_sent = 0, total_recv = 0;
    FILE *fp;

    if (argc < 4) {
        printf("Usage:./ftp_client <server_ip> <port_number> <file_to_send>\n");
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in connecting to server\n");
        exit(1);
    }

    fp = fopen(argv[3], "rb");
    if (fp == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    while ((n = fread(sendbuf, 1, BUFFER_SIZE, fp)) > 0) {
        send(sockfd, sendbuf, n, 0);
        total_sent += n;
    }

    fclose(fp);

    while ((n = recv(sockfd, recvbuf, BUFFER_SIZE, 0)) > 0) {
        total_recv += n;
        recvbuf[n] = '\0';
        printf("%s", recvbuf);
    }

    close(sockfd);

    printf("Total bytes sent: %d\n", total_sent);
    printf("Total bytes received: %d\n", total_recv);

    return 0;
}