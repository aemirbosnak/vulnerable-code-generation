//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate an alien invasion and calculate the probability of success
int simulate_invasion(int num_aliens, int num_humans, int alien_strength, int human_strength) {
    int num_killed_humans = 0;
    int num_killed_aliens = 0;

    // Simulate the battle between aliens and humans
    for (int i = 0; i < num_aliens; i++) {
        for (int j = 0; j < num_humans; j++) {
            int alien_attack = rand_int(1, alien_strength);
            int human_defense = rand_int(1, human_strength);

            if (alien_attack > human_defense) {
                num_killed_humans++;
            } else if (human_defense > alien_attack) {
                num_killed_aliens++;
            }
        }
    }

    // Calculate the probability of success for the aliens
    double success_probability = ((double) num_killed_humans / num_humans) * 100.0;

    return (int) success_probability;
}

int main() {
    int num_aliens, num_humans, alien_strength, human_strength;

    // Get user input for number of aliens, humans, and strengths
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    printf("Enter the number of humans: ");
    scanf("%d", &num_humans);

    printf("Enter the strength of the aliens (1-100): ");
    scanf("%d", &alien_strength);

    printf("Enter the strength of the humans (1-100): ");
    scanf("%d", &human_strength);

    // Simulate the invasion and print the results
    int success_probability = simulate_invasion(num_aliens, num_humans, alien_strength, human_strength);

    printf("\nThe probability of success for the aliens is %.2f%%\n", success_probability);

    return 0;
}