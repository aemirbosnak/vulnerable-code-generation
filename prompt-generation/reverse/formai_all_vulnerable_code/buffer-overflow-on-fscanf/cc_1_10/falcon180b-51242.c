//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SSID_LEN 32
#define MAX_BSSID_LEN 18
#define MAX_CHANNEL_LEN 4
#define MAX_SECURITY_LEN 16
#define MAX_RSSI_LEN 6

typedef struct {
    char ssid[MAX_SSID_LEN];
    char bssid[MAX_BSSID_LEN];
    char channel[MAX_CHANNEL_LEN];
    char security[MAX_SECURITY_LEN];
    int rssi;
} access_point_t;

void print_access_point(access_point_t *ap) {
    printf("SSID: %s\n", ap->ssid);
    printf("BSSID: %s\n", ap->bssid);
    printf("Channel: %s\n", ap->channel);
    printf("Security: %s\n", ap->security);
    printf("RSSI: %d\n\n", ap->rssi);
}

int main() {
    char *ssid;
    char *bssid;
    char *channel;
    char *security;
    int rssi;
    access_point_t ap;
    FILE *fp;

    fp = popen("iwlist wlan0 scan", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        return 1;
    }

    while (fscanf(fp, "Cell %02X - Address: %s\n", &rssi, bssid) == 2) {
        if (rssi > 0) {
            fscanf(fp, "ESSID:\"%[^\"]\"\n", ssid);
            fscanf(fp, "IE: WPA Version 1\n");
            fscanf(fp, "IE: WPA2 Version 1\n");
            fscanf(fp, "IE: Unknown: %[^\n]\n", security);
            fscanf(fp, "Freq: %s\n", channel);

            strncpy(ap.ssid, ssid, MAX_SSID_LEN);
            strncpy(ap.bssid, bssid, MAX_BSSID_LEN);
            strncpy(ap.channel, channel, MAX_CHANNEL_LEN);
            strncpy(ap.security, security, MAX_SECURITY_LEN);
            ap.rssi = rssi;

            print_access_point(&ap);
        }
    }

    pclose(fp);

    return 0;
}