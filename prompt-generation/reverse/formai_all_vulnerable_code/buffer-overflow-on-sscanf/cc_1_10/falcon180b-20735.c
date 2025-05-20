//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_SSID_LEN 32
#define MAX_BSSID_LEN 18
#define MAX_CHANNEL_NUM 14

struct bss_info {
    char bssid[MAX_BSSID_LEN];
    int channel;
    int signal_strength;
    char ssid[MAX_SSID_LEN];
};

void print_bss_info(struct bss_info *bss) {
    printf("BSSID: %s\n", bss->bssid);
    printf("Channel: %d\n", bss->channel);
    printf("Signal Strength: %d\n", bss->signal_strength);
    printf("SSID: %s\n", bss->ssid);
}

int main(int argc, char *argv[]) {
    int sock, optval;
    struct sockaddr_in server_addr;
    char *server_ip = "localhost";
    char *server_port = "8080";
    char buffer[1024];
    struct bss_info bss_info;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(server_port));
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_received = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            break;
        }

        sscanf(buffer, "BSSID:%s CHANNEL:%d SSID:%s SIGNAL:%d", bss_info.bssid, &bss_info.channel, bss_info.ssid, &bss_info.signal_strength);
        print_bss_info(&bss_info);
    }

    close(sock);
    return 0;
}