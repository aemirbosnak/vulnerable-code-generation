//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18
#define MAX_CHANNEL_LENGTH 10
#define MAX_ESSID_LENGTH 32

struct bss_info {
    char bssid[MAX_BSSID_LENGTH];
    char essid[MAX_ESSID_LENGTH];
    int signal;
    int channel;
};

void print_bss_info(struct bss_info *info) {
    printf("BSSID: %s\n", info->bssid);
    printf("ESSID: %s\n", info->essid);
    printf("Signal: %d\n", info->signal);
    printf("Channel: %d\n\n", info->channel);
}

int main(int argc, char *argv[]) {
    int sock, i, j, count;
    struct ifreq ifr;
    struct iwreq wrq;
    struct sockaddr_in sa;
    struct bss_info bss_info[10];

    if (argc!= 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    strcpy(ifr.ifr_name, argv[1]);
    if (ioctl(sock, SIOCGIFINDEX, &ifr) < 0) {
        printf("Error getting interface index\n");
        return 1;
    }

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("255.255.255.255");
    sa.sin_port = htons(0);

    for (i = 0; i < 10; i++) {
        memset(&wrq, 0, sizeof(wrq));
        wrq.u.data.pointer = (caddr_t)&bss_info[i];
        wrq.u.data.length = sizeof(bss_info[i]);
        wrq.u.data.flags = 0;

        if (ioctl(sock, SIOCGIWSCAN, &wrq) < 0) {
            printf("Error getting wireless scan\n");
            return 1;
        }

        if (bss_info[i].essid[0] == '\0') {
            continue;
        }

        printf("BSS %d:\n", i+1);
        print_bss_info(&bss_info[i]);
    }

    close(sock);
    return 0;
}