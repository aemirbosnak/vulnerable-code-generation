//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIFI_NETWORKS 20
#define MAX_WIFI_NAME_LENGTH 20

// Structure to store information about a Wi-Fi network
typedef struct {
    char name[MAX_WIFI_NAME_LENGTH];
    int signal_strength;
} wifi_network;

int main() {
    wifi_network networks[MAX_WIFI_NETWORKS];
    int num_networks = 0;
    char input[MAX_WIFI_NAME_LENGTH+10]; // Extra 10 for signal strength input

    // Ask user to input the Wi-Fi networks
    printf("Enter the name of each Wi-Fi network followed by its signal strength (-100 to 100):\n");

    while (1) {
        // Read in the input
        fgets(input, sizeof(input), stdin);

        // If the user is done entering networks, break out of the loop
        if (strncmp(input, "done", 4) == 0) {
            break;
        }

        // Check if there is space for another network
        if (num_networks >= MAX_WIFI_NETWORKS) {
            printf("Error: Maximum number of Wi-Fi networks reached\n");
            break;
        }

        // Parse the input into the network struct
        char *name_end = strchr(input, ' ');
        if (name_end == NULL) {
            printf("Error: Invalid input format\n");
            continue;
        }

        int signal_strength = atoi(name_end+1);
        if (signal_strength < -100 || signal_strength > 100) {
            printf("Error: Signal strength must be between -100 and 100\n");
            continue;
        }

        int name_length = name_end - input;
        if (name_length > MAX_WIFI_NAME_LENGTH) {
            printf("Error: Wi-Fi name is too long\n");
            continue;
        }

        strncpy(networks[num_networks].name, input, name_length);
        networks[num_networks].name[name_length] = '\0';
        networks[num_networks].signal_strength = signal_strength;
        num_networks++;
    }

    // Print out the sorted Wi-Fi networks
    printf("Wi-Fi networks sorted by signal strength (strongest to weakest):\n");

    for (int i = 0; i < num_networks; i++) {
        // Find the index of the network with the highest signal strength that hasn't been printed yet
        int strongest_index = -1;
        int strongest_strength = -101;
        for (int j = 0; j < num_networks; j++) {
            if (networks[j].signal_strength > strongest_strength) {
                int already_printed = 0;
                for (int k = 0; k < i; k++) {
                    if (strcmp(networks[j].name, networks[k].name) == 0) {
                        already_printed = 1;
                        break;
                    }
                }
                if (!already_printed) {
                    strongest_index = j;
                    strongest_strength = networks[j].signal_strength;
                }
            }
        }

        printf("%s (%d dBm)\n", networks[strongest_index].name, networks[strongest_index].signal_strength);
    }

    return 0;
}