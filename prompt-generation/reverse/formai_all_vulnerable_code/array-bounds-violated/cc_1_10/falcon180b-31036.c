//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    struct hostent *host_info;

    if ((host_info = gethostbyname(ip_address)) == NULL) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host_info->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    char send_buffer[BUF_SIZE];
    char recv_buffer[BUF_SIZE];

    snprintf(send_buffer, BUF_SIZE, "PING\r\n");

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    int recv_len;
    if ((recv_len = recv(sockfd, recv_buffer, BUF_SIZE, 0)) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    recv_buffer[recv_len] = '\0';
    printf("Received response: %s\n", recv_buffer);

    close(sockfd);
    return 0;
}