//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NETWORKS 10

typedef struct {
    char ssid[32];
    int signal_strength;
} Network;

void clearScreen() {
    printf("\033[H\033[J");
}

void displayHeader() {
    printf("---------------------------------------------------\n");
    printf("|             Wi-Fi Signal Strength Analyzer       |\n");
    printf("---------------------------------------------------\n");
}

void displayNetworks(Network networkList[], int numNetworks) {
    printf("\nAvailable Networks:\n");
    printf("-----------------------------\n");
    printf("| SSID                 |  RSSI |\n");
    printf("-----------------------------\n");
    for (int i = 0; i < numNetworks; i++) {
        printf("| %-20s | %-5d |\n", networkList[i].ssid, networkList[i].signal_strength);
    }
    printf("-----------------------------\n");
}

void scanNetworks(Network networkList[], int *numNetworks) {
    // Simulating scanning of networks with random values
    printf("Scanning for networks...\n");
    *numNetworks = rand() % MAX_NETWORKS + 1;
    for (int i = 0; i < *numNetworks; i++) {
        sprintf(networkList[i].ssid, "Network %d", i+1);
        networkList[i].signal_strength = rand() % 100 - 50;
    }
    printf("Found %d networks\n", *numNetworks);
}

void displayStatistics(Network networkList[], int numNetworks) {
    if (numNetworks == 0) {
        printf("No networks found\n");
        return;
    }
    int totalStrength = 0, minStrength = networkList[0].signal_strength, maxStrength = networkList[0].signal_strength;
    for (int i = 0; i < numNetworks; i++) {
        totalStrength += networkList[i].signal_strength;
        if (networkList[i].signal_strength < minStrength) {
            minStrength = networkList[i].signal_strength;
        }
        if (networkList[i].signal_strength > maxStrength) {
            maxStrength = networkList[i].signal_strength;
        }
    }
    float averageStrength = (float)totalStrength / numNetworks;
    printf("\nSignal Strength Statistics:\n");
    printf("------------------------------\n");
    printf("| Average Signal Strength: %-5.2f |\n", averageStrength);
    printf("| Minimum Signal Strength: %-5d |\n", minStrength);
    printf("| Maximum Signal Strength: %-5d |\n", maxStrength);
    printf("------------------------------\n");
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Scan for networks\n");
    printf("2. Display networks\n");
    printf("3. Display statistics\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    srand(time(0));
    Network networkList[MAX_NETWORKS];
    int numNetworks = 0;
    char userChoice;
    do {
        clearScreen();
        displayHeader();
        displayMenu();
        scanf(" %c", &userChoice);
        switch (userChoice) {
            case '1':
                scanNetworks(networkList, &numNetworks);
                break;
            case '2':
                displayNetworks(networkList, numNetworks);
                break;
            case '3':
                displayStatistics(networkList, numNetworks);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        printf("Press enter to continue...");
        getchar();
        getchar();
    } while (userChoice != '4');

    return 0;
}