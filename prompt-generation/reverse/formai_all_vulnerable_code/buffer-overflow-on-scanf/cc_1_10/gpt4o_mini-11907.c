//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void clear_buffer() {
    while (getchar() != '\n'); 
}

void fetch_signal_strength() {
    char buffer[MAX_LEN];
    FILE *fp;

    // Open the iwconfig command to get Wi-Fi information
    fp = popen("iwconfig 2>/dev/null", "r");
    if (fp == NULL) {
        printf("Failed to run iwconfig command\n");
        exit(1);
    }

    // Read the output a line at a time
    int found_signal = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Look for signal quality in the output
        char *signal_start = strstr(buffer, "Signal");
        if (signal_start) {
            char *quality_start = strstr(signal_start, "Quality=");
            if (quality_start) {
                // Extract signal quality value
                char signal_value[10];
                sscanf(quality_start, "Quality=%s", signal_value);
                printf("Detected Signal Strength: %s\n", signal_value);
                found_signal = 1;
            }
            break; // No need to search further
        }
    }

    if (!found_signal) {
        printf("Could not find any Wi-Fi signal information. Please ensure Wi-Fi is enabled.\n");
    }

    // Close the pipe 
    pclose(fp);
}

void display_menu() {
    printf("\n=========================\n");
    printf(" Wi-Fi Signal Analyzer\n");
    printf("=========================\n");
    printf("1. Check Signal Strength\n");
    printf("2. Exit\n");
    printf("=========================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        clear_buffer();  // Clear input buffer for future input

        switch (choice) {
            case 1:
                fetch_signal_strength();
                break;
            case 2:
                printf("Exiting the Wi-Fi Signal Analyzer. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 2);

    return 0;
}