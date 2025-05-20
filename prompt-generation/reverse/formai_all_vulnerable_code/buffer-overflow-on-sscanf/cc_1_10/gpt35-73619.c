//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 20

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_network;

void print_network(wifi_network *network);
void print_networks(wifi_network networks[], int count);
void sort_networks(wifi_network networks[], int count);

int main() {
    wifi_network networks[MAX_NETWORKS];
    int count = 0;

    // Read networks from file
    FILE *file = fopen("networks.txt", "r");
    if (file == NULL) {
        printf("Error: could not open networks.txt\n");
        return 1;
    }

    char line[50];
    while (fgets(line, sizeof(line), file)) {
        char ssid[MAX_SSID_LENGTH];
        int signal_strength;
        if (sscanf(line, "%s %d", ssid, &signal_strength) != 2) {
            printf("Warning: invalid line in networks.txt\n");
            continue;
        }
        if (strlen(ssid) >= MAX_SSID_LENGTH) {
            printf("Warning: SSID too long in networks.txt\n");
            continue;
        }
        if (count >= MAX_NETWORKS) {
            printf("Warning: too many networks in networks.txt\n");
            break;
        }
        strcpy(networks[count].ssid, ssid);
        networks[count].signal_strength = signal_strength;
        count++;
    }

    fclose(file);

    // Sort networks by signal strength
    sort_networks(networks, count);

    // Print networks
    printf("Wifi Networks:\n");
    print_networks(networks, count);

    return 0;
}

void print_network(wifi_network *network) {
    printf("%-20s %d dBm\n", network->ssid, network->signal_strength);
}

void print_networks(wifi_network networks[], int count) {
    for (int i = 0; i < count; i++) {
        print_network(&networks[i]);
    }
}

void sort_networks(wifi_network networks[], int count) {
    for (int i = 0; i < count-1; i++) {
        for (int j = i+1; j < count; j++) {
            if (networks[i].signal_strength < networks[j].signal_strength) {
                wifi_network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
}