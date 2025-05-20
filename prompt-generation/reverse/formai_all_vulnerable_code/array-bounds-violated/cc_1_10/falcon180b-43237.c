//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100

int main(int argc, char *argv[]) {
    int sockfd, portno, n, ret, len;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX];
    char *ip;

    if (argc < 3) {
        printf("Usage:./a.out <host_name/IP> <port_no>\n");
        exit(0);
    }

    ip = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    server = gethostbyname(ip);
    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting\n");
        exit(0);
    }

    printf("Connected to %s\n", ip);

    while (1) {
        ret = recv(sockfd, buffer, MAX, 0);
        if (ret <= 0) {
            printf("Disconnected from %s\n", ip);
            break;
        }
        buffer[ret] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}