//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Function prototypes
void generate_random_sequence(char *sequence, int length);
void print_sequence(const char *sequence, int length);
float calculate_gc_content(const char *sequence, int length);
void introduce_mutation(char *sequence, int length, float mutation_rate);
void perform_sequencing_simulation(int num_sequences, int sequence_length, float mutation_rate);

int main() {
    srand(time(NULL)); // Seed for random number generation

    int num_sequences;
    int sequence_length;
    float mutation_rate;

    // User input for sequencing parameters
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &num_sequences);
    printf("Enter the length of each sequence: ");
    scanf("%d", &sequence_length);
    printf("Enter the mutation rate (0.0 to 1.0): ");
    scanf("%f", &mutation_rate);

    // Perform the sequencing simulation
    perform_sequencing_simulation(num_sequences, sequence_length, mutation_rate);

    return 0;
}

// Generate a random DNA sequence
void generate_random_sequence(char *sequence, int length) {
    const char nucleotides[] = {A, C, G, T};
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4]; // Randomly select a nucleotide
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Print the generated sequence
void print_sequence(const char *sequence, int length) {
    printf("%s\n", sequence);
}

// Calculate the GC content of the sequence
float calculate_gc_content(const char *sequence, int length) {
    int gc_count = 0;
    for (int i = 0; i < length; i++) {
        if (sequence[i] == G || sequence[i] == C) {
            gc_count++;
        }
    }
    return (float)gc_count / length * 100; // Return percentage
}

// Introduce mutations into the DNA sequence
void introduce_mutation(char *sequence, int length, float mutation_rate) {
    for (int i = 0; i < length; i++) {
        if ((float)rand() / RAND_MAX < mutation_rate) {
            // Mutate the nucleotide
            char original_nucleotide = sequence[i];
            char new_nucleotide;
            do {
                new_nucleotide = (rand() % 4) + 'A'; // New random nucleotide
            } while (new_nucleotide == original_nucleotide); // Ensure it's different
            sequence[i] = new_nucleotide; // Apply mutation
        }
    }
}

// Perform the sequencing simulation
void perform_sequencing_simulation(int num_sequences, int sequence_length, float mutation_rate) {
    char *sequence = (char *)malloc((sequence_length + 1) * sizeof(char));
    if (sequence == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < num_sequences; i++) {
        // Generate a new random sequence
        generate_random_sequence(sequence, sequence_length);
        printf("Original Sequence %d: ", i + 1);
        print_sequence(sequence, sequence_length);

        // Calculate and display the GC content
        float gc_content = calculate_gc_content(sequence, sequence_length);
        printf("GC Content: %.2f%%\n", gc_content);

        // Introduce mutations
        introduce_mutation(sequence, sequence_length, mutation_rate);
        printf("Mutated Sequence %d: ", i + 1);
        print_sequence(sequence, sequence_length);

        // Calculate and display the new GC content
        gc_content = calculate_gc_content(sequence, sequence_length);
        printf("New GC Content: %.2f%%\n", gc_content);

        printf("\n"); // Blank line between sequences
    }

    free(sequence); // Clean up memory
}