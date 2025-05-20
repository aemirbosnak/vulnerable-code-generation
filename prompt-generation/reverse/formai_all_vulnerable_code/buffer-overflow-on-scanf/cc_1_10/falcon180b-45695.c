//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// Function to get signal strength in percentage
int getSignalStrength(int quality) {
    int signalStrength = (quality * 100) / 70;
    return signalStrength;
}

// Function to get Wi-Fi information
void getWiFiInfo(char *ssid, int *signalStrength) {
    FILE *fp;
    char cmd[MAX];

    sprintf(cmd, "iwconfig %s | grep 'Link Quality' | awk '{print $2}'", ssid);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        exit(1);
    }

    fscanf(fp, "%d", signalStrength);

    pclose(fp);
}

// Function to display Wi-Fi information in a formatted manner
void displayWiFiInfo(char *ssid, int signalStrength) {
    printf("SSID: %s\n", ssid);
    printf("Signal Strength: %d%%\n", signalStrength);
}

int main() {
    char ssid[MAX];
    int signalStrength;

    // Get Wi-Fi SSID from user
    printf("Enter Wi-Fi SSID: ");
    scanf("%s", ssid);

    // Get Wi-Fi signal strength
    getWiFiInfo(ssid, &signalStrength);

    // Display Wi-Fi information
    displayWiFiInfo(ssid, signalStrength);

    return 0;
}