//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>

/* Struct used to store information about a wireless network */
typedef struct {
    char ssid[32];
    char bssid[18];
    int signal_strength;
    int channel;
} wireless_network;

int main() {

    /* Get list of network interfaces */
    struct ifaddrs *ifaddr;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    /* Loop through each interface */
    for (struct ifaddrs *ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {

        /* Only consider wireless interfaces */
        if (ifa->ifa_addr->sa_family == AF_PACKET && strstr(ifa->ifa_name, "wlan") != '\0') {

            printf("Scanning %s...\n", ifa->ifa_name);

            /* Create socket */
            int s = socket(AF_INET, SOCK_DGRAM, 0);
            if (s < 0) {
                perror("socket");
                continue;
            }

            /* Bind socket to interface */
            if (setsockopt(s, SOL_SOCKET, SO_BINDTODEVICE, ifa->ifa_name, strlen(ifa->ifa_name)) < 0) {
                perror("setsockopt");
                close(s);
                continue;
            }

            /* Send scan request */
            struct sockaddr_in sin;
            sin.sin_family = AF_INET;
            sin.sin_port = htons(0);
            sin.sin_addr.s_addr = htonl(INADDR_ANY);
            if (sendto(s, "SCAN", 4, 0, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
                perror("sendto");
                close(s);
                continue;
            }

            /* Receive scan response */
            char buf[1024];
            ssize_t len;
            if ((len = recv(s, buf, sizeof(buf), 0)) < 0) {
                perror("recv");
                close(s);
                continue;
            }

            /* Parse scan response */
            int num_networks = (len - 4) / 37;
            wireless_network *networks = malloc(num_networks * sizeof(wireless_network));
            for (int i = 0; i < num_networks; i++) {
                strncpy(networks[i].ssid, buf + 4 + i * 37, 32);
                strncpy(networks[i].bssid, buf + 36 + i * 37, 18);
                networks[i].signal_strength = (int)((unsigned char)buf[34 + i * 37] - 256);
                networks[i].channel = (int)((unsigned char)buf[3 + i * 37]);
            }

            /* Print scan results */
            printf("Found %d networks:\n", num_networks);
            for (int i = 0; i < num_networks; i++) {
                printf("  SSID: %s\n", networks[i].ssid);
                printf("  BSSID: %s\n", networks[i].bssid);
                printf("  Signal Strength: %d dBm\n", networks[i].signal_strength);
                printf("  Channel: %d\n", networks[i].channel);
            }

            /* Clean up */
            free(networks);
            close(s);

        }

    }

    /* Free memory allocated by getifaddrs */
    freeifaddrs(ifaddr);

    return 0;

}