//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

void clear_screen() {
    system("clear||cls");
}

void display_networks(Network *networks, int count) {
    clear_screen();
    printf("---- Wi-Fi Networks Found ----\n\n");
    for(int i = 0; i < count; i++) {
        printf("%d. SSID: %s\n   Signal Strength: %d\n", i+1, networks[i].ssid, networks[i].signal_strength);
    }
}

void analyze_networks(Network *networks, int count) {
    clear_screen();

    // Sort networks based on signal strength
    for(int i = 0; i < count-1; i++) {
        for(int j = i+1; j < count; j++) {
            if(networks[i].signal_strength < networks[j].signal_strength) {
                Network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }

    printf("---- Wi-Fi Networks Analysis ----\n\n");
    printf("Strongest Network(s):\n");
    int strongest_signal = networks[0].signal_strength;
    for(int i = 0; i < count; i++) {
        if(networks[i].signal_strength == strongest_signal) {
            printf("- SSID: %s\n  Signal Strength: %d\n", networks[i].ssid, networks[i].signal_strength);
        } else {
            break;
        }
    }

    printf("\nWeakest Network(s):\n");
    int weakest_signal = networks[count-1].signal_strength;
    for(int i = count-1; i >= 0; i--) {
        if(networks[i].signal_strength == weakest_signal) {
            printf("- SSID: %s\n  Signal Strength: %d\n", networks[i].ssid, networks[i].signal_strength);
        } else {
            break;
        }
    }

    printf("\nPress any key to continue...");
    getchar();
}

int main() {
    bool running = true;
    Network networks[MAX_NETWORKS];
    int count = 0;

    while(running) {
        clear_screen();
        printf("\n1. Scan for Wi-Fi Networks\n");
        printf("2. Analyze Wi-Fi Networks\n");
        printf("3. Quit\n");

        char choice;
        scanf(" %c", &choice);
        getchar(); // Consume newline character

        switch(choice) {
            case '1': // Scan for Wi-Fi Networks
                clear_screen();
                printf("Scanning for Wi-Fi Networks...\n\n");

                // Pretend to scan for networks and fill in some dummy data
                strcpy(networks[0].ssid, "My Wi-Fi");
                networks[0].signal_strength = -30;
                strcpy(networks[1].ssid, "My Neighbors Wi-Fi");
                networks[1].signal_strength = -50;
                strcpy(networks[2].ssid, "Public Wi-Fi");
                networks[2].signal_strength = -70;
                count = 3;

                printf("Found %d Wi-Fi Networks!\n", count);
                printf("Press any key to continue...");
                getchar();
                break;

            case '2': // Analyze Wi-Fi Networks
                if(count == 0) {
                    clear_screen();
                    printf("No Wi-Fi networks found. Please scan for networks first.\n");
                    printf("Press any key to continue...");
                    getchar();
                } else {
                    analyze_networks(networks, count);
                }
                break;

            case '3': // Quit
                clear_screen();
                printf("Goodbye!\n");
                running = false;
                break;

            default: // Invalid input
                clear_screen();
                printf("Invalid choice. Please try again.\n");
                printf("Press any key to continue...");
                getchar();
                break;
        }
    }

    return 0;
}