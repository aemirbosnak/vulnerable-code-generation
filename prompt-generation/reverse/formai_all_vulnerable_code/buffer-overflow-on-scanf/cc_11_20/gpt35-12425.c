//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Claude Shannon
/*
Wireless Network Scanner
By: Claude Shannon

This program scans for all available wireless networks within range and displays their names and signal strengths.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/wireless.h>

int main() {
    int sock;
    char interface[10];
    struct iwreq request;
    struct iw_scan_req scanRequest;
    char scanBuffer[4096];
    char *ptr;
    int i;
    int hasSSID = 0;
    int hasSignal = 0;

    printf("Enter the wireless interface to use: ");
    scanf("%s", interface);

    // Open socket for communication with wireless interface
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Get wireless interface name
    strncpy(request.ifr_name, interface, IFNAMSIZ);

    // Scan for available networks
    memset(&scanRequest, 0, sizeof(scanRequest));
    request.u.data.pointer = &scanRequest;
    request.u.data.length = sizeof(scanRequest);
    request.u.data.flags = 0;
    if (ioctl(sock, SIOCSIWSCAN, &request) == -1) {
        perror("ioctl");
        exit(1);
    }

    // Retrieve scan results
    ptr = scanBuffer;
    if (ioctl(sock, SIOCGIWSCAN, &request) == -1) {
        perror("ioctl");
        exit(1);
    }
    memcpy(ptr, request.u.data.pointer, request.u.data.length);
    ptr += request.u.data.length;

    // Parse scan results and display network information
    printf("Wireless networks found:\n");
    for (i = 0; i < 4096; i += sizeof(struct iw_event)) {
        struct iw_event *event = (struct iw_event *)&scanBuffer[i];
        if (event->cmd == SIOCGIWAP) {
            // An access point was found
            struct sockaddr *ap = (struct sockaddr *)&event->u.ap_addr;
            if (hasSSID && hasSignal) {
                printf("\n");
                hasSSID = 0;
                hasSignal = 0;
            }
            printf("Access point: ");
            for (i = 0; i < 6; i++) {
                printf("%02X%s", ap->sa_data[i] & 0xFF, (i == 5) ? "\n" : ":");
            }
        } else if (event->cmd == SIOCGIWESSID) {
            // An SSID was found
            if (hasSSID) {
                printf("\n");
            }
            printf("SSID: ");
            ptr = event->u.essid.pointer;
            for (i = 0; i < event->u.essid.length; i++) {
                printf("%c", *ptr++);
            }
            hasSSID = 1;
        } else if (event->cmd == SIOCGIWRANGE) {
            // Signal range information
            struct iw_range *range = (struct iw_range *)&event->u.data;
            printf("\nSignal Strength: %d dBm\n", range->max_qual.qual);
            hasSignal = 1;
        }
    }

    // Close socket
    close(sock);

    return 0;
}