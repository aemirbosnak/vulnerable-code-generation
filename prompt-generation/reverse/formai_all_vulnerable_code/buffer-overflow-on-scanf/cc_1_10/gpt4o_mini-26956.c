//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_GENOME_LENGTH 100
#define MUTATION_RATE 0.1 // 10% mutation rate

// Function to randomly generate a DNA sequence
void generate_dna_sequence(char *dna_sequence, int length) {
    const char nucleotides[] = "ACGT";
    for (int i = 0; i < length; i++) {
        dna_sequence[i] = nucleotides[rand() % 4];
    }
    dna_sequence[length] = '\0'; // Null-terminate the string
}

// Function to simulate mutations in a DNA sequence
void simulate_mutations(char *dna_sequence, int length) {
    for (int i = 0; i < length; i++) {
        if ((float)rand() / RAND_MAX < MUTATION_RATE) {
            // Choose a random nucleotide to replace
            const char nucleotides[] = "ACGT";
            char original_nucleotide = dna_sequence[i];
            char new_nucleotide;

            // Ensure that the new nucleotide is different from the original
            do {
                new_nucleotide = nucleotides[rand() % 4];
            } while (new_nucleotide == original_nucleotide);
            
            printf("Mutation: %c -> %c at position %d\n", original_nucleotide, new_nucleotide, i);
            dna_sequence[i] = new_nucleotide; // Apply mutation
        }
    }
}

// Function to print the DNA sequence
void print_dna_sequence(char *dna_sequence) {
    printf("DNA Sequence: %s\n", dna_sequence);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    
    char dna_sequence[MAX_GENOME_LENGTH + 1];
    int sequence_length;

    // Prompt user for length of the genome
    printf("Enter the length of the DNA sequence (up to %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &sequence_length);
    
    if (sequence_length < 1 || sequence_length > MAX_GENOME_LENGTH) {
        printf("Invalid sequence length. Please enter a number between 1 and %d.\n", MAX_GENOME_LENGTH);
        return 1;
    }

    generate_dna_sequence(dna_sequence, sequence_length);
    printf("Generated ");
    print_dna_sequence(dna_sequence);

    // Simulate mutations
    simulate_mutations(dna_sequence, sequence_length);
    printf("After mutations: ");
    print_dna_sequence(dna_sequence);

    return 0;
}