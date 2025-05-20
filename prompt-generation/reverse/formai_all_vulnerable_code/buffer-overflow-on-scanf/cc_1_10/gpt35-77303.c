//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct for a nucleotide base
typedef struct Nucleotide {
    char base;
    struct Nucleotide* nextNucleotide;
} Nucleotide;

// Define a struct for a sequence of nucleotides
typedef struct NucleotideSequence {
    Nucleotide* head;
    unsigned int length;
} NucleotideSequence;

// Function prototypes
void free_sequence(NucleotideSequence* sequence);
void print_sequence(NucleotideSequence* sequence);
Nucleotide* get_random_base();
void generate_random_sequence(NucleotideSequence* sequence, unsigned int length);
void save_sequence_to_file(NucleotideSequence* sequence, const char* filename);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define variables
    NucleotideSequence* sequence = NULL;
    unsigned int sequence_length;

    // Get sequence length from user input
    printf("Enter sequence length: ");
    scanf("%d", &sequence_length);

    // Create a new empty sequence
    sequence = calloc(1, sizeof(NucleotideSequence));
    sequence->length = sequence_length;

    // Generate a random sequence of nucleotides
    generate_random_sequence(sequence, sequence_length);

    // Print the generated sequence
    printf("Generated sequence:\n");
    print_sequence(sequence);

    // Save the sequence to a file
    save_sequence_to_file(sequence, "sequence.txt");

    // Free the memory used by the sequence
    free_sequence(sequence);

    return 0;
}

// Free memory used by a nucleotide sequence
void free_sequence(NucleotideSequence* sequence) {
    Nucleotide* current_nucleotide = sequence->head;
    Nucleotide* next_nucleotide = NULL;
    while (current_nucleotide != NULL) {
        next_nucleotide = current_nucleotide->nextNucleotide;
        free(current_nucleotide);
        current_nucleotide = next_nucleotide;
    }
    free(sequence);
}

// Print a nucleotide sequence to stdout
void print_sequence(NucleotideSequence* sequence) {
    Nucleotide* current_nucleotide = sequence->head;
    while (current_nucleotide != NULL) {
        printf("%c", current_nucleotide->base);
        current_nucleotide = current_nucleotide->nextNucleotide;
    }
    printf("\n");
}

// Get a random nucleotide base (A/C/G/T)
Nucleotide* get_random_base() {
    char base;
    Nucleotide* nucleotide = calloc(1, sizeof(Nucleotide));
    int random_number = rand() % 4;
    switch (random_number) {
        case 0: base = 'A'; break;
        case 1: base = 'C'; break;
        case 2: base = 'G'; break;
        case 3: base = 'T'; break;
    }
    nucleotide->base = base;
    return nucleotide;    
}

// Generate a random sequence of nucleotides
void generate_random_sequence(NucleotideSequence* sequence, unsigned int length) {
    Nucleotide* current_nucleotide = NULL;
    for (unsigned int i = 0; i < length; i++) {
        // Get a random nucleotide base
        Nucleotide* nucleotide = get_random_base();
        if (i == 0) {
            sequence->head = nucleotide;
            current_nucleotide = nucleotide;
        }
        else {
            current_nucleotide->nextNucleotide = nucleotide;
            current_nucleotide = nucleotide;
        }
    }
}

// Save a nucleotide sequence to a file
void save_sequence_to_file(NucleotideSequence* sequence, const char* filename) {
    FILE* file = fopen(filename, "w");
    Nucleotide* current_nucleotide = sequence->head;
    while (current_nucleotide != NULL) {
        fprintf(file, "%c", current_nucleotide->base);
        current_nucleotide = current_nucleotide->nextNucleotide;
    }
    fclose(file);
}