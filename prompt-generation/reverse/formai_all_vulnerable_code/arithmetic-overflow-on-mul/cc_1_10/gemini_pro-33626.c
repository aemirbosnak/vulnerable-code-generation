//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>

#define PING_SIZE 56
#define PING_TIMEOUT 1

typedef struct {
    struct sockaddr_in addr;
    int seq;
    time_t time;
} ping_t;

int sockfd;
struct sockaddr_in servaddr;

void sigalrm(int signo) {
    printf("Request timed out.\n");
    close(sockfd);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    // Create a raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set the IP address of the target
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    // Set up the alarm signal
    signal(SIGALRM, sigalrm);

    // Send a ping request
    ping_t ping;
    memset(&ping, 0, sizeof(ping));
    ping.addr = servaddr;
    ping.seq = 1;
    ping.time = time(NULL);
    sendto(sockfd, &ping, sizeof(ping), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Wait for a response
    fd_set rfds;
    struct timeval tv;
    while (1) {
        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);
        tv.tv_sec = PING_TIMEOUT;
        tv.tv_usec = 0;
        int retval = select(sockfd + 1, &rfds, NULL, NULL, &tv);
        if (retval == -1) {
            perror("select");
            return 1;
        } else if (retval == 0) {
            printf("Request timed out.\n");
            break;
        } else if (FD_ISSET(sockfd, &rfds)) {
            recvfrom(sockfd, &ping, sizeof(ping), 0, NULL, NULL);
            time_t now = time(NULL);
            printf("Reply from %s: bytes=%d time=%ldms\n", inet_ntoa(ping.addr.sin_addr), PING_SIZE, (now - ping.time) * 1000);
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}