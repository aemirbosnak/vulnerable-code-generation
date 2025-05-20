//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the results
void print_results(int num_planets, int num_inhabited, int num_intelligent) {
    printf("There are %d planets in the galaxy.\n", num_planets);
    printf("Of these, %d are inhabited.\n", num_inhabited);
    printf("And %d of those have intelligent life.\n", num_intelligent);
}

// Function to simulate the alien invasion
void simulate_invasion(int num_planets, int num_inhabited, int num_intelligent) {
    srand(time(NULL)); // Seed the random number generator
    int num_invaded = 0;
    for (int i = 0; i < num_inhabited; i++) {
        int planet_index = rand_num(0, num_planets - 1);
        if (planet_index < num_intelligent) {
            num_invaded++;
            printf("The aliens have invaded planet %d!\n", planet_index+1);
        }
    }
    printf("The aliens have invaded %d out of %d inhabited planets.\n", num_invaded, num_inhabited);
}

int main() {
    int num_planets, num_inhabited, num_intelligent;

    // Get user input for number of planets
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);

    // Get user input for number of inhabited planets
    printf("Enter the number of inhabited planets: ");
    scanf("%d", &num_inhabited);

    // Get user input for number of intelligent life forms
    printf("Enter the number of intelligent life forms: ");
    scanf("%d", &num_intelligent);

    // Print the results
    print_results(num_planets, num_inhabited, num_intelligent);

    // Simulate the alien invasion
    simulate_invasion(num_planets, num_inhabited, num_intelligent);

    return 0;
}