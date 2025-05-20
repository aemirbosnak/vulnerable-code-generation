//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 20

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} AccessPoint;

AccessPoint access_points[MAX_NETWORKS];
int num_networks = 0;

int get_signal_strength() {
    // Code for reading current signal strength
}

void add_network(char ssid[MAX_SSID_LENGTH]) {
    AccessPoint new_ap;
    strcpy(new_ap.ssid, ssid);
    new_ap.signal_strength = get_signal_strength();
    access_points[num_networks++] = new_ap;
}

void print_networks() {
    printf("---------------------------------------------\n");
    printf("%-20s | %-20s\n", "Access Point", "Signal Strength");
    printf("---------------------------------------------\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%-20s | %-3d%%\n", access_points[i].ssid, access_points[i].signal_strength);
    }
    printf("---------------------------------------------\n");
}

void main() {
    char input[MAX_SSID_LENGTH];
    printf("Wi-Fi Signal Strength Analyzer\n\n");

    while (1) {
        printf("Enter SSID of network to add or 'q' to quit: ");
        fgets(input, MAX_SSID_LENGTH, stdin);
        if (strcmp(input, "q\n") == 0) {
            break;
        }
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';
        add_network(input);
    }

    print_networks();
    printf("Exiting...\n");
}