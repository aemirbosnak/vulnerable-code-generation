//FormAI DATASET v1.0 Category: Browser Plugin ; Style: energetic
// EnergyBoost Plugin

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void energyBoost();

// Main function
int main() {

    // Ask the user if they want to activate EnergyBoost
    printf("Would you like to activate EnergyBoost? (y/n)\n");

    // Read the user's response
    char response;
    scanf("%c", &response);

    // Check if the user wants to activate EnergyBoost
    if (response == 'y' || response == 'Y') {
        energyBoost();
    }

    return 0;
}

// Function definition for EnergyBoost
void energyBoost() {

    // Tell the user that EnergyBoost has been activated
    printf("EnergyBoost has been activated!\n");

    // Ask the user how long they want to boost their energy for
    printf("How many minutes would you like to boost your energy for? (min. 1, max. 60)\n");

    // Read the user's input
    int minutes;
    scanf("%d", &minutes);

    // Ensure that the input is within the valid range (1-60)
    if (minutes < 1) {
        minutes = 1;
    } else if (minutes > 60) {
        minutes = 60;
    }

    // Calculate the number of seconds to boost energy for
    int seconds = minutes * 60;

    // Display the countdown timer
    printf("EnergyBoost will last for %d minutes.\n", minutes);
    for (int i = seconds; i > 0; i--) {
        printf("%d seconds remaining...\n", i);
        sleep(1); // Pause for 1 second
    }

    // Tell the user that EnergyBoost has ended
    printf("EnergyBoost has ended. Thanks for using the plugin!\n");
}