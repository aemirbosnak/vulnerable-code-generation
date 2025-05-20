//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_SSID_LENGTH 32
#define MAX_NUM_NETWORKS 100

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} NetworkDetail;

void execute_command(const char *cmd, char *output, size_t size) {
    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return;
    }

    fgets(output, size, fp);
    pclose(fp);
}

int parse_wifi_data(const char *raw_data, NetworkDetail *networks) {
    char *line;
    int index = 0;

    line = strtok(raw_data, "\n");
    while (line != NULL && index < MAX_NUM_NETWORKS) {
        char ssid[MAX_SSID_LENGTH];
        int signal;

        // Example line: "MyWifi: -70 dBm"
        if (sscanf(line, "%[^:]: %d dBm", ssid, &signal) == 2) {
            strncpy(networks[index].ssid, ssid, MAX_SSID_LENGTH);
            networks[index].signal_strength = signal;
            index++;
        }

        line = strtok(NULL, "\n");
    }
    return index;
}

void print_networks(const NetworkDetail *networks, int count) {
    printf("\n-----------------------------------\n");
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("-----------------------------------\n");
    printf("SSID                            Signal Strength (dBm)\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-30s %d\n", networks[i].ssid, networks[i].signal_strength);
    }

    printf("----------------------------------------------------\n");
}

void sort_networks(NetworkDetail *networks, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (networks[j].signal_strength > networks[i].signal_strength) {
                NetworkDetail temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
}

int main() {
    char command[] = "nmcli -f SSID,SIGNAL device wifi";
    char raw_data[1024];
    NetworkDetail networks[MAX_NUM_NETWORKS];

    printf("Fetching Wi-Fi networks...\n");
    
    // Execute the command to obtain the Wi-Fi details
    execute_command(command, raw_data, sizeof(raw_data));
    
    // Parse the fetched data
    int network_count = parse_wifi_data(raw_data, networks);
    
    // Sort networks by signal strength
    sort_networks(networks, network_count);

    // Print the sorted network information
    print_networks(networks, network_count);

    return 0;
}