//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[4096];
    char send_buffer[4096];
    double start_time, end_time;
    double total_time;
    double data_rate;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    start_time = difftime(time(NULL), time(NULL));
    n = send(sockfd, argv[1], strlen(argv[1]), 0);
    if (n == -1) {
        printf("Error sending file name.\n");
        exit(1);
    }

    while ((n = fread(send_buffer, 1, 4096, fp)) > 0) {
        send(sockfd, send_buffer, n, 0);
    }

    fclose(fp);

    total_time = difftime(time(NULL), start_time);
    data_rate = (double)file_size / total_time;

    printf("File size: %ld bytes\n", file_size);
    printf("Transfer time: %.2f seconds\n", total_time);
    printf("Data rate: %.2f bytes/second\n", data_rate);

    close(sockfd);
    return 0;
}