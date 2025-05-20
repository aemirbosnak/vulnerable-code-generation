//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 6

struct wireless_info {
    int signal_strength;
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
};

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0x8888);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    struct wireless_info wlan_info;
    memset(&wlan_info, 0, sizeof(wlan_info));

    int ioctl_result = ioctl(sock, SIOCGIWAP, &wlan_info);
    if (ioctl_result == -1) {
        fprintf(stderr, "Error getting wireless info: %s\n", strerror(errno));
        return 1;
    }

    printf("SSID: %s\n", wlan_info.ssid);
    printf("BSSID: %s\n", wlan_info.bssid);
    printf("Signal Strength: %d\n", wlan_info.signal_strength);

    close(sock);
    return 0;
}