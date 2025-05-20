//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random Wi-Fi signal strength between -100 and 0 dBm
int generate_signal_strength() {
    return rand() % 101 - 100;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int signal_strength = generate_signal_strength(); // generate initial signal strength

    printf("Initial Wi-Fi signal strength: %d dBm\n", signal_strength);

    while (1) { // loop forever
        int menu_choice = 0;

        printf("\nWi-Fi Signal Strength Analyzer Menu:\n");
        printf("1. Generate new signal strength\n");
        printf("2. Analyze signal strength\n");
        printf("3. Exit\n");
        printf("Enter a choice [1-3]: ");
        scanf("%d", &menu_choice);

        if (menu_choice == 1) { // generate new signal strength
            signal_strength = generate_signal_strength();
            printf("\nNew Wi-Fi signal strength generated: %d dBm\n", signal_strength);
        }
        else if (menu_choice == 2) { // analyze signal strength
            if (signal_strength >= -50) {
                printf("\nSignal strength is excellent.\n");
            }
            else if (signal_strength >= -60) {
                printf("\nSignal strength is good.\n");
            }
            else if (signal_strength >= -70) {
                printf("\nSignal strength is fair.\n");
            }
            else if (signal_strength >= -80) {
                printf("\nSignal strength is poor.\n");
            }
            else {
                printf("\nSignal strength is very poor.\n");
            }
        }
        else if (menu_choice == 3) { // exit program
            printf("\nExiting Wi-Fi Signal Strength Analyzer.\n");
            break;
        }
        else { // invalid menu choice
            printf("\nInvalid menu choice. Please try again.\n");
        }
    }

    return 0;
}