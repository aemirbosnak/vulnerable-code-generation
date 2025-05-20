//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasion_chance; // probability of alien invasion
    int num_of_sightings; // number of alien sightings
    int total_pop; // total population
    int endangered_pop; // population at risk
    int rnd_num; // random number
    char play_again; // whether the user wants to play again

    srand(time(NULL)); // seeding the random number generator with the current time

    do {
        printf("Welcome to the Alien Invasion Probability Calculator\n");

        // Getting user input
        printf("Enter the total population: ");
        scanf("%d", &total_pop);

        printf("Enter the population at risk: ");
        scanf("%d", &endangered_pop);

        printf("Enter the number of reported alien sightings: ");
        scanf("%d", &num_of_sightings);

        // Calculating the invasion chance
        invasion_chance = ((float) num_of_sightings / (float) total_pop) * 100;

        // Generating a random number between 1 and 100
        rnd_num = (rand() % 100) + 1;

        // Checking if the invasion will occur
        if (invasion_chance <= rnd_num) {
            printf("Alien invasion is imminent!\n");
            printf("Evacuate immediately!\n");
        } else {
            printf("No immediate danger of an alien invasion\n");
            printf("But stay alert and report any sightings to the authorities\n");
        }

        // Asking the user if they want to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}