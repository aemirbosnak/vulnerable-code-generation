//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define the probability distribution parameters
    double lambda = 0.0001;  // Arrival rate of alien spacecraft per year
    double gamma = 0.00001; // Probability of an alien spacecraft causing a major disaster
    double delta = 0.000001; // Probability of an alien spacecraft being detected and destroyed

    // Get the number of years to simulate
    int num_years;
    printf("Enter the number of years to simulate: ");
    scanf("%d", &num_years);

    // Initialize the simulation variables
    int num_arrivals = 0; // Number of alien spacecraft arrivals
    int num_disasters = 0; // Number of major disasters caused by alien spacecraft
    int num_detected = 0; // Number of alien spacecraft detected and destroyed

    // Simulate the alien invasion
    for (int i = 0; i < num_years; i++) {
        // Generate a random number to determine if an alien spacecraft arrives
        double u = (double)rand() / (double)RAND_MAX;
        if (u < lambda) {
            num_arrivals++;

            // Generate a random number to determine if the alien spacecraft causes a major disaster
            u = (double)rand() / (double)RAND_MAX;
            if (u < gamma) {
                num_disasters++;
            }

            // Generate a random number to determine if the alien spacecraft is detected and destroyed
            u = (double)rand() / (double)RAND_MAX;
            if (u < delta) {
                num_detected++;
            }
        }
    }

    // Calculate the probability of an alien invasion
    double invasion_probability = (double)num_disasters / (double)num_arrivals;

    // Print the simulation results
    printf("Number of alien spacecraft arrivals: %d\n", num_arrivals);
    printf("Number of major disasters caused by alien spacecraft: %d\n", num_disasters);
    printf("Number of alien spacecraft detected and destroyed: %d\n", num_detected);
    printf("Probability of an alien invasion: %f\n", invasion_probability);

    return 0;
}