//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER "speedtest.net"
#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[BUFFER_SIZE];
    char recv_data[BUFFER_SIZE];
    struct hostent *server;

    if (argc < 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 1;
    }

    server = gethostbyname(SERVER);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    while (1) {
        memset(send_data, 'a', BUFFER_SIZE);
        send(sockfd, send_data, BUFFER_SIZE, 0);

        n = recv(sockfd, recv_data, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Connection closed by server\n");
            break;
        }

        printf("Received %d bytes of data\n", n);
    }

    close(sockfd);
    return 0;
}