//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char sendbuf[256];
    char recvbuf[256];

    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("ERROR: No such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(53);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    send(sockfd, "QUERY /a=1\r\n\r\n", 22, 0);

    while ((n = recv(sockfd, recvbuf, 255, 0)) > 0) {
        recvbuf[n] = '\0';
        printf("Received: %s\n", recvbuf);
    }

    close(sockfd);

    return 0;
}