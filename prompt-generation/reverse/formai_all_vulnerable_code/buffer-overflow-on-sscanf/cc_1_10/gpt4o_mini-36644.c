//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void check_signal_strength(int signal_level) {
    if (signal_level >= -50) {
        printf("Signal strength is excellent! Enjoy seamless connectivity!\n");
    } else if (signal_level >= -70) {
        printf("Signal strength is good, but some interference may occur.\n");
    } else if (signal_level >= -85) {
        printf("Signal strength is fair. You might experience some connectivity issues.\n");
    } else {
        printf("Signal strength is poor! Consider moving closer to the router.\n");
    }
}

void analyze_wifi_signal() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    int signal_level = 0;
    int is_signal_found = 0;

    // Use the iw command to get wireless statistics
    // The command finds the first interface, and fetches signal strength
    fp = popen("iw dev | grep 'signal:'", "r");
    if (fp == NULL) {
        perror("Failed to run iw command");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Extracting signal strength
        if (sscanf(buffer, " signal: %d", &signal_level) == 1) {
            is_signal_found = 1;
            break;
        }
    }

    pclose(fp);

    if (is_signal_found) {
        printf("Current Wi-Fi Signal Strength: %d dBm\n", signal_level);
        check_signal_strength(signal_level);
    } else {
        printf("Could not retrieve Wi-Fi signal strength. Is your Wi-Fi interface up?\n");
    }
}

void show_menu() {
    printf("\n=== Wi-Fi Signal Strength Analyzer ===\n");
    printf("1. Analyze Wi-Fi Signal Strength\n");
    printf("2. Exit\n");
}

int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Let's try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                analyze_wifi_signal();
                break;
            case 2:
                printf("Exiting program. Stay connected!\n");
                return 0;
            default:
                printf("Invalid choice, please select from the menu above.\n");
                break;
        }
    }

    return 0;
}