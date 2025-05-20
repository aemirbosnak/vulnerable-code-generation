//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible outcomes of an alien invasion
enum invasion_outcome {
    INVASION_SUCCESS,
    INVASION_FAILURE,
    INVASION_UNKNOWN
};

// Define the factors that affect the probability of an alien invasion
enum invasion_factor {
    FACTOR_TECHNOLOGY,
    FACTOR_MOTIVATION,
    FACTOR_DEFENSES
};

// Define the range of values for each factor
#define MIN_FACTOR 0
#define MAX_FACTOR 10

// Define the weight of each factor in the probability calculation
#define WEIGHT_TECHNOLOGY 0.5
#define WEIGHT_MOTIVATION 0.3
#define WEIGHT_DEFENSES 0.2

// Generate a random number between min and max
int rand_range(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Calculate the probability of an alien invasion based on the given factors
enum invasion_outcome calculate_invasion_probability(int technology, int motivation, int defenses) {
    // Calculate the weighted average of the factors
    double weighted_average = (technology * WEIGHT_TECHNOLOGY) + (motivation * WEIGHT_MOTIVATION) + (defenses * WEIGHT_DEFENSES);

    // Convert the weighted average to a probability
    double probability = weighted_average / (MAX_FACTOR * 3);

    // Determine the invasion outcome based on the probability
    if (probability >= 0.5) {
        return INVASION_SUCCESS;
    } else if (probability < 0.5) {
        return INVASION_FAILURE;
    } else {
        return INVASION_UNKNOWN;
    }
}

// Get the user's input for the invasion factors
void get_user_input(int *technology, int *motivation, int *defenses) {
    printf("Enter the level of alien technology (0-10): ");
    scanf("%d", technology);

    printf("Enter the level of alien motivation (0-10): ");
    scanf("%d", motivation);

    printf("Enter the level of human defenses (0-10): ");
    scanf("%d", defenses);
}

// Print the invasion outcome
void print_invasion_outcome(enum invasion_outcome outcome) {
    switch (outcome) {
        case INVASION_SUCCESS:
            printf("The aliens have successfully invaded Earth.\n");
            break;
        case INVASION_FAILURE:
            printf("The aliens have failed to invade Earth.\n");
            break;
        case INVASION_UNKNOWN:
            printf("The outcome of the alien invasion is unknown.\n");
            break;
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the user's input for the invasion factors
    int technology, motivation, defenses;
    get_user_input(&technology, &motivation, &defenses);

    // Calculate the probability of an alien invasion
    enum invasion_outcome outcome = calculate_invasion_probability(technology, motivation, defenses);

    // Print the invasion outcome
    print_invasion_outcome(outcome);

    return 0;
}