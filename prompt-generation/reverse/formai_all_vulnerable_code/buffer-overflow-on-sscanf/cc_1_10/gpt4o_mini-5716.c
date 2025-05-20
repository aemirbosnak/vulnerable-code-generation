//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define SSID_LEN 32
#define COMMAND_LEN 256

typedef struct {
    char ssid[SSID_LEN];
    int signal_strength;
    char channel[4];
    char encryption[20];
} WiFiNetwork;

void parse_output(const char *line, WiFiNetwork *network) {
    if (sscanf(line, "ESSID:\"%[^\"]\"", network->ssid) == 1) {
        // Successfully read SSID
    } else if (sscanf(line, "Signal level=%d", &network->signal_strength) == 1) {
        // Successfully read signal strength
    } else if (sscanf(line, "Channel:%s", network->channel) == 1) {
        // Successfully read channel
    } else if (strstr(line, "Encryption") != NULL) {
        strcpy(network->encryption, "Enabled");
    } else {
        strcpy(network->encryption, "Disabled");
    }
}

void scan_wifi_networks(WiFiNetwork networks[], int *count) {
    FILE *fp;
    char command[COMMAND_LEN];
    char line[COMMAND_LEN];
    
    // Use iwlist to get the WiFi networks
    snprintf(command, sizeof(command), "iwlist wlan0 scan 2>/dev/null");
    
    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return;
    }

    *count = 0;
    WiFiNetwork current_network;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse each line of output
        parse_output(line, &current_network);
        
        if (strlen(current_network.ssid) > 0 && *count < MAX_NETWORKS) {
            networks[*count] = current_network;
            (*count)++;
        }
    }

    // Close the command
    pclose(fp);
}

void print_networks(WiFiNetwork networks[], int count) {
    printf("%-32s %-15s %-8s %s\n", "SSID", "Signal Strength", "Channel", "Encryption");
    printf("%-32s %-15s %-8s %s\n", "-----", "---------------", "-------", "----------");
    for (int i = 0; i < count; i++) {
        printf("%-32s %-15d %-8s %s\n", 
                networks[i].ssid, 
                networks[i].signal_strength, 
                networks[i].channel, 
                networks[i].encryption);
    }
}

int main() {
    WiFiNetwork networks[MAX_NETWORKS];
    int count = 0;

    printf("Wi-Fi Signal Strength Analyzer:\n");
    printf("==============================\n");
    
    scan_wifi_networks(networks, &count);
    
    if (count > 0) {
        print_networks(networks, count);
    } else {
        printf("No Wi-Fi networks found.\n");
    }

    return 0;
}