//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printHeader() {
    printf("\nWelcome to the C Wireless Network Scanner - A Sherlock Holmes Style Program!\n\n");
}

void printInstructions() {
    printf("Please enter the number of networks you would like to scan: ");
}

void printSummary(int numNetworks) {
    printf("\n\nSummary:\n");
    printf("Scanned %d wireless networks\n", numNetworks);
    printf("Found 5 unsecured networks\n\n");
}

void printNetworkInfo(char* networkName, int isSecure) {
    printf("Network: %s\n", networkName);
    if(isSecure) {
        printf("This network is secure\n");
    } else {
        printf("This network is not secure\n");
    }
    printf("--------------------------\n");
}

int generateSecure(int max) {
    srand(time(NULL));
    return rand() % max;
}

void scanNetworks(int numNetworks) {
    char networkName[50];
    int isSecure;
    int numUnsecured = 0;

    for(int i = 0; i < numNetworks; i++) {
        sprintf(networkName, "Network %d", i + 1);
        isSecure = generateSecure(2);
        printNetworkInfo(networkName, isSecure);
        if(!isSecure) {
            numUnsecured++;
        }
    }

    printSummary(numNetworks);
}

int main() {
    printHeader();
    printInstructions();

    int numNetworks;
    scanf("%d", &numNetworks);

    scanNetworks(numNetworks);

    return 0;
}