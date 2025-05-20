//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNALS 20

struct AccessPoint {
    char ssid[20];
    int signalStrength;
};

struct AccessPoint signals[MAX_SIGNALS];

void displaySignal(int signalStrength) {
    for (int i = 0; i < signalStrength; i++) {
        printf("|");
    }
    printf("\n");
}

void displaySignalStrengths(struct AccessPoint signals[], int count) {
    printf("\n");
    for(int i = 0; i < count; i++) {
        printf("%s: ", signals[i].ssid);
        displaySignal(signals[i].signalStrength);
    }
    printf("\n");
}

void sortSignalStrengths(struct AccessPoint signals[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (signals[j].signalStrength < signals[j+1].signalStrength) {
                struct AccessPoint temp = signals[j];
                signals[j] = signals[j+1];
                signals[j+1] = temp;
            }
        }
    }
}

int main() {
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    int count;
    printf("Enter the number of access points: ");
    scanf("%d", &count);

    if (count > MAX_SIGNALS) {
        printf("Maximum number of access points exceeded. Exiting...\n");
        return -1;
    }

    for(int i = 0; i < count; i++) {
        printf("Enter SSID of access point %d: ", i+1);
        scanf("%s", signals[i].ssid);
        printf("Enter signal strength of access point %d: ", i+1);
        scanf("%d", &signals[i].signalStrength);
    }

    sortSignalStrengths(signals, count);

    displaySignalStrengths(signals, count);

    return 0;
}