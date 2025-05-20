//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10
#define MAX_MUTATIONS 5

const char NUCLEOTIDES[] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide sequence
void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = NUCLEOTIDES[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to introduce random mutations in a sequence
void mutate_sequence(char *sequence, int max_mutations) {
    int mutations = rand() % (max_mutations + 1);
    for (int i = 0; i < mutations; i++) {
        int position = rand() % strlen(sequence);
        char new_nucleotide;
        do {
            new_nucleotide = NUCLEOTIDES[rand() % 4];
        } while (new_nucleotide == sequence[position]);
        sequence[position] = new_nucleotide;
    }
}

// Function to print the nucleotide sequences
void print_sequences(char sequences[][MAX_SEQUENCE_LENGTH], int count) {
    for (int i = 0; i < count; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    char sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH];
    int sequence_length;

    printf("Enter sequence length (max %d): ", MAX_SEQUENCE_LENGTH - 1);
    scanf("%d", &sequence_length);
    
    if (sequence_length < 1 || sequence_length > MAX_SEQUENCE_LENGTH - 1) {
        fprintf(stderr, "Invalid sequence length. Please enter a value between 1 and %d.\n", MAX_SEQUENCE_LENGTH - 1);
        return EXIT_FAILURE;
    }

    // Generate random sequences
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        generate_random_sequence(sequences[i], sequence_length);
    }

    printf("\nGenerated Sequences:\n");
    print_sequences(sequences, NUM_SEQUENCES);

    // Introduce mutations
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        mutate_sequence(sequences[i], MAX_MUTATIONS);
    }

    printf("\nMutated Sequences:\n");
    print_sequences(sequences, NUM_SEQUENCES);

    return EXIT_SUCCESS;
}