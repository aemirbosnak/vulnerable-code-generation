//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX 1024
#define SERVER "speedtest.net"
#define PORT "80"

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main() {
    int sockfd, portno, n;
    struct hostent *servinfo;
    struct sockaddr_in servaddr;
    char buffer[MAX];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("Socket failed");

    servinfo = gethostbyname(SERVER);

    if (servinfo == NULL) {
        printf("No such host\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;

    memcpy(&servaddr.sin_addr, servinfo->h_addr, servinfo->h_length);

    portno = atoi(PORT);

    servaddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        error("Connection failed");

    printf("Connected to %s:%d\n", SERVER, portno);

    while (1) {
        bzero(buffer, MAX);
        n = read(sockfd, buffer, MAX);

        if (n < 0)
            error("Read failed");

        printf("%s", buffer);
    }

    return 0;
}