//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants
#define MAX_SSID_LENGTH  32
#define MIN_RSSI_VALUE   -100
#define MAX_RSSI_VALUE   0
#define MAX_SAMPLES      100

// Define functions
void scan_wifi_networks(char *ssid[], int wifi_strength[]);
void analyze_wifi_strength(int wifi_strength[], int num_samples);

int main() {
    char *ssid[MAX_SAMPLES];
    int wifi_strength[MAX_SAMPLES];
    int num_samples = 0;
    int i;

    // Scan for available Wi-Fi networks and their signal strength
    scan_wifi_networks(ssid, wifi_strength);

    // Analyze the data and print the results
    analyze_wifi_strength(wifi_strength, num_samples);

    return 0;
}

void scan_wifi_networks(char *ssid[], int wifi_strength[]) {
    char temp_ssid[MAX_SSID_LENGTH];
    int temp_strength;
    int num_networks = 0;

    // Simulate scanning for Wi-Fi networks and their signal strength
    while (num_networks < MAX_SAMPLES) {
        printf("Enter SSID of Network #%d: ", num_networks+1);
        scanf("%s", temp_ssid);
        printf("Enter Wi-Fi Strength (dBm) of Network #%d: ", num_networks+1);
        scanf("%d", &temp_strength);
        if (temp_strength < MIN_RSSI_VALUE || temp_strength > MAX_RSSI_VALUE) {
            printf("Invalid signal strength value. (valid range: -100 to 0 dBm)\n");
            continue;
        }
        ssid[num_networks] = (char *) malloc(sizeof(char)*strlen(temp_ssid));
        strcpy(ssid[num_networks], temp_ssid);
        wifi_strength[num_networks] = temp_strength;
        num_networks++;
        printf("\n");
    }
}

void analyze_wifi_strength(int wifi_strength[], int num_samples) {
    int i;
    int sum = 0;
    int average_strength;

    // Calculate the average signal strength
    for (i = 0; i < num_samples; i++) {
        sum += wifi_strength[i];
    }

    if (num_samples > 0) {
        average_strength = sum / num_samples;
        printf("Average Wi-Fi strength: %d dBm\n", average_strength);
        if (average_strength < -60) {
            printf("Wi-Fi signal strength is strong.\n");
        } else if (average_strength < -80) {
            printf("Wi-Fi signal strength is moderate.\n");
        } else {
            printf("Wi-Fi signal strength is weak.\n");
        }
    } else {
        printf("No Wi-Fi networks detected.\n");
    }
}