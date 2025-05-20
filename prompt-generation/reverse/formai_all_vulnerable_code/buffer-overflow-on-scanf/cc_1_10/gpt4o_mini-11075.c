//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define MAX_SEQUENCE 100
#define BASES "ACGT"

// Function prototypes
void generate_dna_sequence(char *sequence, int length);
void mutate_sequence(char *sequence, int mutations);
void print_sequences(char sequences[MAX_SEQUENCE][SEQUENCE_LENGTH], int count);
void save_sequences_to_file(char sequences[MAX_SEQUENCE][SEQUENCE_LENGTH], int count, const char *filename);

int main() {
    srand(time(NULL));

    char sequences[MAX_SEQUENCE][SEQUENCE_LENGTH];
    int sequence_count;
    int i, mutations;

    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Please enter the number of sequences to generate (max %d): ", MAX_SEQUENCE);
    scanf("%d", &sequence_count);

    if (sequence_count < 1 || sequence_count > MAX_SEQUENCE) {
        fprintf(stderr, "Invalid number of sequences! Exiting...\n");
        return 1;
    }

    printf("Generating %d DNA sequences of length %d...\n", sequence_count, SEQUENCE_LENGTH);
    
    for (i = 0; i < sequence_count; i++) {
        generate_dna_sequence(sequences[i], SEQUENCE_LENGTH);
        printf("Sequence %d generated: %s\n", i + 1, sequences[i]);
        
        // Ask for mutations
        printf("Enter number of mutations for sequence %d: ", i + 1);
        scanf("%d", &mutations);
        
        if (mutations < 0) {
            fprintf(stderr, "Number of mutations cannot be negative! Skipping mutations for this sequence.\n");
            continue;
        }

        mutate_sequence(sequences[i], mutations);
        printf("Mutated Sequence %d: %s\n", i + 1, sequences[i]);
    }

    // Save sequences to file
    save_sequences_to_file(sequences, sequence_count, "dna_sequences.txt");
    printf("All sequences have been saved to dna_sequences.txt\n");

    return 0;
}

void generate_dna_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = BASES[rand() % 4]; // Randomly select a base from A, C, G, T
    }
    sequence[length] = '\0'; // Null terminate the sequence string
}

void mutate_sequence(char *sequence, int mutations) {
    for (int i = 0; i < mutations; i++) {
        int position = rand() % SEQUENCE_LENGTH; // Random position to mutate
        char new_base;

        // Generate a new base that is different from the current one
        do {
            new_base = BASES[rand() % 4];
        } while (new_base == sequence[position]);

        sequence[position] = new_base; // Mutate the sequence
    }
}

void print_sequences(char sequences[MAX_SEQUENCE][SEQUENCE_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

void save_sequences_to_file(char sequences[MAX_SEQUENCE][SEQUENCE_LENGTH], int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file for writing! Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Sequence %d: %s\n", i + 1, sequences[i]);
    }

    fclose(file);
}