//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define SEQUENCE_LENGTH 100
#define NUM_SEQUENCES 10
#define BASES "ACGT"

// Function to generate a random nucleotide sequence
void generate_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = BASES[rand() % 4]; // Randomly pick A, C, G, or T
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to simulate error in the sequence
void introduce_error(char *sequence, float error_rate) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if ((float)rand() / RAND_MAX < error_rate) {
            int original_base = strchr(BASES, sequence[i]) - BASES; // Find original base index
            int new_base;
            do {
                new_base = rand() % 4; // Pick a new base
            } while (new_base == original_base); // Ensure it’s different
            sequence[i] = BASES[new_base]; // Replace with new base
        }
    }
}

// Function to print a nucleotide sequence
void print_sequence(char *sequence) {
    printf("Generated Sequence: %s\n", sequence);
}

// Function to write sequences to a file
void write_to_file(char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH + 1]) {
    FILE *file = fopen("sequences.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        fprintf(file, "%s\n", sequences[i]);
    }
    
    fclose(file);
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(float error_rate) {
    char sequences[NUM_SEQUENCES][SEQUENCE_LENGTH + 1];

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        generate_sequence(sequences[i], SEQUENCE_LENGTH);
        introduce_error(sequences[i], error_rate);
        print_sequence(sequences[i]);
    }
    
    write_to_file(sequences);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    float error_rate;

    printf("Enter error rate (0.0 to 1.0): ");
    scanf("%f", &error_rate);
    
    if (error_rate < 0.0 || error_rate > 1.0) {
        fprintf(stderr, "Error rate must be between 0.0 and 1.0\n");
        return EXIT_FAILURE;
    }

    simulate_genome_sequencing(error_rate);

    printf("Sequencing simulation completed. Check 'sequences.txt' for output.\n");
    return EXIT_SUCCESS;
}