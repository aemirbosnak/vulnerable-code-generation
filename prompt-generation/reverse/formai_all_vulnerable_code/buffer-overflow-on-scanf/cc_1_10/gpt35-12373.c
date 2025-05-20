//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define buffer size for reading files
#define BUFFER_SIZE 1024

// Define the maximum number of Wi-Fi networks that can be stored
#define MAX_WIFI_NETS 10

// Structure to store Wi-Fi network data
typedef struct {
    char ssid[25];
    int signal_strength;
} wifi_network;

// Function to get the signal strength of a Wi-Fi network
int get_wifi_signal_strength(char* interface, char* ssid) {
    char command[100];
    sprintf(command, "iwlist %s scan | grep -A 5 \"%s\" | grep Signal | awk '{print $4}' | cut -c 6-7", interface, ssid);

    // Open pipe to read command output
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        printf("Error opening pipe!\n");
        return -1;
    }

    // Read output into buffer
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, pipe);

    // Close pipe
    pclose(pipe);

    // Convert buffer value to integer
    int signal_strength = strtol(buffer, NULL, 10);

    return signal_strength;
}

int main() {
    // Allocate memory for Wi-Fi network array
    wifi_network* networks = calloc(MAX_WIFI_NETS, sizeof(wifi_network));

    // Get Wi-Fi interface name
    char interface[10];
    printf("Enter Wi-Fi interface name: ");
    scanf("%s", interface);

    // Open file with known Wi-Fi network SSIDs
    FILE* file = fopen("wifi_networks.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read each line in file
    char buffer[BUFFER_SIZE];
    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, file) && i < MAX_WIFI_NETS) {
        // Trim newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Get signal strength of network
        int signal_strength = get_wifi_signal_strength(interface, buffer);

        // Add network to array
        wifi_network network;
        strcpy(network.ssid, buffer);
        network.signal_strength = signal_strength;
        networks[i++] = network;
    }

    // Close file
    fclose(file);

    // Print out Wi-Fi network data
    printf("\n%-10s %s\n", "SSID", "Signal Strength");
    for (int j = 0; j < i; j++) {
        printf("%-10s %d\n", networks[j].ssid, networks[j].signal_strength);
    }

    // Deallocate memory
    free(networks);

    return 0;
}