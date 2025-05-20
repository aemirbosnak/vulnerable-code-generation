//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN_SIGNAL_STRENGTH 60
#define MAX_SIGNAL_STRENGTH 100
#define NUMBER_OF_AP 5

void analyzeSignalStrength(int signalStrength[]) {
    bool isInRange = true;
    for(int i = 0; i < NUMBER_OF_AP; i++) {
        if(signalStrength[i] < MIN_SIGNAL_STRENGTH || signalStrength[i] > MAX_SIGNAL_STRENGTH) {
            isInRange = false;
        }
    }
    if(isInRange) {
        printf("All AP signal strengths are within range.\n");
    } else {
        printf("Some or all AP signal strengths are not within range.\n");
    }
}

void recordSignalStrength(int signalStrength[]) {
    printf("Please input the signal strength of each access point (AP):\n");
    for(int i = 0; i < NUMBER_OF_AP; i++) {
        printf("AP #%d: ", i+1);
        scanf("%d", &signalStrength[i]);
    }
}

void printMenu() {
    printf("\n");
    printf("=== Wi-Fi Signal Strength Analyzer ===\n");
    printf("1. Record AP signal strengths\n");
    printf("2. Analyze signal strengths\n");
    printf("3. Exit\n");
    printf("======================================\n");
    printf("\n");
}

int getChoice() {
    int choice;
    printf("Please input your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int main() {
    int signalStrength[NUMBER_OF_AP];
    bool isRunning = true;

    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");

    while(isRunning) {
        printMenu();
        int choice = getChoice();
        switch(choice) {
            case 1:
                recordSignalStrength(signalStrength);
                break;
            case 2:
                analyzeSignalStrength(signalStrength);
                break;
            case 3:
                printf("Thank you for using Wi-Fi Signal Strength Analyzer!\n");
                isRunning = false;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}