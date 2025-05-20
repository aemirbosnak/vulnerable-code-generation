//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SSID_MAX_LEN 32    // Maximum length of SSID
#define MAX_RSSI 100       // Maximum value of RSSI
#define MIN_RSSI -100      // Minimum value of RSSI

// Function prototypes
void getInput(char *ssid, int *rssi);
void printReport(char *ssid, int rssi);

int main() {
    char ssid[SSID_MAX_LEN];
    int rssi;

    getInput(ssid, &rssi);
    printReport(ssid, rssi);

    return 0;
}

// Function to get input from user
void getInput(char *ssid, int *rssi) {
    printf("Enter SSID: ");
    scanf("%s", ssid);

    printf("Enter RSSI: ");
    scanf("%d", rssi);
}

// Function to print report
void printReport(char *ssid, int rssi) {
    printf("---------------------------\n");
    printf("| Wi-Fi Signal Strength   |\n");
    printf("---------------------------\n");
    printf("| SSID         |   RSSI   |\n");
    printf("|--------------|----------|\n");
    printf("| %-12s | %-8d |\n", ssid, rssi);
    printf("|--------------|----------|\n");

    // Print signal strength bars
    int bars = (rssi - MIN_RSSI) * 10 / (MAX_RSSI - MIN_RSSI);
    printf("| Signal Strength Bars:");
    for (int i = 0; i < bars; i++) {
        printf("#");
    }
    printf("\n");
    printf("---------------------------\n");
}