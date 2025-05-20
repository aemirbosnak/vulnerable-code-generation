//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCES 100
#define MAX_LENGTH 100
#define BASES "ACGT"

// Function to generate a random DNA sequence of a given length
void generate_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = BASES[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to print the sequences
void print_sequences(char sequences[][MAX_LENGTH + 1], int count) {
    printf("Generated DNA Sequences:\n");
    for (int i = 0; i < count; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

int main() {
    int num_sequences, length;
    char sequences[MAX_SEQUENCES][MAX_LENGTH + 1];

    // Seed the random number generator
    srand(time(NULL));

    // Ask user for the number of sequences and their length
    printf("Enter the number of DNA sequences to generate (max %d): ", MAX_SEQUENCES);
    scanf("%d", &num_sequences);
    
    if (num_sequences > MAX_SEQUENCES || num_sequences <= 0) {
        printf("Error: Please enter a number between 1 and %d.\n", MAX_SEQUENCES);
        return 1;
    }

    printf("Enter the length of each DNA sequence (max %d): ", MAX_LENGTH);
    scanf("%d", &length);

    if (length > MAX_LENGTH || length <= 0) {
        printf("Error: Please enter a length between 1 and %d.\n", MAX_LENGTH);
        return 1;
    }

    // Generate the DNA sequences
    for (int i = 0; i < num_sequences; i++) {
        generate_sequence(sequences[i], length);
    }

    // Print the generated sequences
    print_sequences(sequences, num_sequences);

    return 0;
}