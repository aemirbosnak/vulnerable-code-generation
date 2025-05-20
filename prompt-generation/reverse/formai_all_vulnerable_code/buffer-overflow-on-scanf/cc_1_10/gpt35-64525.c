//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: recursive
#include<stdio.h>

#define MAX_WIFI_AND_MOB_DEV 100

int wifiDevices[MAX_WIFI_AND_MOB_DEV];
int mobDevices[MAX_WIFI_AND_MOB_DEV];
int wifiDevicesCount = 0;
int mobDevicesCount = 0;

void analyzeStrength(int wifiDeviceIndex, int mobDeviceIndex);
void printResults();

int main() {
    int t, i, j;
    scanf("%d", &t);

    // Reading all the wifi devices strength integers
    for (i = 0; i < t; i++) {
        scanf("%d", &wifiDevices[wifiDevicesCount]);
        wifiDevicesCount++;
    }

    // Reading all the mobile devices strength integers
    for (i = 0; i < t; i++) {
        scanf("%d", &mobDevices[mobDevicesCount]);
        mobDevicesCount++;
    }

    // Analyzing the strength of each wifi device with respect to mobile devices recursively
    for (i = 0; i < wifiDevicesCount; i++) {
        analyzeStrength(i, 0);
    }

    // Printing the results of the analysis
    printResults();

    return 0;
}

void analyzeStrength(int wifiDeviceIndex, int mobDeviceIndex) {
    if (mobDeviceIndex >= mobDevicesCount) {
        return;
    }

    int diff = wifiDevices[wifiDeviceIndex] - mobDevices[mobDeviceIndex];
    if (diff < 0) {
        diff = diff * -1;
    }

    printf("Strength of Wifi Device at index %d with respect to Mobile Device at index %d: %d\n", wifiDeviceIndex, mobDeviceIndex, diff);

    // Recursively analyzing the strength with respect to all mobile devices
    analyzeStrength(wifiDeviceIndex, mobDeviceIndex + 1);
}

void printResults() {
    int i;
    printf("--------------------\n");
    printf("Wifi and Mobile devices analysis results:\n");
    printf("--------------------\n");

    printf("Wifi Devices and their strength: ");
    for (i = 0; i < wifiDevicesCount; i++) {
        printf("%d ", wifiDevices[i]);
    }

    printf("\n");

    printf("Mobile Devices and their strength: ");
    for (i = 0; i < mobDevicesCount; i++) {
        printf("%d ", mobDevices[i]);
    }

    printf("\n");
}