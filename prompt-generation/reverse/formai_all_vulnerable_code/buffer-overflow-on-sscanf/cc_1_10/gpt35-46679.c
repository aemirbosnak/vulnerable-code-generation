//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>
#include <arpa/inet.h>

#define MAX_INTERFACE_NAME_LEN 16
#define MAX_WIFI_NAME_LEN 32

struct wifi_data {
    char name[MAX_WIFI_NAME_LEN];
    int signal_strength;
};

void get_wifi_signal_strength(const char* ifname, struct wifi_data* data) {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct iwreq req;
    strncpy(req.ifr_name, ifname, IFNAMSIZ);
    req.u.essid.flags = 0;
    if (ioctl(sockfd, SIOCGIWESSID, &req) != -1) {
        strncpy(data->name, req.u.essid.pointer, MAX_WIFI_NAME_LEN);
    }
    if (ioctl(sockfd, SIOCGIWSENS, &req) != -1) {
        data->signal_strength = (req.u.sens.value * 100) / 0x7FFF;
    }
    close(sockfd);
}

int main() {
    FILE* fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/net/wireless");
        return 1;
    }
    char buffer[2048];
    fgets(buffer, sizeof(buffer), fp);    // skip first line
    printf("%-16s %s\n", "Interface", "Signal Strength (%%)");
    printf("----------------------------------------------\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char ifname[MAX_INTERFACE_NAME_LEN];
        float signal_strength;
        if (sscanf(buffer, "%[^:]:  %f", ifname, &signal_strength) == 2) {
            struct wifi_data data;
            get_wifi_signal_strength(ifname, &data);
            printf("%-16s %d\n", ifname, data.signal_strength);
        }
    }
    fclose(fp);
    return 0;
}