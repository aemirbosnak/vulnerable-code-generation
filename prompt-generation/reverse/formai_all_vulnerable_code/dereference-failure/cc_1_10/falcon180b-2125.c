//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000 // Maximum length of DNA sequence
#define MAX_READ_LENGTH 100 // Maximum length of each read
#define NUM_READS 1000 // Number of reads to simulate
#define ERROR_RATE 0.01 // Error rate for each base call

typedef struct {
    char *sequence;
    int length;
} DNASequence;

DNASequence* generateRandomSequence(int length) {
    DNASequence *sequence = (DNASequence*) malloc(sizeof(DNASequence));
    sequence->length = length;
    sequence->sequence = (char*) malloc(length + 1);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4; // Randomly choose A, C, G or T
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

void printSequence(DNASequence *sequence) {
    printf("%s\n", sequence->sequence);
}

void freeSequence(DNASequence *sequence) {
    free(sequence->sequence);
    free(sequence);
}

int main() {
    srand(time(NULL));

    // Generate the original DNA sequence
    DNASequence *originalSequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printSequence(originalSequence);

    // Simulate sequencing with errors
    DNASequence *simulatedSequences[NUM_READS];
    for (int i = 0; i < NUM_READS; i++) {
        int readLength = rand() % MAX_READ_LENGTH + 1; // Randomly choose read length between 1 and MAX_READ_LENGTH
        DNASequence *read = generateRandomSequence(readLength);

        int startIndex = rand() % (MAX_SEQUENCE_LENGTH - readLength) + 1; // Randomly choose starting index for the read
        for (int j = 0; j < readLength; j++) {
            if (rand() % 100 < ERROR_RATE) { // Introduce errors with a certain probability
                read->sequence[j] = 'A' + rand() % 4; // Randomly choose a different base
            } else {
                read->sequence[j] = originalSequence->sequence[startIndex + j]; // Copy the correct base from the original sequence
            }
        }

        simulatedSequences[i] = read;
    }

    // Print the simulated sequences
    for (int i = 0; i < NUM_READS; i++) {
        printSequence(simulatedSequences[i]);
    }

    // Free memory
    freeSequence(originalSequence);
    for (int i = 0; i < NUM_READS; i++) {
        freeSequence(simulatedSequences[i]);
    }

    return 0;
}