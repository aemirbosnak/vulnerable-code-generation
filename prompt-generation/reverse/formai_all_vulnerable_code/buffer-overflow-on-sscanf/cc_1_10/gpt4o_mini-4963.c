//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 50
#define MAX_SSID_LENGTH 32
#define COMMAND_BUFFER 128

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

void parse_scan_results(const char *buffer, WiFiNetwork *networks, int *count) {
    const char *p = buffer;
    char *ssid_start;
    char *ssid_end;
    char temp_ssid[MAX_SSID_LENGTH];
    int current_signal = 0;
    
    while ((ssid_start = strstr(p, "ESSID:")) != NULL) {
        p = ssid_start + strlen("ESSID:");
        
        ssid_end = strchr(p, '\"');
        if (ssid_end) {
            strncpy(temp_ssid, p + 1, ssid_end - p - 1);
            temp_ssid[ssid_end - p - 1] = '\0';
            strcpy(networks[*count].ssid, temp_ssid);
        }

        current_signal = 0;
        sscanf(ssid_start, " Signal level=%d", &current_signal);
        networks[*count].signal_strength = current_signal;
        (*count)++;

        if (*count >= MAX_NETWORKS) {
            break;
        }

        p = ssid_end + 1; // Move past the current network
    }
}

void scan_wireless_networks() {
    char command[COMMAND_BUFFER];
    char buffer[4096];
    FILE *fp;
    WiFiNetwork networks[MAX_NETWORKS];
    int network_count = 0;

    memset(networks, 0, sizeof(networks));
    
    // Execute the command to scan for wireless networks
    snprintf(command, sizeof(command), "sudo iwlist wlan0 scan");
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run iwlist command\n");
        exit(1);
    }

    // Read the output a line at a time
    fread(buffer, sizeof(char), sizeof(buffer), fp);
    pclose(fp);

    // Parse the command output
    parse_scan_results(buffer, networks, &network_count);

    // Display results
    printf("Available Wireless Networks:\n");
    printf("---------------------------\n");
    for (int i = 0; i < network_count; i++) {
        printf("SSID: %s, Signal Strength: %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    printf("Wi-Fi Network Scanner\n");
    printf("=====================\n");
    
    scan_wireless_networks();

    return 0;
}