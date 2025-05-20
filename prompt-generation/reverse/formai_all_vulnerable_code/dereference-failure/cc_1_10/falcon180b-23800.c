//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <SSID>\n", argv[0]);
        return 1;
    }

    char ssid[33];
    strncpy(ssid, argv[1], 32);
    ssid[32] = '\0';

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in si_other;
    memset(&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(9);
    inet_pton(AF_INET, "255.255.255.255", &si_other.sin_addr);

    char buffer[BUFFER_SIZE];
    while (1) {
        int len = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (len <= 0) {
            break;
        }

        char *pos = strstr(buffer, ssid);
        if (pos!= NULL) {
            int rssi = atoi(pos + strlen(ssid) + 1);
            printf("SSID: %s, RSSI: %d\n", ssid, rssi);
        }
    }

    close(sock);
    return 0;
}