//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUM_NUCLEOTIDES 4

// Function to generate a random nucleotide
char generate_nucleotide(void) {
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    return nucleotides[rand() % 4];
}

// Function to generate a random sequence of nucleotides
char* generate_sequence(int length) {
    char* sequence = malloc(length + 1);
    if (sequence == NULL) {
        printf("Error: Could not allocate memory for sequence.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++) {
        sequence[i] = generate_nucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to print a sequence of nucleotides
void print_sequence(char* sequence) {
    printf("%s\n", sequence);
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(char* sequence, int num_errors) {
    int i;
    for (i = 0; i < strlen(sequence); i++) {
        int error_position = rand() % strlen(sequence);
        if (error_position == i) {
            continue;
        }
        char error_nucleotide = generate_nucleotide();
        sequence[error_position] = error_nucleotide;
    }
}

int main(void) {
    srand(time(NULL));

    // Prompt the user for sequence length and number of errors
    int sequence_length;
    int num_errors;
    printf("Enter the length of the sequence: ");
    scanf("%d", &sequence_length);
    printf("Enter the number of errors to introduce: ");
    scanf("%d", &num_errors);

    // Generate the original sequence
    char* original_sequence = generate_sequence(sequence_length);
    printf("Original sequence:\n");
    print_sequence(original_sequence);

    // Simulate genome sequencing with errors
    simulate_genome_sequencing(original_sequence, num_errors);

    // Print the sequence with errors
    printf("Sequence with errors:\n");
    print_sequence(original_sequence);

    return 0;
}