//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 30
#define MIN_SIGNAL_STRENGTH -100
#define MAX_SIGNAL_STRENGTH 0
#define SIGNAL_STRENGTH_RANGE (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH)

void clear_screen() {
    system("clear");
}

void delay(int seconds) {
    sleep(seconds);
}

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_signal_strength(int signal_strength) {
    int bars = (signal_strength - MIN_SIGNAL_STRENGTH) * 10 / SIGNAL_STRENGTH_RANGE;
    printf("Signal Strength: ");
    for (int i = 0; i < bars; i++) {
        printf("|");
    }
    printf("\n");
}

void print_wifi_info(char *ssid, int signal_strength) {
    printf("SSID: %s\n", ssid);
    print_signal_strength(signal_strength);
}

void scan_for_networks(char networks[MAX_NETWORKS][MAX_SSID_LENGTH], int signal_strengths[MAX_NETWORKS], int *num_networks) {
    // Simulate scanning for networks
    *num_networks = random_int(1, 5);
    for (int i = 0; i < *num_networks; i++) {
        sprintf(networks[i], "Network %d", i+1);
        signal_strengths[i] = random_int(MIN_SIGNAL_STRENGTH, MAX_SIGNAL_STRENGTH);
    }
}

void display_networks(char networks[MAX_NETWORKS][MAX_SSID_LENGTH], int signal_strengths[MAX_NETWORKS], int num_networks) {
    for (int i = 0; i < num_networks; i++) {
        printf("[%d] %s ", i+1, networks[i]);
        print_signal_strength(signal_strengths[i]);
    }
}

int main() {
    srand(time(NULL));
    char networks[MAX_NETWORKS][MAX_SSID_LENGTH];
    int signal_strengths[MAX_NETWORKS];
    int num_networks;
    int selected_network;

    while (1) {
        clear_screen();
        printf("Scanning for networks...\n");
        scan_for_networks(networks, signal_strengths, &num_networks);
        if (num_networks == 0) {
            printf("No networks found. Trying again in 5 seconds...\n");
            delay(5);
            continue;
        }
        display_networks(networks, signal_strengths, num_networks);
        printf("Select a network (1-%d): ", num_networks);
        scanf("%d", &selected_network);
        if (selected_network < 1 || selected_network > num_networks) {
            printf("Invalid selection. Please try again.\n");
            delay(2);
            continue;
        }
        clear_screen();
        printf("Connecting to %s...\n", networks[selected_network-1]);
        delay(2);
        clear_screen();
        print_wifi_info(networks[selected_network-1], signal_strengths[selected_network-1]);
        delay(5);
    }

    return 0;
}