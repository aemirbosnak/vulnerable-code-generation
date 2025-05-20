//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the probability of alien invasion
float calculateInvasionProbability(int sightings, int technology, int resources) {
    // A mock formula to determine invasion probability
    return (float)(sightings * technology) / (resources + 1);
}

// Function to simulate alien invasion scenarios
void simulateInvasionScenarios() {
    int sightings, technology, resources;
    float probability;
    srand(time(0)); // Seed for randomness

    // Loop to generate random scenarios
    for (int i = 0; i < 5; i++) {
        // Randomly generate values for sightings, technology level, and resources
        sightings = rand() % 100;       // Random sightings between 0 to 99
        technology = rand() % 50 + 1;   // Random technology level between 1 to 50
        resources = rand() % 100 + 1;   // Random resources between 1 to 100

        // Calculate probability
        probability = calculateInvasionProbability(sightings, technology, resources);

        printf("Scenario %d: Sighting=%d, Technology=%d, Resources=%d\n", 
            i + 1, sightings, technology, resources);
        printf("Invasion Probability: %.2f%%\n", probability * 100);
        printf("------------------------\n");
    }
}

int main() {
    int user_sightings, user_technology, user_resources;
    float invasion_probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    // Gather user inputs
    printf("Enter the number of alien sightings reported: ");
    scanf("%d", &user_sightings);
    
    printf("On a scale of 1 to 50, how advanced is Earth’s technology (1 being very basic, 50 being hyper-advanced)? ");
    scanf("%d", &user_technology);
    
    printf("Rate the Earth's resources in your opinion (1 to 100): ");
    scanf("%d", &user_resources);

    // Calculate invasion probability based on user input
    invasion_probability = calculateInvasionProbability(user_sightings, user_technology, user_resources);
    
    // Display the result of user-defined inputs
    printf("\nBased on your inputs:\n");
    printf("Sightings: %d, Technology Level: %d, Resources: %d\n", 
        user_sightings, user_technology, user_resources);
    printf("The calculated probability of an alien invasion is: %.2f%%\n", invasion_probability * 100);

    // Let's explore some scenarios for fun!
    printf("\nWould you like to see some randomly simulated invasion scenarios? (1 for Yes, 0 for No): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Generating random invasion scenarios...\n");
        simulateInvasionScenarios();
    } else {
        printf("Thank you for using the Alien Invasion Probability Calculator! Stay safe!\n");
    }

    return 0;
}