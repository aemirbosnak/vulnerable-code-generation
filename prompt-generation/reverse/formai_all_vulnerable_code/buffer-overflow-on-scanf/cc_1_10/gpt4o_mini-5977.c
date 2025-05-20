//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_PROBABILITY 100
#define MAX_ATTEMPTS 50

// Function to simulate the alien invasion probability
float calculate_probability(int attempts, int success_count) {
    return (float)success_count / attempts * MAX_PROBABILITY;
}

// Function to generate a random integer
int random_integer(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Structure to hold alien invasion details
typedef struct {
    int attempt_id;
    int successful;
    float probability;
} InvasionAttempt;

// Function to initiate the invasion probability calculation
void initiate_invasion(int attempts) {
    InvasionAttempt *attempts_array = malloc(attempts * sizeof(InvasionAttempt));
    if (attempts_array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int success_count = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Simulate multiple invasion attempts
    printf("Simulating alien invasion attempts...\n");

    for (int i = 0; i < attempts; i++) {
        attempts_array[i].attempt_id = i + 1;
        attempts_array[i].successful = random_integer(0, 1); // 0 = failed, 1 = succeeded

        if (attempts_array[i].successful) {
            success_count++;
        }

        attempts_array[i].probability = calculate_probability(i + 1, success_count);
        printf("Attempt %d: %s (Probability: %.2f%%)\n", 
            attempts_array[i].attempt_id, 
            attempts_array[i].successful ? "Successful" : "Failed", 
            attempts_array[i].probability);
    }

    // Final summary
    float final_probability = calculate_probability(attempts, success_count);
    printf("\nFinal Probability of Alien Invasion Success: %.2f%%\n", final_probability);

    // Freeing up the allocated memory
    free(attempts_array);
}

// The main driver code
int main() {
    int attempts;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of invasion attempts (1 - %d): ", MAX_ATTEMPTS);
    
    // Input Validation
    while (1) {
        scanf("%d", &attempts);
        if (attempts < 1 || attempts > MAX_ATTEMPTS) {
            printf("Invalid number! Please enter a value between 1 and %d: ", MAX_ATTEMPTS);
        } else {
            break;
        }
    }

    // Start the invasion probability simulation
    initiate_invasion(attempts);

    return 0;
}