//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
    // What's this sorcery?
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Let's find the network interfaces like a boss!
    struct ifreq *ifr;
    struct ifconf ifc;
    char ifname[IFNAMSIZ];
    int num_ifcs;

    ifc.ifc_len = sizeof(ifc);
    ifc.ifc_buf = malloc(ifc.ifc_len);
    if (ioctl(sockfd, SIOCGIFCONF, &ifc) == -1) {
        perror("ioctl() failed");
        close(sockfd);
        exit(1);
    }

    // Hold your horses, we've got a whole herd of interfaces!
    num_ifcs = ifc.ifc_len / sizeof(struct ifreq);
    ifr = (struct ifreq *)ifc.ifc_buf;
    for (int i = 0; i < num_ifcs; i++) {
        // What's this? An interface? And it's wireless? Wow!
        if (ifr->ifr_addr.sa_family == AF_INET &&
            !(ifr->ifr_flags & IFF_LOOPBACK) &&
            (ifr->ifr_flags & IFF_UP) &&
            (ifr->ifr_flags & IFF_RUNNING) &&
            (ifr->ifr_flags & IFF_POINTOPOINT) == 0) {
            strcpy(ifname, ifr->ifr_name);
            break;
        }
        ifr++;
    }

    // Got the wireless interface? Let's not chicken out now!
    if (strlen(ifname) == 0) {
        printf("Couldn't find a wireless interface. Bummer!\n");
        close(sockfd);
        exit(1);
    }

    // Time to broadcast some magic packets like a wizard!
    char broadcast_addr[] = "255.255.255.255";
    struct sockaddr_in broadcast_sockaddr;
    memset(&broadcast_sockaddr, 0, sizeof(broadcast_sockaddr));
    broadcast_sockaddr.sin_family = AF_INET;
    broadcast_sockaddr.sin_addr.s_addr = inet_addr(broadcast_addr);
    broadcast_sockaddr.sin_port = htons(65535);

    // Let's start the wireless network scanner like a pro!
    printf("Scanning wireless networks on interface %s...\n", ifname);
    char recvbuf[1024];
    int recvbuf_len = sizeof(recvbuf);
    char ssid[33];
    char mac[18];
    char channel[5];
    int signal_strength;
    int num_networks = 0;
    while (1) {
        // Send the magic packets like a boss!
        char magic_packet[] = "\xFF\xFF\xFF\xFF\xFF\xFF";
        sendto(sockfd, magic_packet, sizeof(magic_packet), 0, (struct sockaddr *)&broadcast_sockaddr, sizeof(broadcast_sockaddr));

        // Wait for the wireless networks to respond like they mean it!
        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = 250000;
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        int nfds = select(sockfd + 1, &readfds, NULL, NULL, &tv);
        if (nfds == -1) {
            perror("Select failed");
            close(sockfd);
            exit(1);
        } else if (nfds == 0) {
            continue;
        }

        // Got a response? Let's decode the magic and see what we've found!
        recvfrom(sockfd, recvbuf, recvbuf_len, 0, NULL, NULL);
        if (recvbuf[0] == 0x51 && recvbuf[1] == 0x6F && recvbuf[2] == 0x6E && recvbuf[3] == 0x61) {
            // Parse the SSID, MAC address, channel and signal strength like a superhero!
            memcpy(ssid, recvbuf + 32, 32);
            ssid[32] = '\0';
            memcpy(mac, recvbuf + 44, 12);
            mac[12] = ':';
            mac[13] = recvbuf[56];
            mac[14] = ':';
            mac[15] = recvbuf[57];
            mac[16] = ':';
            mac[17] = recvbuf[58];
            mac[18] = '\0';
            sprintf(channel, "%d", recvbuf[60]);
            signal_strength = recvbuf[61] - 256;

            // Display the network information like a champ!
            printf("Network %d:\n", ++num_networks);
            printf("  SSID: %s\n", ssid);
            printf("  MAC Address: %s\n", mac);
            printf("  Channel: %s\n", channel);
            printf("  Signal Strength: %d%%\n", signal_strength);
            printf("\n");
        }
    }

    // We're done! Time to clean up like a boss.
    close(sockfd);
    free(ifc.ifc_buf);
    return 0;
}