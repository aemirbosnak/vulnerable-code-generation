//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int signal_strength = 50; // Initialize signal strength to 50
    int option;

    srand(time(NULL)); // Seed for generating random numbers

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");

    do {
        printf("\nCurrent signal strength: %d\n", signal_strength);

        printf("Choose an option:\n");
        printf("1. Scan for Wi-Fi networks\n");
        printf("2. Analyze signal strength of a network\n");
        printf("3. Exit\n");

        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Scanning for Wi-Fi networks...\n");

                // Generate random number between -20 and 20 to simulate change in signal strength
                int change = rand() % 41 - 20;

                signal_strength += change;

                printf("Found %d networks.\n", rand() % 10);
                break;

            case 2:
                if(signal_strength >= 80)
                    printf("The signal strength is excellent.\n");
                else if(signal_strength >= 60)
                    printf("The signal strength is good.\n");
                else if(signal_strength >= 40)
                    printf("The signal strength is average.\n");
                else if(signal_strength >= 20)
                    printf("The signal strength is poor.\n");
                else
                    printf("The signal strength is very poor.\n");
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option.\n");
        }
    } while(option != 3);

    return 0;
}