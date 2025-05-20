//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NETWORKS 20

// Global variable to store scanned networks
char scanned_networks[MAX_NETWORKS][50];

// Function to scan for wireless networks
void scan_networks() {
    printf("Scanning for wireless networks...\n");

    // Simulating network scanning process
    for(int i=0; i<MAX_NETWORKS; i++) {
        int r = rand() % 100;

        if(r < 30) {
            strcpy(scanned_networks[i], "Friendly WiFi");
        } else if(r < 60) {
            strcpy(scanned_networks[i], "Cool Wi-Fi");
        } else if(r < 80) {
            strcpy(scanned_networks[i], "WIFI-nally Found You");
        } else {
            strcpy(scanned_networks[i], "The WiFi Awakens");
        }

        printf("%d. %s\n", i+1, scanned_networks[i]);
    }

    printf("Scan completed!\n");
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Wireless Network Scanner v1.0, brought to you by C-3PO!\n");

    // Loop until user enters exit command
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Scan for wireless networks.\n");
        printf("2. Show scanned networks.\n");
        printf("3. Exit.\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                scan_networks();
                break;
            case 2:
                printf("\nScanned Networks:\n");
                for(int i=0; i<MAX_NETWORKS; i++) {
                    if(strcmp(scanned_networks[i], "") != 0) {
                        printf("%d. %s\n", i+1, scanned_networks[i]);
                    }
                }
                break;
            case 3:
                printf("\nGoodbye from C-3PO and the Wireless Network Scanner v1.0!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}