//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random base
char random_base() {
    int random_number = rand() % 4;

    switch (random_number) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N'; // Unknown base
    }
}

int main() {
    printf("Welcome to the DNA sequencing simulator!\n\n");

    // Ask user for input
    printf("Enter the length of the genome to simulate: ");
    int genome_length;
    scanf("%d", &genome_length);

    printf("Enter the number of samples to simulate: ");
    int num_samples;
    scanf("%d", &num_samples);

    // Allocate memory for genome
    char *genome = (char*) malloc(genome_length * sizeof(char));

    // Generate random genome sequence
    srand(time(NULL)); // Seed the random number generator
    printf("\nGenerating genome sequence...\n\n");

    for (int i = 0; i < genome_length; i++) {
        genome[i] = random_base();
        printf("%c", genome[i]);
    }

    printf("\n\n");

    // Allocate memory for samples
    char **samples = (char**) malloc(num_samples * sizeof(char*));
    for (int i = 0; i < num_samples; i++) {
        samples[i] = (char*) malloc((genome_length + 1) * sizeof(char));
    }

    // Simulate samples
    printf("Simulating samples...\n\n");

    for (int i = 0; i < num_samples; i++) {
        printf("Sample %d: ", i + 1);

        for (int j = 0; j < genome_length; j++) {
            char base = genome[j];

            // Introduce errors
            int error_chance = rand() % 100;
            if (error_chance < 5) { // 5% chance of error
                do {
                    base = random_base();
                } while (base == genome[j]);
            }

            samples[i][j] = base;
            printf("%c", base);
        }

        samples[i][genome_length] = '\0'; // Add null terminator
        printf("\n");
    }

    printf("\n");

    // Print results
    printf("Results:\n\n");

    for (int i = 0; i < num_samples; i++) {
        printf("Sample %d: %s\n", i + 1, samples[i]);
    }

    // Free memory
    free(genome);
    for (int i = 0; i < num_samples; i++) {
        free(samples[i]);
    }
    free(samples);

    return 0;
}