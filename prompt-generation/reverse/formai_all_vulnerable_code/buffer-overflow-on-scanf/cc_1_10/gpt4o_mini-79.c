//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10
#define BASES "ACGT"

// Function to generate a random DNA sequence
void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; ++i) {
        sequence[i] = BASES[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to print a DNA sequence
void print_sequence(const char *sequence) {
    printf("%s\n", sequence);
}

// Function to simulate DNA sequencing using simple random sampling
void simulate_sequencing(const char *original_sequence, char *sequenced_result, int length) {
    for (int i = 0; i < length; ++i) {
        sequenced_result[i] = original_sequence[rand() % strlen(original_sequence)];
    }
    sequenced_result[length] = '\0'; // Null-terminate the string
}

// Main function to run the simulation
int main() {
    srand(time(NULL)); // Seed the random number generator

    char original_sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH];
    char sequenced_results[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH];
    int sequence_length;

    // Read sequence length from user
    printf("Enter DNA sequence length (1-%d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);
    if (sequence_length < 1 || sequence_length > MAX_SEQUENCE_LENGTH) {
        fprintf(stderr, "Invalid sequence length. Exiting...\n");
        return 1;
    }

    // Generate random original sequences
    for (int i = 0; i < NUM_SEQUENCES; ++i) {
        generate_random_sequence(original_sequences[i], sequence_length);
        printf("Original Sequence %d: ", i + 1);
        print_sequence(original_sequences[i]);
    }

    // Simulate sequencing for each original sequence
    for (int i = 0; i < NUM_SEQUENCES; ++i) {
        simulate_sequencing(original_sequences[i], sequenced_results[i], sequence_length);
        printf("Sequenced Result %d: ", i + 1);
        print_sequence(sequenced_results[i]);
    }

    // Compare original and sequenced results
    for (int i = 0; i < NUM_SEQUENCES; ++i) {
        printf("Comparing Sequence %d:\n", i + 1);
        printf("Original: %s\n", original_sequences[i]);
        printf("Sequenced: %s\n", sequenced_results[i]);
        
        int matches = 0;
        for (int j = 0; j < sequence_length; ++j) {
            if (original_sequences[i][j] == sequenced_results[i][j]) {
                matches++;
            }
        }
        
        printf("Matched Bases: %d out of %d\n", matches, sequence_length);
        printf("\n");
    }

    return 0;
}