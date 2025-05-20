//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    struct hostent* host = gethostbyname(argv[1]);

    if (host == NULL) {
        printf("Unable to resolve host %s\n", argv[1]);
        return 1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(0);  // pick any available port
    servaddr.sin_addr = *((struct in_addr*) host->h_addr_list[0]);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0) {
        printf("Unable to create socket\n");
        return 1;
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*) &timeout, sizeof(timeout)) < 0) {
        printf("Unable to set socket options\n");
        return 1;
    }

    printf("Pinging %s [%s] with 32 bytes of data:\n", host->h_name, inet_ntoa(servaddr.sin_addr));

    int seqno;
    for (seqno = 0; seqno < 4; seqno++) {
        char msg[32];
        snprintf(msg, sizeof(msg), "Ping request %d", seqno);

        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);

        if (sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
            printf("Unable to send ping request\n");
            continue;
        }

        char buf[1024];
        struct sockaddr_in recvaddr;
        socklen_t recvlen = sizeof(recvaddr);

        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*) &recvaddr, &recvlen) < 0) {
            printf("Request timed out\n");
            continue;
        }

        struct timeval tv_end;
        gettimeofday(&tv_end, NULL);

        double rtt = (double) (tv_end.tv_sec - tv_start.tv_sec) * 1000.0 + (double) (tv_end.tv_usec - tv_start.tv_usec) / 1000.0;

        char sender[1024];
        inet_ntop(AF_INET, &recvaddr.sin_addr, sender, sizeof(sender));

        printf("Reply from %s: bytes=32 time=%.2fms\n", sender, rtt);
    }

    return 0;
}