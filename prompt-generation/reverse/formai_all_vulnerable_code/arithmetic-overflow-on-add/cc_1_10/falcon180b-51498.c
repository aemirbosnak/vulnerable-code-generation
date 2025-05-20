//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

// Function to generate a random DNA sequence
void generateRandomSequence(char *sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int randIndex = rand() % MAX_ALPHABET_SIZE;
        sequence[i] = 'A' + randIndex;
    }
    sequence[length] = '\0';
}

int main() {
    int numSequences, maxSequenceLength;
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &numSequences);
    printf("Enter the maximum length of each sequence: ");
    scanf("%d", &maxSequenceLength);

    // Allocate memory for sequences
    char **sequences = malloc(numSequences * sizeof(char *));
    if (sequences == NULL) {
        printf("Error: Could not allocate memory for sequences.\n");
        exit(1);
    }

    // Generate random sequences
    for (int i = 0; i < numSequences; i++) {
        sequences[i] = malloc(maxSequenceLength + 1);
        if (sequences[i] == NULL) {
            printf("Error: Could not allocate memory for sequence %d.\n", i);
            exit(1);
        }
        generateRandomSequence(sequences[i], maxSequenceLength);
    }

    // Print sequences
    for (int i = 0; i < numSequences; i++) {
        printf("Sequence %d: %s\n", i, sequences[i]);
    }

    // Free memory
    for (int i = 0; i < numSequences; i++) {
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}