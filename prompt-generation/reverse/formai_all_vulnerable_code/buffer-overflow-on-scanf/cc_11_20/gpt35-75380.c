//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNALS 10
#define MAX_NAME_LENGTH 20

struct wifi_signal {
    char name[MAX_NAME_LENGTH];
    int signal_strength;
};

int main() {

    struct wifi_signal signals[MAX_SIGNALS];
    char name_input[MAX_NAME_LENGTH];
    int strength_input;
    int num_signals = 0;

    printf("Welcome to the WiFi Signal Strength Analyzer!\n\n");
    printf("Please enter up to %d WiFi signals and their strength (1-100).\n", MAX_SIGNALS);
    printf("Enter \"quit\" for signal name to exit program.\n");

    while (num_signals < MAX_SIGNALS) {
        printf("Enter signal name: ");
        scanf("%s", name_input);

        if (strcmp(name_input, "quit") == 0) {
            break;
        }

        printf("Enter signal strength (1-100): ");
        scanf("%d", &strength_input);

        if (strength_input < 1 || strength_input > 100) {
            printf("Invalid signal strength. Please enter a value between 1 and 100.\n");
            continue;
        }

        strcpy(signals[num_signals].name, name_input);
        signals[num_signals].signal_strength = strength_input;
        num_signals++;

        printf("\n");
    }

    if (num_signals == 0) {
        printf("No signals entered. Exiting program.\n");
        return 0;
    }

    printf("\n");

    // Calculate average signal strength
    int total_strength = 0;
    for (int i = 0; i < num_signals; i++) {
        total_strength += signals[i].signal_strength;
    }
    float average_strength = (float) total_strength / num_signals;
    printf("Average signal strength: %.2f\n", average_strength);

    // Find strongest and weakest signal
    struct wifi_signal strongest_signal = signals[0];
    struct wifi_signal weakest_signal = signals[0];
    for (int i = 1; i < num_signals; i++) {
        if (signals[i].signal_strength > strongest_signal.signal_strength) {
            strongest_signal = signals[i];
        }
        if (signals[i].signal_strength < weakest_signal.signal_strength) {
            weakest_signal = signals[i];
        }
    }
    printf("Strongest signal: %s (%d)\n", strongest_signal.name, strongest_signal.signal_strength);
    printf("Weakest signal: %s (%d)\n", weakest_signal.name, weakest_signal.signal_strength);

    // Calculate standard deviation
    float variance = 0.0;
    for (int i = 0; i < num_signals; i++) {
        variance += pow(signals[i].signal_strength - average_strength, 2);
    }
    variance /= num_signals;
    float standard_deviation = sqrt(variance);
    printf("Standard deviation: %.2f\n", standard_deviation);

    return 0;
}