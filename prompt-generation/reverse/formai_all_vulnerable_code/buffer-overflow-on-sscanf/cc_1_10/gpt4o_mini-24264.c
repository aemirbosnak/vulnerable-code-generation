//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LEN 32

typedef struct {
    char ssid[MAX_SSID_LEN];
    char quality[10];
    char frequency[10];
} Network;

void parse_networks(FILE *fp, Network networks[], int *count) {
    char line[256];
    *count = 0;

    while (fgets(line, sizeof(line), fp) != NULL && *count < MAX_NETWORKS) {
        if (strstr(line, "ESSID") != NULL) {
            sscanf(line, " ESSID:\"%[^\"]\"", networks[*count].ssid);
        } else if (strstr(line, "Quality") != NULL) {
            sscanf(line, " Quality=%[^ ]", networks[*count].quality);
        } else if (strstr(line, "Frequency") != NULL) {
            sscanf(line, " Frequency:%[^ ]", networks[*count].frequency);
            (*count)++;
        }
    }
}

void print_networks(Network networks[], int count) {
    printf("Available Wireless Networks:\n");
    printf("%-32s %-10s %-10s\n", "SSID", "Quality", "Frequency");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-32s %-10s %-10s\n", networks[i].ssid, networks[i].quality, networks[i].frequency);
    }
}

int main() {
    FILE *fp;
    Network networks[MAX_NETWORKS];
    int network_count = 0;

    // Command to scan wireless networks
    const char *command = "sudo iwlist scan";

    // Open a pipe to the command
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return 1;
    }

    // Parse the output of the command
    parse_networks(fp, networks, &network_count);

    // Close the pipe
    pclose(fp);

    // Print the results
    if (network_count > 0) {
        print_networks(networks, network_count);
    } else {
        printf("No wireless networks found.\n");
    }

    return 0;
}