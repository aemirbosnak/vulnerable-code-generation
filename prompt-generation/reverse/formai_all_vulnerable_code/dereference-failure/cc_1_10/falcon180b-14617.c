//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18

typedef struct {
    unsigned char bssid[MAX_BSSID_LENGTH];
    char ssid[MAX_SSID_LENGTH];
    int channel;
    int signal_strength;
} wireless_network;

void print_wireless_network(wireless_network *network) {
    printf("BSSID: ");
    for (int i = 0; i < 6; i++) {
        printf("%02X:", network->bssid[i]);
    }
    printf("\n");

    printf("SSID: ");
    for (int i = 0; i < strlen(network->ssid); i++) {
        printf("%c", network->ssid[i]);
    }
    printf("\n");

    printf("Channel: %d\n", network->channel);
    printf("Signal Strength: %d\n", network->signal_strength);
}

void scan_wireless_networks(void) {
    FILE *fp;
    char line[1024];
    wireless_network *networks = malloc(100 * sizeof(wireless_network));
    int num_networks = 0;

    fp = popen("iwlist wlan0 scan", "r");
    if (fp == NULL) {
        printf("Error: Failed to scan wireless networks.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, "Cell ")) {
            networks[num_networks].channel = atoi(strtok(line, " "));
            strcpy(networks[num_networks].ssid, strtok(NULL, " "));
            strcpy(networks[num_networks].bssid, strtok(NULL, " "));
            networks[num_networks].signal_strength = atoi(strtok(NULL, " "));
            num_networks++;
        }
    }

    pclose(fp);

    printf("Found %d wireless networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        print_wireless_network(&networks[i]);
    }
}

int main() {
    scan_wireless_networks();

    return 0;
}