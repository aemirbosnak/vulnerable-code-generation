//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <linux/if_tun.h>
#include <linux/if_packet.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_PKT 4096

int main() {
    int s, i;
    struct ifreq ifr;
    char pkt[MAX_PKT];
    struct sockaddr_ll local, remote;
    struct ifreq ifr_tun;

    s = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (s == -1) {
        perror("socket");
        return 1;
    }

    memset(&local, 0, sizeof(local));
    local.sll_family = PF_PACKET;
    local.sll_protocol = htons(ETH_P_ALL);
    local.sll_ifindex = 0; // or any other interface index you want to use
    local.sll_halen = 6;
    local.sll_addr[0] = 0xff;
    local.sll_addr[1] = 0xff;
    local.sll_addr[2] = 0xff;
    local.sll_addr[3] = 0xff;
    local.sll_addr[4] = 0xff;
    local.sll_addr[5] = 0xff;

    memset(&remote, 0, sizeof(remote));
    remote.sll_family = PF_PACKET;
    remote.sll_protocol = htons(ETH_P_ALL);
    remote.sll_ifindex = 0; // or any other interface index you want to use
    remote.sll_halen = 6;
    remote.sll_addr[0] = 0xff;
    remote.sll_addr[1] = 0xff;
    remote.sll_addr[2] = 0xff;
    remote.sll_addr[3] = 0xff;
    remote.sll_addr[4] = 0xff;
    remote.sll_addr[5] = 0xff;

    if (ioctl(s, SIOCGIFINDEX, &local) < 0) {
        perror("SIOCGIFINDEX");
        return 1;
    }

    if (ioctl(s, SIOCGIFNAME, &local) < 0) {
        perror("SIOCGIFNAME");
        return 1;
    }

    if (ioctl(s, SIOCGIFHWADDR, &local) < 0) {
        perror("SIOCGIFHWADDR");
        return 1;
    }

    strcpy(ifr_tun.ifr_name, ifr.ifr_name);
    strcpy(ifr_tun.ifr_name, "tun0");
    if (ioctl(s, SIOCGIFINDEX, &ifr_tun) < 0) {
        perror("SIOCGIFINDEX");
        return 1;
    }

    if (ioctl(s, SIOCGIFNAME, &ifr_tun) < 0) {
        perror("SIOCGIFNAME");
        return 1;
    }

    if (ioctl(s, SIOCGIFHWADDR, &ifr_tun) < 0) {
        perror("SIOCGIFHWADDR");
        return 1;
    }

    if (ioctl(s, SIOCGIFFLAGS, &ifr) < 0) {
        perror("SIOCGIFFLAGS");
        return 1;
    }

    if ((ifr.ifr_flags & IFF_UP) == 0) {
        if (ioctl(s, SIOCSIFFLAGS, &ifr) < 0) {
            perror("SIOCSIFFLAGS");
            return 1;
        }
    }

    printf("Interface: %s\n", ifr.ifr_name);
    printf("MAC address: ");
    for (i = 0; i < 6; i++) {
        printf("%02x: ", ifr.ifr_hwaddr.sa_data[i]);
    }
    printf("\n");

    if (ioctl(s, SIOCGIFINDEX, &remote) < 0) {
        perror("SIOCGIFINDEX");
        return 1;
    }

    if (ioctl(s, SIOCGIFNAME, &remote) < 0) {
        perror("SIOCGIFNAME");
        return 1;
    }

    if (ioctl(s, SIOCGIFHWADDR, &remote) < 0) {
        perror("SIOCGIFHWADDR");
        return 1;
    }

    printf("Remote interface: %s\n", remote.sll_ifindex);

    while (1) {
        if (read(s, pkt, MAX_PKT) < 0) {
            perror("read");
            break;
        }

        printf("Packet: ");
        for (i = 0; i < read(s, pkt, MAX_PKT); i++) {
            printf("%02x ", pkt[i]);
        }
        printf("\n");
    }

    close(s);
    return 0;
}