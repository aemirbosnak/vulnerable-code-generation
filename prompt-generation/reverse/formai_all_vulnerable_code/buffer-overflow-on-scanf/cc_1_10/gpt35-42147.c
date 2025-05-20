//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Alien Invasion Probability Calculator */

int main() {

    int num_of_aliens, days_left, survival_chance;
    float random_factor;
    char name[100];

    srand(time(NULL)); // seed random number generator with current time

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("Hello %s! Let's determine your chance of survival in an alien invasion.\n", name);

    printf("Enter the number of aliens that have invaded (1-1000): ");
    scanf("%d", &num_of_aliens);
    
    printf("Enter the number of days until the aliens reach your location (1-30): ");
    scanf("%d", &days_left);

    // calculate random factor based on number of aliens and days left
    if (num_of_aliens > 500 || days_left < 5) {
        random_factor = ((float) rand() / RAND_MAX) * 0.5 + 0.5; // between 0.5 and 1.0
    } else {
        random_factor = ((float) rand() / RAND_MAX) * 0.3 + 0.7; // between 0.7 and 1.0
    }
    
    // calculate survival chance based on random factor and number of aliens
    survival_chance = random_factor * (1000 - num_of_aliens) / 10;

    printf("Calculating your chance of survival...\n");

    // simulate thinking time
    for (int i = 0; i < 5; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    printf("\n\nCongratulations %s, your chance of survival is %d%%!\n", name, survival_chance);

    return 0;
}