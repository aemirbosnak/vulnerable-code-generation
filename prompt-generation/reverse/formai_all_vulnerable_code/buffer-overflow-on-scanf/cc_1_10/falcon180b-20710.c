//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_OF_PEOPLE 1000000000
#define MAX_NUM_OF_PLANETS 1000000000

typedef struct {
    int num_of_people;
    int num_of_planets;
    int num_of_invasions;
} invasion_probability_t;

invasion_probability_t calculate_invasion_probability(int num_of_people, int num_of_planets) {
    invasion_probability_t result;
    int i;
    int num_of_invasions = 0;

    // Initialize the result structure
    result.num_of_people = num_of_people;
    result.num_of_planets = num_of_planets;
    result.num_of_invasions = num_of_invasions;

    // Simulate the invasion
    for (i = 0; i < num_of_planets; i++) {
        if (rand() % 2 == 0) {
            // The planet is invaded
            num_of_invasions++;
        }
    }

    // Update the result structure
    result.num_of_invasions = num_of_invasions;

    return result;
}

int main() {
    int num_of_people, num_of_planets;
    invasion_probability_t probability;
    int i;

    // Get the number of people and planets from the user
    printf("Enter the number of people: ");
    scanf("%d", &num_of_people);

    printf("Enter the number of planets: ");
    scanf("%d", &num_of_planets);

    // Validate the input
    if (num_of_people <= 0 || num_of_people > MAX_NUM_OF_PEOPLE) {
        printf("Invalid number of people\n");
        return 1;
    }

    if (num_of_planets <= 0 || num_of_planets > MAX_NUM_OF_PLANETS) {
        printf("Invalid number of planets\n");
        return 1;
    }

    // Calculate the invasion probability
    probability = calculate_invasion_probability(num_of_people, num_of_planets);

    // Print the results
    printf("There are %d people and %d planets.\n", num_of_people, num_of_planets);
    printf("The probability of an alien invasion is %d/%d = %.2f%%\n", probability.num_of_invasions, num_of_planets, ((float)probability.num_of_invasions / (float)num_of_planets) * 100.0);

    return 0;
}