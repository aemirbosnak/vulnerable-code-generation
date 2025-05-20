//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *serv_ip;
    int port;
    char buff[1024];
    int n;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    serv_ip = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    host = gethostbyname(serv_ip);
    if (host == NULL) {
        fprintf(stderr, "No such host: %s\n", serv_ip);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s:%d\n", serv_ip, port);

    while (1) {
        memset(buff, 0, sizeof(buff));
        n = read(sockfd, buff, sizeof(buff));
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        printf("Received: %s", buff);
    }

    close(sockfd);
    return 0;
}