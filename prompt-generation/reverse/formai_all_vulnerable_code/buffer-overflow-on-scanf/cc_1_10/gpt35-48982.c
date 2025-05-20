//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORKS 10

typedef struct {
    char ssid[20];
    int signal_strength;
} network;

int get_random_signal_strength();
void scan_networks(network *networks, int num_networks);
void print_networks(network *networks, int num_networks);
void sort_networks_by_signal_strength(network *networks, int num_networks);
void analyze_signal_strength(network *networks, int num_networks);

int main() {
    int num_networks = 5;
    network networks[MAX_NETWORKS];
    scan_networks(networks, num_networks);
    sort_networks_by_signal_strength(networks, num_networks);
    analyze_signal_strength(networks, num_networks);
    print_networks(networks, num_networks);
    return 0;
}

int get_random_signal_strength() {
    return rand() % 100 + 1;
}

void scan_networks(network *networks, int num_networks) {
    for (int i = 0; i < num_networks; i++) {
        printf("Scanning network %d...\n", i + 1);
        printf("Enter network SSID: ");
        scanf("%s", networks[i].ssid);
        networks[i].signal_strength = get_random_signal_strength();
    }
    printf("Scan complete!\n");
}

void print_networks(network *networks, int num_networks) {
    printf("Networks sorted by signal strength:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("SSID: %s | Signal Strength: %d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

void sort_networks_by_signal_strength(network *networks, int num_networks) {
    for (int i = 0; i < num_networks - 1; i++) {        
        int max_index = i;
        for (int j = i + 1; j < num_networks; j++) {
            if (networks[j].signal_strength > networks[max_index].signal_strength) {
                max_index = j;
            }
        }
        network temp = networks[i];
        networks[i] = networks[max_index];
        networks[max_index] = temp;
    }
}

void analyze_signal_strength(network *networks, int num_networks) {
    bool isStrongSignal = false;
    for (int i = 0; i < num_networks; i++) {
        if (networks[i].signal_strength >= 80) {
            printf("%s has a strong signal.\n", networks[i].ssid);
            isStrongSignal = true;
        } else if (networks[i].signal_strength >= 60) {
            printf("%s has a medium signal.\n", networks[i].ssid);
        } else {
            printf("%s has a weak signal.\n", networks[i].ssid);
        }
    }
    if (!isStrongSignal) {
        printf("There are no strong signals in the area.\n");
    }
}