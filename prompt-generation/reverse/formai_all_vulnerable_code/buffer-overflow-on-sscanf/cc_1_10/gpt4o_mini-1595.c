//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define BUFFER_SIZE 256

typedef struct {
    char ssid[50];
    int signal_strength; // in dBm
} WifiNetwork;

void parse_iwlist_output(WifiNetwork* networks, int* count) {
    FILE* fp;
    char buffer[BUFFER_SIZE];
    char ssid[50];
    int signal_level;
    
    // Execute the iwlist scan command and read its output
    fp = popen("iwlist wlan0 scan 2>/dev/null", "r");
    if (fp == NULL) {
        perror("Failed to run iwlist");
        exit(EXIT_FAILURE);
    }

    *count = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, " ESSID:\"%[^\"]\"", ssid) == 1) {
            // Found a network SSID
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // Next, look for Signal level
                if (sscanf(buffer, " Signal level=%d", &signal_level) == 1) {
                    // Add network details to the array
                    if (*count < MAX_NETWORKS) {
                        strncpy(networks[*count].ssid, ssid, sizeof(networks[*count].ssid));
                        networks[*count].signal_strength = signal_level;
                        (*count)++;
                    }
                    break; // Exit the current network scanning; continue with next
                }
            }
        }
    }

    pclose(fp);
}

void display_networks(WifiNetwork* networks, int count) {
    printf("\nAvailable Wi-Fi Networks:\n");
    printf("%-30s | %s\n", "SSID", "Signal Strength (dBm)");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s | %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

void analyze_signal_strength(WifiNetwork* networks, int count) {
    int weak_count = 0, moderate_count = 0, strong_count = 0;

    for (int i = 0; i < count; i++) {
        if (networks[i].signal_strength < -80) {
            weak_count++;
        } else if (networks[i].signal_strength >= -80 && networks[i].signal_strength < -50) {
            moderate_count++;
        } else {
            strong_count++;
        }
    }

    printf("\nSignal Strength Analysis:\n");
    printf("Weak Networks: %d\n", weak_count);
    printf("Moderate Networks: %d\n", moderate_count);
    printf("Strong Networks: %d\n", strong_count);
}

int main() {
    WifiNetwork networks[MAX_NETWORKS];
    int count = 0;

    parse_iwlist_output(networks, &count);
    
    if (count == 0) {
        printf("No Wi-Fi networks found.\n");
        return 0;
    }

    display_networks(networks, count);
    analyze_signal_strength(networks, count);

    return 0;
}