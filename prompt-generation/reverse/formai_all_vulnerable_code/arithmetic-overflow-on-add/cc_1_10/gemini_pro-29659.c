//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port1> <port2>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port1 = atoi(argv[2]);
    int port2 = atoi(argv[3]);

    struct timeval start, end;
    long long timediff;

    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        printf("Could not resolve hostname %s\n", hostname);
        return 1;
    }

    for (int port = port1; port <= port2; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Could not create socket\n");
            return 1;
        }

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = *(struct in_addr *)host->h_addr;

        int rc = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

        if (rc == 0) {
            printf("Port %d is open\n", port);
            close(sockfd);
        }

        gettimeofday(&end, NULL);
        timediff = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

        if (timediff > 1000000) {
            printf("Port %d is closed\n", port);
            close(sockfd);
        }
    }

    printf("Scan complete\n");

    return 0;
}