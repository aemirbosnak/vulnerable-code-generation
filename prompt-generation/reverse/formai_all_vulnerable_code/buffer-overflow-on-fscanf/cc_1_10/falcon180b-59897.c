//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_DEVICES 10
#define MAX_SSID_LEN 32

typedef struct {
    int sock;
    char ssid[MAX_SSID_LEN];
    int rssi;
    int channel;
} device_t;

int main() {
    device_t devices[MAX_DEVICES];
    int num_devices = 0;

    char *ifname = "wlan0";
    char cmd[100];
    sprintf(cmd, "iw dev %s scan | grep -A3 'SSID' > temp.txt", ifname);
    system(cmd);

    // Read the temp file for SSID, RSSI and channel
    FILE *fp = fopen("temp.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d %d\n", devices[num_devices].ssid, &devices[num_devices].rssi, &devices[num_devices].channel) == 3) {
        num_devices++;
        if (num_devices >= MAX_DEVICES) {
            break;
        }
    }

    fclose(fp);
    remove("temp.txt");

    printf("Number of devices found: %d\n", num_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("SSID: %s, RSSI: %d, Channel: %d\n", devices[i].ssid, devices[i].rssi, devices[i].channel);
    }

    return 0;
}