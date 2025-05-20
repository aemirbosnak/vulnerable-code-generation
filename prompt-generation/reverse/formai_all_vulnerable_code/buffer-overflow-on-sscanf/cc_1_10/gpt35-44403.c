//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNALS 50

// A structure to hold the data of a WiFi network signal
struct SignalInfo {
    char ssid[20];
    int signal_strength;
};

// A function to sort an array of SignalInfo structures based on signal strength
void sortSignals(struct SignalInfo signals[], int numSignals) {
    struct SignalInfo temp;
    int i, j;

    for (i = 0; i < numSignals-1; i++) {
        for (j = i+1; j < numSignals; j++) {
            if (signals[i].signal_strength < signals[j].signal_strength) {
                temp = signals[i];
                signals[i] = signals[j];
                signals[j] = temp;
            }
        }
    }
}

int main() {
    struct SignalInfo signals[MAX_SIGNALS];
    int numSignals = 0;

    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("==============================\n");

    // Read in signal data from file
    FILE* fp = fopen("signals.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open signals.txt\n");
        return 1;
    }
    char line[50];
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into SSID and signal strength
        char ssid[20];
        int signal_strength;
        sscanf(line, "%s %d", ssid, &signal_strength);

        // Store the signal data in a SignalInfo structure and add it to the array
        struct SignalInfo signal;
        strcpy(signal.ssid, ssid);
        signal.signal_strength = signal_strength;
        signals[numSignals] = signal;
        numSignals++;
    }
    fclose(fp);

    // Sort the signals based on signal strength
    sortSignals(signals, numSignals);

    // Print out the sorted signals
    printf("Signal Strengths (strongest to weakest)\n");
    printf("---------------------------------------\n");
    int i;
    for (i = 0; i < numSignals; i++) {
        printf("%d. %s: %d dBm\n", i+1, signals[i].ssid, signals[i].signal_strength);
    }

    return 0;
}