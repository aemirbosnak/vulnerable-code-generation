//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 65535
#define DEFAULT_PORT 80

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN - 1);
    hostname[MAX_HOSTNAME_LEN - 1] = '\0';

    int port = DEFAULT_PORT;
    if (argc > 2) {
        port = atoi(argv[2]);
    }

    int sockfd, ret;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char send_data[MAX_DATA_LEN];
    strcpy(send_data, "GET / HTTP/1.1\r\nHost: ");
    strncat(send_data, hostname, MAX_HOSTNAME_LEN - 1);
    strcat(send_data, "\r\nConnection: close\r\n\r\n");

    ret = send(sockfd, send_data, strlen(send_data), 0);
    if (ret == -1) {
        printf("Error sending data\n");
        close(sockfd);
        return 1;
    }

    char recv_data[MAX_DATA_LEN];
    memset(recv_data, 0, MAX_DATA_LEN);

    ret = recv(sockfd, recv_data, MAX_DATA_LEN, 0);
    if (ret == -1) {
        printf("Error receiving data\n");
        close(sockfd);
        return 1;
    }

    printf("Received data:\n%s", recv_data);

    close(sockfd);
    return 0;
}