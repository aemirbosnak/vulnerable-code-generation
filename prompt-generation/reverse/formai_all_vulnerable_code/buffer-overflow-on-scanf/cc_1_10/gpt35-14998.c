//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000

// Function to generate a random base
char random_base() {
    char bases[4] = {'A', 'C', 'G', 'T'};
    return bases[rand() % 4];
}

// Function to generate a random DNA sequence
char* generate_sequence(int length) {
    char* sequence = malloc(sizeof(char) * length);
    int i;
    for (i=0; i<length; i++) {
        sequence[i] = random_base();
    }
    return sequence;
}

// Main function
int main() {
    int seq_length;
    char* sequence;
    printf("Enter sequence length: ");
    scanf("%d", &seq_length);

    if (seq_length > MAX_SEQ_LENGTH) {
        printf("Sequence length exceeds limit.\n");
        exit(1);
    }

    // Generate random sequence of specified length
    sequence = generate_sequence(seq_length);
    printf("Generated sequence: %s\n", sequence);

    // Generate mutations
    int num_mutations;
    printf("Enter number of mutations: ");
    scanf("%d", &num_mutations);

    int i;
    for (i=0; i<num_mutations; i++) {
        int index = rand() % seq_length;
        char original_base = sequence[index];
        char new_base = random_base();

        while (new_base == original_base) {
            new_base = random_base();
        }

        sequence[index] = new_base;
        printf("Mutation at index %d: %c -> %c\n", index, original_base, new_base);
    }

    printf("Final sequence: %s\n", sequence);

    // Free memory
    free(sequence);

    return 0;
}