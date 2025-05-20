//Code Llama-13B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
// Alien Invasion Probability Calculator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Struct to represent an alien invasion
struct AlienInvasion {
    int num_alien_ships;
    int num_aliens_per_ship;
    int num_humans_defending;
};

// Function to calculate the probability of an alien invasion
float calculate_invasion_probability(struct AlienInvasion invasion) {
    float probability = 0.0;

    // Calculate the total number of aliens
    int num_aliens = invasion.num_alien_ships * invasion.num_aliens_per_ship;

    // Calculate the probability of the aliens winning
    probability = num_aliens / (float) (num_aliens + invasion.num_humans_defending);

    return probability;
}

// Function to print the probability of an alien invasion
void print_invasion_probability(struct AlienInvasion invasion) {
    float probability = calculate_invasion_probability(invasion);
    printf("The probability of an alien invasion is %f\n", probability);
}

// Main function
int main() {
    // Get the number of alien ships, aliens per ship, and humans defending
    printf("Enter the number of alien ships: ");
    int num_alien_ships;
    scanf("%d", &num_alien_ships);

    printf("Enter the number of aliens per ship: ");
    int num_aliens_per_ship;
    scanf("%d", &num_aliens_per_ship);

    printf("Enter the number of humans defending: ");
    int num_humans_defending;
    scanf("%d", &num_humans_defending);

    // Create the alien invasion struct
    struct AlienInvasion invasion = {
        .num_alien_ships = num_alien_ships,
        .num_aliens_per_ship = num_aliens_per_ship,
        .num_humans_defending = num_humans_defending
    };

    // Print the probability of an alien invasion
    print_invasion_probability(invasion);

    return 0;
}