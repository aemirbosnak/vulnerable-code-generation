//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <net/if.h>
#include <linux/wireless.h>

#define MAX_SSID_LEN 32
#define MAX_BSSID_LEN 18
#define MAX_BSSID_COUNT 100

struct bss_info {
    char bssid[MAX_BSSID_LEN];
    int signal;
    int freq;
    int flags;
};

int main(int argc, char *argv[]) {
    int sock, ret;
    struct iwreq iwr;
    char ifname[IF_NAMESIZE];
    struct bss_info *bss_list;
    int bss_count;

    if (argc < 2) {
        printf("Usage: %s interface\n", argv[0]);
        exit(1);
    }

    strcpy(ifname, argv[1]);

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&iwr, 0, sizeof(iwr));
    strncpy(iwr.ifr_name, ifname, IFNAMSIZ);
    iwr.u.data.pointer = NULL;
    iwr.u.data.length = 0;

    if (ioctl(sock, SIOCGIWSCAN, &iwr) < 0) {
        printf("Error getting scan data\n");
        exit(1);
    }

    bss_list = iwr.u.data.pointer;
    bss_count = iwr.u.data.length / sizeof(struct iw_quality);

    printf("SSID\tBSSID\tSignal\tFrequency\tFlags\n");
    for (int i = 0; i < bss_count; i++) {
        printf("%-15s", bss_list[i].bssid);
        printf("%-18s", bss_list[i].bssid);
        printf("%d\t", bss_list[i].signal);
        printf("%d\t", bss_list[i].freq);
        printf("%d\n", bss_list[i].flags);
    }

    close(sock);

    return 0;
}