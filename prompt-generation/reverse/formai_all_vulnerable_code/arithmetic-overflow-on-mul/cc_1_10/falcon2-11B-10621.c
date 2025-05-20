//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, valread;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char recvbuf[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(33434);

    for (int i = 0; i < 10; i++) {
        valread = sendto(sockfd, "PING ", 5, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        if (valread < 0) {
            perror("sendto");
            exit(1);
        }

        valread = recvfrom(sockfd, recvbuf, 255, 0, NULL, NULL);
        if (valread < 0) {
            perror("recvfrom");
            exit(1);
        }

        printf("%d bytes from %s: icmp_seq=%d time=%ld.%06ld ms\n", valread, inet_ntoa(servaddr.sin_addr),
                i, (long)((valread * 8) / 1000 / 1000), (long)((valread * 8) / 1000 * 1000 - ((valread * 8) / 1000 * 1000) % 1000));
    }

    printf("--- %s ping statistics ---\n", argv[1]);
    printf("10 packets transmitted, 10 packets received, 0.0% packet loss\n");

    return 0;
}