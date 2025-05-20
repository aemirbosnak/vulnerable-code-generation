//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_SSID_LENGTH 32

struct wireless_info {
    int freq;
    int signal;
    char ssid[MAX_SSID_LENGTH];
};

int main() {
    int sock, i;
    struct iwreq wrq;
    struct wireless_info *info = NULL;
    char ifname[IF_NAMESIZE];

    printf("Enter the interface name: ");
    scanf("%s", ifname);

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    strncpy(wrq.ifr_name, ifname, IFNAMSIZ);
    if (ioctl(sock, SIOCGIWNAME, &wrq) < 0) {
        perror("ioctl");
        exit(1);
    }

    info = malloc(sizeof(struct wireless_info));
    if (info == NULL) {
        perror("malloc");
        exit(1);
    }

    for (i = 0; i < 100; i++) {
        memset(&wrq, 0, sizeof(wrq));
        strncpy(wrq.ifr_name, ifname, IFNAMSIZ);
        snprintf(wrq.u.essid.pointer, "%d", i);
        if (ioctl(sock, SIOCGIWNWID, &wrq) < 0) {
            perror("ioctl");
            exit(1);
        }

        info->freq = wrq.u.freq.m;
        info->signal = wrq.u.ap_addr.sa_data[2];
        strncpy(info->ssid, wrq.u.essid.pointer, MAX_SSID_LENGTH);
        printf("SSID: %s\nFrequency: %d MHz\nSignal Strength: %d dBm\n", info->ssid, info->freq, info->signal);
    }

    free(info);
    close(sock);

    return 0;
}