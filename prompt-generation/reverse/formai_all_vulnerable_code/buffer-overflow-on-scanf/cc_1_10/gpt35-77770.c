//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10

typedef struct {
    char ssid[20];
    int rssi;
    int channel;
} wifiNetwork;

void printNetworks(wifiNetwork *networks, int count);
void filterNetworks(wifiNetwork *networks, int count, int strengthThreshold);
void sortNetworks(wifiNetwork *networks, int count);

int main() {
    int strengthThreshold;
    wifiNetwork networks[MAX_NETWORKS] = {{"WIFI1", -60, 6},
                                          {"WIFI2", -75, 1},
                                          {"WIFI3", -80, 11},
                                          {"WIFI4", -55, 1},
                                          {"WIFI5", -70, 6},
                                          {"WIFI6", -85, 11},
                                          {"WIFI7", -40, 6},
                                          {"WIFI8", -90, 1},
                                          {"WIFI9", -65, 11},
                                          {"WIFI10", -50, 6}};

    printf("Enter the signal strength threshold: ");
    scanf("%d", &strengthThreshold);

    printf("\nAll Networks:\n");
    printNetworks(networks, MAX_NETWORKS);

    filterNetworks(networks, MAX_NETWORKS, strengthThreshold);
    sortNetworks(networks, MAX_NETWORKS);

    printf("\nFiltered Networks:\n");
    printNetworks(networks, MAX_NETWORKS);

    return 0;
}

void printNetworks(wifiNetwork *networks, int count) {
    printf("----------------------------------------------------------------\n");
    printf("%20s %10s %10s\n", "SSID", "RSSI", "Channel");
    printf("----------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%20s %10d %10d\n", networks[i].ssid, networks[i].rssi, networks[i].channel);
    }
    printf("----------------------------------------------------------------\n");
}

void filterNetworks(wifiNetwork *networks, int count, int strengthThreshold) {
    for (int i = 0; i < count; i++) {
        if (networks[i].rssi < strengthThreshold) {
            memset(&networks[i], 0, sizeof(wifiNetwork));
        }
    }
}

void sortNetworks(wifiNetwork *networks, int count) {
    int i, j;
    wifiNetwork temp;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (networks[i].rssi < networks[j].rssi) {
                temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
}