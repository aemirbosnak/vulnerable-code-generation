//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char recvbuf[BUFFER_SIZE], ipstr[INET_ADDRSTRLEN];
    struct hostent *he;
    struct sockaddr_in their_addr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(PORT);
    their_addr.sin_addr = * ((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1) {
        perror("fcntl");
        exit(1);
    }

    numbytes = 0;
    while (1) {
        if ((numbytes = recv(sockfd, recvbuf, BUFFER_SIZE, MSG_DONTWAIT)) == -1) {
            if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                usleep(100000);
                continue;
            } else {
                perror("recv");
                exit(1);
            }
        } else if (numbytes == 0) {
            break;
        }

        recvbuf[numbytes] = '\0';
        printf("%s", recvbuf);
    }

    inet_ntop(AF_INET, &(their_addr.sin_addr), ipstr, INET_ADDRSTRLEN);
    printf("\n\nPort 80 is open on %s\n", ipstr);

    close(sockfd);

    return 0;
}