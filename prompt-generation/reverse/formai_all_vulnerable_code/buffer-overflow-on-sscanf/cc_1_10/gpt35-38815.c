//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNALS 1000 // Maximum number of signals to store
#define MAX_SSID_LENGTH 32 // Maximum length of SSID name

// A struct to store Wi-Fi signals
struct wifi_signal {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

// Function to calculate the average signal strength
float calculate_average_signal_strength(struct wifi_signal signals[], int num_signals) {
    int total_strength = 0;
    for (int i = 0; i < num_signals; i++) {
        total_strength += signals[i].signal_strength;
    }
    return (float) total_strength / num_signals;
}

int main() {
    struct wifi_signal signals[MAX_SIGNALS];
    int num_signals = 0; // Number of signals read in

    // Example of reading in signals from a file
    FILE *file = fopen("wifi_signals.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[64];
    while (fgets(line, sizeof(line), file)) {
        char ssid[MAX_SSID_LENGTH];
        int signal_strength;

        // Example format of file: "SSID_name signal_strength"
        if (sscanf(line, "%s %d", ssid, &signal_strength) != 2) {
            fprintf(stderr, "Error reading record\n");
            continue;
        }

        // Create new wifi_signal and add to array
        struct wifi_signal new_signal;
        strncpy(new_signal.ssid, ssid, sizeof(new_signal.ssid)); // Only copy the first MAX_SSID_LENGTH characters of the SSID name
        new_signal.signal_strength = signal_strength;

        if (num_signals < MAX_SIGNALS) {
            signals[num_signals++] = new_signal;
        } else {
            fprintf(stderr, "Cannot store more than %d signals\n", MAX_SIGNALS);
            break;
        }
    }

    fclose(file);

    // Calculate the average signal strength
    float average_strength = calculate_average_signal_strength(signals, num_signals);
    printf("Average signal strength: %.2f dBm\n", average_strength);

    // Identify the SSID with the highest signal strength
    char strongest_ssid[MAX_SSID_LENGTH];
    int strongest_signal = -100; // Initialize to a negative value so any signal read in will be greater
    for (int i = 0; i < num_signals; i++) {
        if (signals[i].signal_strength > strongest_signal) {
            strongest_signal = signals[i].signal_strength;
            strncpy(strongest_ssid, signals[i].ssid, sizeof(strongest_ssid)); // Only copy the first MAX_SSID_LENGTH characters of the SSID name
        }
    }
    printf("SSID with strongest signal: %s (%d dBm)\n", strongest_ssid, strongest_signal);

    // Calculate the standard deviation of the signal strengths
    float signal_strengths[num_signals];
    for (int i = 0; i < num_signals; i++) {
        signal_strengths[i] = signals[i].signal_strength;
    }

    float mean, variance, std_deviation=0;
    int i;
    mean = calculate_average_signal_strength(signals, num_signals);

    for(i=0; i<num_signals; ++i) {
        variance += pow(signal_strengths[i] - mean, 2);
    }
    variance /= num_signals;
    std_deviation = sqrt(variance);
    printf("Standard deviation of signal strengths: %.2f\n", std_deviation);

    return EXIT_SUCCESS;
}