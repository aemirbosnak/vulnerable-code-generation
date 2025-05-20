//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_OF_READINGS 100 // Number of readings to average
#define NUM_OF_BARS 10 // Number of bars for signal strength

int main() {

    int i, j, k, signal_strength;
    int sum_signal_strength = 0;
    char signal_strength_str[1000];
    char command[1000];
    char output[4096];
    float average_signal_strength;
    int frequency_band;

    // Ask the user for the frequency band
    printf("Enter the frequency band:\n");
    printf("1. 2.4 GHz\n");
    printf("2. 5 GHz\n");
    scanf("%d", &frequency_band);

    // Check if the user entered a valid frequency band
    if(frequency_band != 1 && frequency_band != 2) {
        printf("Invalid option! Exiting.");
        exit(0);
    }

    // Start the Wi-Fi scan
    printf("Starting Wi-Fi scan...\n");

    // Store the Wi-Fi scan output in output variable
    if (frequency_band == 1) {
        // Scan the 2.4 GHz band
        strcpy(command, "sudo iwlist wlan0 scanning channel 1-13 frequency 2.4G | grep Signal");
    } else {
        // Scan the 5 GHz band
        strcpy(command, "sudo iwlist wlan0 scanning channel 36-165 freq 5G | grep Signal");
    }

    // Run the command and store the output in output variable
    FILE* cmdrun = popen(command, "r");
    if (cmdrun == NULL) {
        printf("Unable to run the command!\n");
        exit(0);
    }
    fread(output, sizeof(char), sizeof(output), cmdrun);
    pclose(cmdrun);

    // Parse the output variable to calculate the average signal strength
    for(i = 0; i < NUM_OF_READINGS; i++) {
        // Look for the index of the signal strength in the output variable
        char* signal_strength_index = strstr(output, "Signal level=");
        if (signal_strength_index == NULL) {
            printf("Error in parsing Wi-Fi scan output! Exiting.");
            exit(0);
        }

        // Store the signal strength in signal_strength_str variable
        for (j = 0; j < 1000; j++) {
            if(signal_strength_index[j] == '\n') {
                signal_strength_str[j] = '\0';
                break;
            } else {
                signal_strength_str[j] = signal_strength_index[j];
            }
        }

        // Convert signal strength string to integer
        signal_strength = atoi(signal_strength_str + 14);

        // Add signal strength to sum
        sum_signal_strength += signal_strength;

        // Remove the signal strength reading from output variable
        for (k = 0; k < j; k++) {
            signal_strength_index[k] = ' ';
            output[signal_strength_index - output + k] = ' ';
        }
    }

    // Calculate the average signal strength
    average_signal_strength = (float) sum_signal_strength / NUM_OF_READINGS;

    // Calculate the signal strength bar
    signal_strength = round(average_signal_strength / 10);
    if(signal_strength > NUM_OF_BARS) {
        signal_strength = NUM_OF_BARS;
    }

    // Print the Wi-Fi signal strength
    printf("Wi-Fi signal strength: %.1f dBm - ", average_signal_strength);
    for(i = 0; i < signal_strength; i++) {
        printf("|");
    }
    for(i = 0; i < NUM_OF_BARS - signal_strength; i++) {
        printf(" ");
    }
    printf("|\n");

    return 0;
}