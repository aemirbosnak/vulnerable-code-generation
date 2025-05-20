//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_civilizations, num_planets, num_habitable_planets, num_intelligent_civilizations, num_radio_civilizations, num_invasions;
    float distance_to_closest_star, average_distance_between_stars, average_distance_to_nearest_planet, average_distance_to_nearest_habitable_planet, average_distance_to_nearest_intelligent_civilization, average_distance_to_nearest_radio_civilization;
    char choice;
    
    // Initialize variables
    num_civilizations = 0;
    num_planets = 0;
    num_habitable_planets = 0;
    num_intelligent_civilizations = 0;
    num_radio_civilizations = 0;
    num_invasions = 0;
    
    // Prompt user for input
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of civilizations in the galaxy: ");
    scanf("%d", &num_civilizations);
    printf("Please enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);
    printf("Please enter the number of habitable planets in the galaxy: ");
    scanf("%d", &num_habitable_planets);
    printf("Please enter the number of intelligent civilizations in the galaxy: ");
    scanf("%d", &num_intelligent_civilizations);
    
    // Calculate probability of invasion
    num_radio_civilizations = num_intelligent_civilizations * 0.1;
    if (num_radio_civilizations == 0) {
        num_radio_civilizations = 1;
    }
    average_distance_to_nearest_planet = (float)num_planets / (float)(num_civilizations * num_planets);
    average_distance_to_nearest_habitable_planet = (float)num_habitable_planets / (float)(num_civilizations * num_habitable_planets);
    average_distance_to_nearest_intelligent_civilization = (float)num_intelligent_civilizations / (float)(num_civilizations * num_intelligent_civilizations);
    average_distance_to_nearest_radio_civilization = (float)num_radio_civilizations / (float)(num_civilizations * num_radio_civilizations);
    
    // Calculate probability of invasion
    printf("The probability of an invasion by an intelligent civilization is %f.\n", (float)num_intelligent_civilizations / (float)num_civilizations);
    printf("The probability of an invasion by a radio-capable civilization is %f.\n", (float)num_radio_civilizations / (float)num_civilizations);
    
    // Ask user if they want to run simulation
    printf("Would you like to run a simulation? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        srand(time(NULL));
        int num_invasions_simulated = 0;
        for (int i = 0; i < num_civilizations; i++) {
            if (rand() % 100 <= 50) { // 50% chance of invasion
                num_invasions_simulated++;
            }
        }
        printf("In %d simulations, there were %d invasions.\n", num_civilizations, num_invasions_simulated);
    }
    
    return 0;
}