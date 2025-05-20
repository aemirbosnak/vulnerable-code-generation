//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT "80"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, addrlen, opt = 1;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    char ip[16];
    int port = 0;
    int i = 0;

    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 0;
    }

    strcpy(ip, argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error opening socket\n");
        return 0;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        printf("Invalid IP Address\n");
        return 0;
    }

    port = atoi(PORT);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return 0;
    }

    if (write(sockfd, "GET / HTTP/1.1\r\nHost: ", strlen("GET / HTTP/1.1\r\nHost: "))!= strlen("GET / HTTP/1.1\r\nHost: ")) {
        printf("Write failed\n");
        return 0;
    }

    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        printf("Read failed\n");
        return 0;
    }

    printf("Response from server:\n%s\n", buffer);

    close(sockfd);

    return 0;
}