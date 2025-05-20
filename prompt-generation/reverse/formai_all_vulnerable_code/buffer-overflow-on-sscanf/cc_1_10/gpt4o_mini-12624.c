//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define MAX_NETWORKS 100

typedef struct {
    char ssid[BUFFER_SIZE];
    int signal_level;
} Network;

void parseOutput(char *output, Network *networks, int *network_count);
void sortNetworks(Network *networks, int network_count);
void displayNetworks(Network *networks, int network_count);

int main() {
    char command[] = "nmcli -fields SSID,SIGNAL device wifi list";
    char output[BUFFER_SIZE * MAX_NETWORKS];
    int network_count = 0;
    Network networks[MAX_NETWORKS];

    // Execute the command and read output
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return 1;
    }

    // Read the output from the command
    while (fgets(output, sizeof(output), fp) != NULL) {
        // Handle output
        parseOutput(output, networks, &network_count);
    }

    // Close the file pointer
    pclose(fp);

    // Sort networks by signal strength
    sortNetworks(networks, network_count);

    // Display the networks with their signal levels
    displayNetworks(networks, network_count);

    return 0;
}

void parseOutput(char *output, Network *networks, int *network_count) {
    if (sscanf(output, "%s %d", networks[*network_count].ssid, &networks[*network_count].signal_level) == 2) {
        (*network_count)++;
    }
}

void sortNetworks(Network *networks, int network_count) {
    for (int i = 0; i < network_count - 1; i++) {
        for (int j = 0; j < network_count - i - 1; j++) {
            if (networks[j].signal_level < networks[j + 1].signal_level) {
                // Swap networks
                Network temp = networks[j];
                networks[j] = networks[j + 1];
                networks[j + 1] = temp;
            }
        }
    }
}

void displayNetworks(Network *networks, int network_count) {
    printf("\nAvailable Wi-Fi Networks:\n");
    printf("%-25s %s\n", "SSID", "Signal Strength (%)");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < network_count; i++) {
        printf("%-25s %d\n", networks[i].ssid, networks[i].signal_level);
    }
}