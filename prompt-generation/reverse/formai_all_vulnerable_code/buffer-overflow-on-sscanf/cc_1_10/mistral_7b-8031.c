//MISTRAL-7B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_AP_NUM 10
#define SSID_LEN 32
#define BUF_LEN 1024

struct wifi_data {
    char ssid[SSID_LEN];
    int rssi;
};

int main(int argc, char *argv[]) {
    int sockfd, i, j, len;
    char buf[BUF_LEN];
    struct ifreq ifr;
    struct sockaddr_in serv_addr;
    struct wifi_data wifi_list[MAX_AP_NUM];
    int ap_num = 0;

    memset(wifi_list, 0, sizeof(wifi_list));

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(ifr.ifr_name, "wlan0");
    if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0) {
        perror("Unable to get wlan0 index");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(69);
    serv_addr.sin_addr.s_addr = INADDR_BROADCAST;

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Unable to bind to port");
        exit(EXIT_FAILURE);
    }

    while (1) {
        len = sizeof(buf);
        if (recvfrom(sockfd, buf, BUF_LEN, 0, NULL, NULL) <= 0) {
            perror("Unable to receive data");
            continue;
        }

        if (strstr(buf, "SSID:") && ap_num < MAX_AP_NUM) {
            sscanf(buf, "SSID:%s RSSI:%d", wifi_list[ap_num].ssid, &wifi_list[ap_num].rssi);
            ap_num++;
        }
    }

    close(sockfd);

    printf("Scan Results:\n");
    for (i = 0; i < ap_num; i++) {
        printf("SSID: %s RSSI: %d\n", wifi_list[i].ssid, wifi_list[i].rssi);
    }

    return EXIT_SUCCESS;
}