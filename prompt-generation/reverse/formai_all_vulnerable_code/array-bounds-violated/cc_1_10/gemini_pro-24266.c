//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <linux/wireless.h>

#define MAX_ESSIDS      32

struct essid_info {
    char    essid[33];
    int     channel;
} essid_info_list[MAX_ESSIDS];

int main(int argc, char *argv[])
{
    int sock, i, j;
    struct iwreq req;

    // Create a socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the list of interfaces
    struct ifreq *ifr_list;
    int num_ifaces = 0;
    ifr_list = malloc(sizeof(struct ifreq) * 10);
    if (!ifr_list) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    for (i = 0; ; i++) {
        snprintf(ifr_list[i].ifr_name, sizeof(ifr_list[i].ifr_name), "wlan%d", i);
        if (ioctl(sock, SIOCGIFFLAGS, &ifr_list[i]) < 0) {
            break;
        }
        num_ifaces++;
    }

    // Get the ESSIDs for each interface
    int num_essids = 0;
    for (i = 0; i < num_ifaces; i++) {
        req.u.essid.pointer = essid_info_list[num_essids].essid;
        req.u.essid.length = sizeof(essid_info_list[num_essids].essid);
        if (ioctl(sock, SIOCGIWESSID, &req) < 0) {
            perror("ioctl");
            continue;
        }
        essid_info_list[num_essids].essid[req.u.essid.length] = '\0';
        if (req.u.essid.length > 0) {
            req.u.freq.e = 0;
            if (ioctl(sock, SIOCGIWFREQ, &req) < 0) {
                perror("ioctl");
                continue;
            }
            essid_info_list[num_essids].channel = req.u.freq.m / 1000000;
            num_essids++;
        }
    }

    // Print the list of ESSIDs
    printf("Available ESSIDs:\n");
    for (i = 0; i < num_essids; i++) {
        printf("  %s (channel %d)\n", essid_info_list[i].essid, essid_info_list[i].channel);
    }

    // Clean up
    free(ifr_list);
    close(sock);

    return EXIT_SUCCESS;
}