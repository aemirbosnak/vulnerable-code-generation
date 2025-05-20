//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>

#define MAX_INTERFACE_NAME_LEN 16

int main(int argc, char *argv[]) {
    int sfd;
    struct ifreq ifr;
    char interface_name[MAX_INTERFACE_NAME_LEN];
    struct sockaddr_in *sin;
    unsigned char *macaddr;
    unsigned int ipaddr;
    unsigned short port;
    unsigned int netmask;
    int i;
    unsigned char *p;
    unsigned char *buf;
    int buflen;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <interface_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(interface_name, argv[1], MAX_INTERFACE_NAME_LEN);
    interface_name[MAX_INTERFACE_NAME_LEN-1] = '\0';

    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sfd == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    strncpy(ifr.ifr_name, interface_name, IFNAMSIZ-1);
    ifr.ifr_name[IFNAMSIZ-1] = '\0';

    /* Get interface MAC address */
    if (ioctl(sfd, SIOCGIFHWADDR, &ifr) == -1) {
        perror("ioctl SIOCGIFHWADDR error");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    macaddr = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    printf("MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           macaddr[0], macaddr[1], macaddr[2], macaddr[3], macaddr[4], macaddr[5]);

    /* Get interface IP address and netmask */
    if (ioctl(sfd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl SIOCGIFADDR error");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    sin = (struct sockaddr_in *)&ifr.ifr_addr;
    ipaddr = sin->sin_addr.s_addr;
    printf("IP address: %s\n", inet_ntoa(sin->sin_addr));

    if (ioctl(sfd, SIOCGIFNETMASK, &ifr) == -1) {
        perror("ioctl SIOCGIFNETMASK error");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    sin = (struct sockaddr_in *)&ifr.ifr_netmask;
    netmask = sin->sin_addr.s_addr;
    printf("Netmask: %s\n", inet_ntoa(sin->sin_addr));

    /* Get interface MTU */
    if (ioctl(sfd, SIOCGIFMTU, &ifr) == -1) {
        perror("ioctl SIOCGIFMTU error");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    printf("MTU: %d\n", ifr.ifr_mtu);

    /* Get interface broadcast address */
    if (ioctl(sfd, SIOCGIFBRDADDR, &ifr) == -1) {
        perror("ioctl SIOCGIFBRDADDR error");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    sin = (struct sockaddr_in *)&ifr.ifr_addr;
    printf("Broadcast address: %s\n", inet_ntoa(sin->sin_addr));

    /* Get interface flags */
    if (ioctl(sfd, SIOCGIFFLAGS, &ifr) == -1) {
        perror("ioctl SIOCGIFFLAGS error");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    printf("Flags: ");
    if (ifr.ifr_flags & IFF_UP) {
        printf("UP ");
    }
    if (ifr.ifr_flags & IFF_BROADCAST) {
        printf("BROADCAST ");
    }
    if (ifr.ifr_flags & IFF_RUNNING) {
        printf("RUNNING ");
    }
    if (ifr.ifr_flags & IFF_PROMISC) {
        printf("PROMISC ");
    }
    if (ifr.ifr_flags & IFF_MULTICAST) {
        printf("MULTICAST ");
    }
    printf("\n");

    /* Scan for wireless networks */
    printf("Scanning for wireless networks...\n");

    /* Prepare request command buffer */
    buflen = 1024;
    buf = (unsigned char *)malloc(buflen);
    if (buf == NULL) {
        perror("malloc error");
        close(sfd);
        exit(EXIT_FAILURE);
    }

    p = buf;
    *(unsigned short *)p = htons(0x0101); /* Magic */
    p += 2;
    *(unsigned short *)p = htons(0x0000); /* Payload length */
    p += 2;
    *(unsigned char *)p = 0x00; /* Payload ID */
    p += 1;
    *(unsigned char *)p = 0x00; /* Payload version */
    p += 1;
    for (i = 0; i < 6; i++) {
        *(p+i) = macaddr[i];
    }
    p += 6;

    /* Send request command */
    sin = (struct sockaddr_in *)&ifr.ifr_addr;
    sin->sin_addr.s_addr |= ~netmask; /* Broadcast address */
    port = htons(5581);
    sin->sin_port = port;
    if (sendto(sfd, buf, p-buf, 0, (struct sockaddr *)sin, sizeof(struct sockaddr_in)) == -1) {
        perror("sendto error");
        free(buf);
        close(sfd);
        exit(EXIT_FAILURE);
    }

    free(buf);
    close(sfd);
    return 0;
}