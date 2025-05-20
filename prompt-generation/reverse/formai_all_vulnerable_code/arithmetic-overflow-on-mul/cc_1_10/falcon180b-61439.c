//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate an alien invasion and determine the probability of success
int simulate_invasion(int num_aliens, int num_defenders, int alien_strength, int defender_strength) {
    int num_battles = 0;
    int num_wins = 0;

    // Simulate battles until one side is defeated
    while (num_aliens > 0 && num_defenders > 0) {
        num_battles++;
        int alien_win = rand_range(0, 100) < (100 - defender_strength + alien_strength);
        if (alien_win) {
            num_defenders -= rand_range(1, 3);
            num_aliens -= rand_range(1, 3);
            num_wins++;
        } else {
            num_aliens -= rand_range(1, 3);
        }
    }

    // Calculate and return the probability of success
    if (num_aliens == 0) {
        return 100;
    } else {
        return (100 - (100 * num_battles / num_wins)) / (100 - num_aliens * defender_strength / num_defenders);
    }
}

int main() {
    srand(time(NULL));

    // Get user input for number of aliens and defenders, and their strengths
    int num_aliens, num_defenders, alien_strength, defender_strength;
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);
    printf("Enter the number of defenders: ");
    scanf("%d", &num_defenders);
    printf("Enter the strength of the aliens (1-100): ");
    scanf("%d", &alien_strength);
    printf("Enter the strength of the defenders (1-100): ");
    scanf("%d", &defender_strength);

    // Simulate the alien invasion and determine the probability of success
    int invasion_probability = simulate_invasion(num_aliens, num_defenders, alien_strength, defender_strength);

    // Print the results
    printf("Probability of a successful alien invasion: %.2f%%\n", invasion_probability);

    return 0;
}