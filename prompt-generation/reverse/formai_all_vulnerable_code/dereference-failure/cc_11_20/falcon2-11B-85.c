//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_LEN 256

int main() {
    struct hostent *host;
    struct sockaddr_in addr;
    struct hostent *hp;
    int s, i, n, m;
    char buf[MAX_LEN], ip[MAX_LEN], mac[MAX_LEN], ssid[MAX_LEN];
    char hostname[MAX_LEN];
    struct addrinfo hints, *servinfo, *p;
    struct timeval timeout;
    char *scanResult = "Network Scanner";

    // Initialization
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    gettimeofday(&timeout, NULL);
    timeout.tv_sec += 5; // 5 seconds timeout

    s = getaddrinfo(NULL, "12345", &hints, &servinfo);
    if (s!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (s == -1) {
            perror("socket");
            continue;
        }

        n = 1;
        if (setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(n)) == -1) {
            perror("setsockopt");
            continue;
        }

        if (bind(s, p->ai_addr, p->ai_addrlen) == -1) {
            perror("bind");
            continue;
        }

        if (listen(s, 5) == -1) {
            perror("listen");
            continue;
        }

        for (;;) {
            memset(&addr, 0, sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = INADDR_ANY;
            addr.sin_port = htons(0);

            n = sizeof(addr);
            s = accept(s, (struct sockaddr *) &addr, &n);
            if (s == -1) {
                perror("accept");
                continue;
            }

            i = 1;
            if (getsockname(s, (struct sockaddr *) &addr, &i) == -1) {
                perror("getsockname");
                continue;
            }

            if (inet_ntop(AF_INET, &addr.sin_addr, ip, MAX_LEN) == NULL) {
                perror("inet_ntop");
                continue;
            }

            if (inet_ntop(AF_INET, &addr.sin_addr.s_addr, mac, MAX_LEN) == NULL) {
                perror("inet_ntop");
                continue;
            }

            if (getnameinfo((struct sockaddr *) &addr, i, hostname, MAX_LEN, NULL, 0, NI_NUMERICHOST) == 0) {
                if (strcmp(hostname, "Unknown")!= 0) {
                    printf("%s (%s) %s %s\n", hostname, ip, mac, scanResult);
                }
            }

            close(s);
        }
    }

    freeaddrinfo(servinfo);

    return 0;
}