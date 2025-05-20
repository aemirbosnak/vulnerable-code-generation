//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

#define BUF_SIZE 1024

struct sockaddr_in server_addr;
int sockfd;

void get_wireless_info(char *ifname) {
    int sockfd;
    struct ifreq ifr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    strcpy(ifr.ifr_name, ifname);
    ioctl(sockfd, SIOCGIFHWADDR, &ifr);
    printf("MAC address: ");
    for (int i = 0; i < 6; i++) {
        printf("%02X:", (unsigned char) ifr.ifr_hwaddr.sa_data[i]);
    }
    printf("\n");

    close(sockfd);
}

void scan_wireless_networks() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[BUF_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_BROADCAST, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        printf("Waiting for wireless networks...\n");
        if (recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL) > 0) {
            printf("Received: %s\n", buffer);
        }
    }

    close(sockfd);
}

int main() {
    char ifname[IF_NAMESIZE];
    int i;

    for (i = 0; i < 10; i++) {
        sprintf(ifname, "wlan%d", i);
        get_wireless_info(ifname);
    }

    scan_wireless_networks();

    return 0;
}