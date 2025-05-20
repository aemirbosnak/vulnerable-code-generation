//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define MAX_BSSID_LEN 18
#define MAX_SIGNAL_STRENGTH 100

struct {
    char ssid[MAX_SSID_LEN];
    char bssid[MAX_BSSID_LEN];
    int signal_strength;
} wifi_network;

void read_wifi_network() {
    FILE *file = fopen("wifi.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fscanf(file, "%s %s %d", wifi_network.ssid, wifi_network.bssid, &wifi_network.signal_strength);

    fclose(file);
}

void write_wifi_network() {
    FILE *file = fopen("wifi.txt", "w");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fprintf(file, "%s %s %d", wifi_network.ssid, wifi_network.bssid, wifi_network.signal_strength);

    fclose(file);
}

void display_wifi_network() {
    printf("SSID: %s\n", wifi_network.ssid);
    printf("BSSID: %s\n", wifi_network.bssid);
    printf("Signal Strength: %d\n", wifi_network.signal_strength);
}

int main() {
    read_wifi_network();
    display_wifi_network();

    return 0;
}