//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_network_t;

bool is_wifi_connected = false;
char connected_ssid[MAX_SSID_LENGTH];
int connected_signal_strength = 0;
wifi_network_t available_networks[] = {
    {"WiFi_AP_1", -50},
    {"WiFi_AP_2", -70},
    {"WiFi_AP_3", -60},
    {"WiFi_AP_4", -80},
    {"WiFi_AP_5", -90},
    {"WiFi_AP_6", -55},
    {"WiFi_AP_7", -75},
    {"WiFi_AP_8", -40}
};
int num_available_networks = sizeof(available_networks) / sizeof(wifi_network_t);

void scan_and_print_available_networks() {
    printf("Scanning for available networks...\n");

    for (int i=0; i<num_available_networks; i++) {
        wifi_network_t* network = &available_networks[i];
        printf("%d. %s (%d dBm)\n", i+1, network->ssid, network->signal_strength);
    }

    printf("\n");
}

void connect_to_wifi_network(int network_index) {
    wifi_network_t* network = &available_networks[network_index];
    printf("Connecting to %s...\n", network->ssid);
    printf("Authentication successful.\n");
    printf("Connected to %s (%d dBm signal strength).\n", network->ssid, network->signal_strength);
    is_wifi_connected = true;
    strcpy(connected_ssid, network->ssid);
    connected_signal_strength = network->signal_strength;
}

void disconnect_from_wifi_network() {
    printf("Disconnecting from %s...\n", connected_ssid);
    printf("Disconnected.\n");
    is_wifi_connected = false;
    connected_signal_strength = 0;
}

int main() {
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");

    bool is_running = true;
    while(is_running) {
        if (is_wifi_connected) {
            printf("Connected to %s (%d dBm signal strength).\n", connected_ssid, connected_signal_strength);
        } else {
            scan_and_print_available_networks();

            printf("Enter the number of a network to connect to (or 0 to exit): ");
            int input;
            scanf("%d", &input);

            if (input == 0) {
                printf("Goodbye!\n");
                is_running = false;
            } else if (input > 0 && input <= num_available_networks) {
                connect_to_wifi_network(input - 1);
            } else {
                printf("Invalid input.\n");
            }
        }

        printf("\n");
    }

    return 0;
}