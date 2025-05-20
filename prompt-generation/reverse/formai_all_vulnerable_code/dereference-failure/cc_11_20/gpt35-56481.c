//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>

#define SCAN_TIMEOUT 5
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [interface_name]\n", argv[0]);
        return 1;
    }
    
    char *interface_name = argv[1];
    
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct ifreq ifq;
    strncpy(ifq.ifr_name, interface_name, IFNAMSIZ);
    if(ioctl(sockfd, SIOCGIFHWADDR, (char *)&ifq) < 0) {
        perror("ioctl");
        return 1;
    }

    printf("Scanning wireless network for %s...\n", interface_name);
    printf("--------------------------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-20s\n", "Access Point Name", "MAC Address", "Signal Strength (dBm)");
    printf("--------------------------------------------------------------------------------------------\n");

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status;
    if ((status = getaddrinfo(interface_name, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    struct sockaddr_in *if_addr = (struct sockaddr_in*) res->ai_addr;

    u_int8_t bssid[6];
    memcpy(bssid, ifq.ifr_hwaddr.sa_data, sizeof bssid);

    char *buf = malloc(MAX_BUFFER_SIZE);
    if (!buf) {
        perror("malloc");
        return 1;
    }

    int sockoptval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &sockoptval, sizeof sockoptval);

    struct timeval tv;
    tv.tv_sec = SCAN_TIMEOUT;
    tv.tv_usec = 0;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int max_sd = sockfd;

    for (int i = 1; i <= 11; i++) {
        char ssid[20];
        snprintf(ssid, sizeof ssid, "Wave-%02d-VIT", i);

        snprintf(buf, MAX_BUFFER_SIZE, "80:2a:a8:%02x:%02x:%02x", bssid[3], bssid[4], ((i << 2) + bssid[5]));
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(5353);
        addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
        bzero(addr.sin_zero, sizeof addr.sin_zero);

        int nbytes_sent = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof addr);
        if (nbytes_sent < 0) {
            perror("sendto");
        } else {
            printf("%-20s ", ssid);

            tv.tv_sec = SCAN_TIMEOUT;
            tv.tv_usec = 0;

            int retval = select(max_sd + 1, &readfds, NULL, NULL, &tv);
            if (retval < 0) {
                perror("select");
                continue;
            }

            if (retval == 0) {
                printf("%-20s\n", "No response");
            } else {
                if (FD_ISSET(sockfd, &readfds)) {
                    struct sockaddr_in addr;
                    socklen_t addr_len = sizeof addr;

                    ssize_t nbytes_recv = recvfrom(sockfd, buf, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&addr, &addr_len);
                    if (nbytes_recv < 0) {
                        perror("recvfrom");
                        printf("%-20s\n", "Error");
                    } else {
                        char mac[18];
                        snprintf(mac, sizeof mac, "%02x:%02x:%02x:%02x:%02x:%02x", bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5]);
                        printf("%-20s %-20s %-20s\n", ssid, mac, buf);
                    }
                }
            }
        }
    }

    freeaddrinfo(res);
    free(buf);

    close(sockfd);

    return 0;
}