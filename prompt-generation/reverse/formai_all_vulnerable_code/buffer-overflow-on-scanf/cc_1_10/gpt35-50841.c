//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SSID_LEN 32
#define MAX_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WifiNetwork;

WifiNetwork networks[MAX_NETWORKS];
int networkCount = 0;

bool addNetwork(char *ssid, int signal_strength) {
    if (networkCount == MAX_NETWORKS) {
        return false;
    }

    strcpy(networks[networkCount].ssid, ssid);
    networks[networkCount].signal_strength = signal_strength;

    networkCount++;

    return true;
}

void printNetworks() {
    if (networkCount == 0) {
        printf("No networks found.\n");
        return;
    }

    printf("SSID\tSignal Strength\n");

    for (int i = 0; i < networkCount; i++) {
        printf("%s\t%d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    int option = 0;
    char ssid[MAX_SSID_LEN];
    int signal_strength;

    while (true) {
        printf("\nSelect an option:\n");
        printf("1. Add Network\n");
        printf("2. Print Networks\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nEnter SSID: ");
            scanf("%s", ssid);

            printf("Enter Signal Strength (in dBm): ");
            scanf("%d", &signal_strength);

            bool result = addNetwork(ssid, signal_strength);
            if (!result) {
                printf("Could not add network. Maximum number of networks reached.\n");
            } else {
                printf("Network added successfully.\n");
            }
        } else if (option == 2) {
            printNetworks();
        } else if (option == 3) {
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}