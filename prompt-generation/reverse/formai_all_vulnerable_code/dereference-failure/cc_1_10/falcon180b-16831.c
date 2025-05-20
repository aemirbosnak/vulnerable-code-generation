//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void diep(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, numbytes;
    struct sockaddr_in serveraddr;
    char buffer[1024];
    int port = 8080;
    int timeout = 5000;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    strcpy(buffer, argv[1]);
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        diep("socket failed");

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, buffer, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
        diep("connect failed");

    char sendbuf[1024];
    strcpy(sendbuf, "PING");
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    while (1) {
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Disconnected after %d seconds\n", timeout);
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}