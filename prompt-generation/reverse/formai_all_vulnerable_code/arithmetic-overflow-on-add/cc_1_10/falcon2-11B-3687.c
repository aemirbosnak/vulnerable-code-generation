//Falcon2-11B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int num_aliens = 0;
    int num_ships = 0;
    int alien_probability = 0.5;
    int ship_probability = 0.5;
    int max_aliens = 1000;
    int max_ships = 1000;
    int num_trials = 1000000;
    
    // Initialize random number generator
    srand(time(NULL));
    
    // Run simulation
    for (int i = 0; i < num_trials; i++) {
        // Generate number of aliens
        int num_aliens_in_system = (int) (max_aliens * alien_probability * rand() / (RAND_MAX + 1));
        
        // Generate number of ships
        int num_ships_in_system = (int) (max_ships * ship_probability * rand() / (RAND_MAX + 1));
        
        // Determine if system is invaded
        int invasion_result = 0;
        if (num_aliens_in_system > num_ships_in_system) {
            invasion_result = 1;
        } else if (num_ships_in_system > num_aliens_in_system) {
            invasion_result = 0;
        }
        
        // Update probabilities
        if (invasion_result == 1) {
            num_aliens++;
            alien_probability += 0.01;
        } else if (invasion_result == 0) {
            num_ships++;
            ship_probability += 0.01;
        }
        
        // Check for maximum number of aliens or ships
        if (num_aliens > max_aliens) {
            num_aliens = max_aliens;
        }
        if (num_ships > max_ships) {
            num_ships = max_ships;
        }
    }
    
    // Calculate invasion probability
    double invasion_probability = (double) num_aliens / num_trials;
    
    // Print results
    printf("Alien Invasion Probability: %.2f%%\n", 100 * invasion_probability);
    printf("Number of Aliens: %d\n", num_aliens);
    printf("Number of Ships: %d\n", num_ships);
    printf("Alien Probability: %.2f%%\n", 100 * alien_probability);
    printf("Ship Probability: %.2f%%\n", 100 * ship_probability);
    
    return 0;
}