//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define BUFFER_SIZE 256

typedef struct {
    char ssid[BUFFER_SIZE];
    int signal_strength; // in dBm
} WiFiNetwork;

void analyze_wifi_signals(WiFiNetwork networks[], int *count) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char command[] = "iw dev wlan0 scan | grep 'SSID\\|signal'";
    
    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    // Read the output a line at a time
    int index = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "SSID") != NULL) {
            sscanf(buffer, " SSID: %s", networks[index].ssid); // Extract SSID
        } else if (strstr(buffer, "signal") != NULL) {
            sscanf(buffer, " signal: %d", &networks[index].signal_strength); // Extract strength
            index++;
        }
    }
    *count = index; // Total count of networks found
    pclose(fp);
}

void display_wifi_report(WiFiNetwork networks[], int count) {
    printf("\n📶 Wi-Fi Signal Strength Analysis Report 📶\n");
    printf("--------------------------------------------------\n");
    printf("| %20s | %17s |\n", "SSID", "Signal Strength (dBm)");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %20s | %17d |\n", networks[i].ssid, networks[i].signal_strength);
    }
    
    printf("--------------------------------------------------\n");
}

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer! 🚀\n");
    printf("Gathering Wi-Fi network data, please wait...\n");

    WiFiNetwork networks[MAX_NETWORKS];
    int network_count = 0;

    analyze_wifi_signals(networks, &network_count);
    display_wifi_report(networks, network_count);

    printf("Analysis complete! Happy surfing! 🌐\n");
    return 0;
}