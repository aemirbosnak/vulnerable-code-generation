//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float calculateProbability(int ufoSightings, int conspiracyTheories, int historicalEvents);
void displayResult(float probability);

int main() {
    int ufoSightings, conspiracyTheories, historicalEvents;
    char repeat;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    do {
        // Gather user inputs
        printf("Enter the number of UFO sightings reported in your area: ");
        scanf("%d", &ufoSightings);
        
        printf("Enter the number of conspiracy theories you know about (scale 0-10): ");
        scanf("%d", &conspiracyTheories);
        
        printf("Enter the number of significant historical events related to aliens (e.g., Roswell, Area 51): ");
        scanf("%d", &historicalEvents);
        
        // Calculate the probability
        float invasionProbability = calculateProbability(ufoSightings, conspiracyTheories, historicalEvents);
        
        // Display the result
        displayResult(invasionProbability);
        
        // Ask the user if they want to run the calculator again
        printf("Would you like to check again? (y/n): ");
        scanf(" %c", &repeat);
        
    } while (repeat == 'y' || repeat == 'Y');

    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe!\n");
    return 0;
}

float calculateProbability(int ufoSightings, int conspiracyTheories, int historicalEvents) {
    // A simple formula to calculate the probability score
    float probability = (ufoSightings * 0.4) + (conspiracyTheories * 0.5) + (historicalEvents * 0.3);
    
    // Normalize the probability to be between 0 and 100
    if (probability > 100) {
        probability = 100;
    }
    
    return probability;
}

void displayResult(float probability) {
    printf("\n=====================================\n");
    printf("Alien Invasion Probability Score: %.2f%%\n", probability);

    if (probability < 20) {
        printf("Unlikely! You're safe for now.\n");
    } else if (probability < 50) {
        printf("Possible, but no need to panic!\n");
    } else if (probability < 80) {
        printf("High chance! Prepare for contact!\n");
    } else {
        printf("Extreme risk! Aliens are coming!\n");
    }
    
    printf("=====================================\n\n");
}