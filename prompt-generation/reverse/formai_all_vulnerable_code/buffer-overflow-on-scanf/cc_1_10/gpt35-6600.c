//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max size of SSID and signal
#define MAX_SIZE 20

// Define structure for Wi-Fi networks
typedef struct {
    char ssid[MAX_SIZE];
    int signal;
} Network;

int main() {
    // Create array of networks
    Network networks[5];
    
    // Prompt user to input SSID and signal for each network
    printf("Please enter the SSID and signal strength (out of 10) for each network:\n");
    for (int i = 0; i < 5; i++) {
        printf("Network %d: ", i + 1);
        scanf("%s %d", networks[i].ssid, &networks[i].signal);
    }
    
    // Sort the array of networks based on signal strength
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (networks[j].signal > networks[i].signal) {
                // Swap the two networks
                Network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
    
    // Display the sorted array of networks
    printf("\nSorted Wi-Fi network list:\n");
    printf("--------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%-20s %d/10\n", networks[i].ssid, networks[i].signal);
    }
    
    // Calculate and display the average signal strength
    int total_signal = 0;
    for (int i = 0; i < 5; i++) {
        total_signal += networks[i].signal;
    }
    float average_signal = (float)total_signal / 5;
    printf("\nAverage signal strength: %.1f/10\n", average_signal);
    
    // Check for and display any networks with signal strength below 5
    printf("\nNetworks with signal strength below 5:\n");
    printf("-------------------------------------\n");
    int below_five = 0;
    for (int i = 0; i < 5; i++) {
        if (networks[i].signal < 5) {
            below_five = 1;
            printf("%-20s %d/10\n", networks[i].ssid, networks[i].signal);
        }
    }
    if (!below_five) {
        printf("None\n");
    }
    
    return 0;
}