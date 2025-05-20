//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main() {
    int sock, opt = 1;
    struct ifreq ifr;
    char *ifname = "wlan0";
    char buf[BUF_SIZE];
    int len, res;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error: setsockopt\n");
        return 1;
    }

    strcpy(ifr.ifr_name, ifname);
    if (ioctl(sock, SIOCGIFINDEX, &ifr)) {
        printf("Error: ioctl\n");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    inet_pton(AF_INET, "255.255.255.255", &addr.sin_addr);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr))) {
        printf("Error: bind\n");
        return 1;
    }

    while (1) {
        res = recvfrom(sock, buf, BUF_SIZE, 0, NULL, NULL);

        if (res > 0) {
            buf[res] = '\0';
            printf("%s\n", buf);
        }
    }

    return 0;
}