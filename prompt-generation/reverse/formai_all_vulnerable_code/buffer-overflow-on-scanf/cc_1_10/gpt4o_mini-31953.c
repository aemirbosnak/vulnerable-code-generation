//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VARIABLES 5

// Function Declarations
void display_intro();
void request_user_data(double *variables);
double calculate_probability(double *variables);
void display_results(double probability);

int main() {
    display_intro();

    // Variables to hold user input
    double variables[MAX_VARIABLES];

    // Request data from the user
    request_user_data(variables);

    // Calculate the probability of alien invasion
    double probability = calculate_probability(variables);

    // Display the results
    display_results(probability);

    return 0;
}

void display_intro() {
    printf("****************************************************\n");
    printf("** Welcome, dear traveler, to the Alien Invasion **\n");
    printf("** Probability Calculator!                         **\n");
    printf("****************************************************\n");
    printf("In this vast universe, your heart may dance with fear,\n");
    printf("As we unveil the shimmering secrets of the skies.\n");
    printf("Let us embark on this romantic numerical journey,\n");
    printf("And discover the probabilities of visitors from afar.\n\n");
}

void request_user_data(double *variables) {
    printf("Please provide the following mystical variables:\n");

    printf("1. Your belief in extraterrestrial life (0.0 - 1.0): ");
    scanf("%lf", &variables[0]);

    printf("2. The current level of global unrest (0.0 - 1.0): ");
    scanf("%lf", &variables[1]);

    printf("3. The number of telescope observations made (must be >0): ");
    scanf("%lf", &variables[2]);

    printf("4. Media portrayal of UFOs in the past year (0 - 100): ");
    scanf("%lf", &variables[3]);

    printf("5. Your own intuition (0.0 - 1.0): ");
    scanf("%lf", &variables[4]);

    // Constrain the values to proper ranges
    for (int i = 0; i < MAX_VARIABLES; i++) {
        if (i == 3) { // Media portrayal should be between 0 and 100
            if (variables[i] < 0) variables[i] = 0;
            if (variables[i] > 100) variables[i] = 100;
        } else {
            if (variables[i] < 0) variables[i] = 0;
            if (variables[i] > 1) variables[i] = 1;
        }
    }
}

double calculate_probability(double *variables) {
    // A romantic formula where stars align and feelings blend
    double alien_influence = (variables[0] * 0.25) + 
                             (variables[1] * 0.3) + 
                             (variables[2] * 0.15) + 
                             ((variables[3] / 100.0) * 0.2) + 
                             (variables[4] * 0.1);
                             
    // Scale it to a range of 0 to 1
    return (alien_influence > 1) ? 1 : alien_influence;
}

void display_results(double probability) {
    printf("\nAfter an enchanting calculation, the probability of an alien invasion...\n");

    // Romantic flair to the probabilities
    if (probability <= 0.2) {
        printf("is a mere whisper at %.2f. Fear not, for they shall not arrive tonight.\n", probability);
    } else if (probability <= 0.5) {
        printf("is a gentle breeze at %.2f. Perhaps they are merely watching from afar.\n", probability);
    } else if (probability <= 0.8) {
        printf("is a restless tide at %.2f. They fancy your world and may soon come to dance.\n", probability);
    } else {
        printf("is a fiery star at %.2f! They are drawn to your heart's glow, arriving with purpose!\n", probability);
    }
    
    printf("Thank you for partaking in this cosmic exploration. May love and peace prevail.\n");
}