//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000

// Structure to hold genome sequence data
typedef struct {
    char *sequence;
    int length;
} GenomeSequence;

// Function to generate a random DNA sequence
char *generateRandomSequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to print a genome sequence
void printSequence(GenomeSequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

// Function to simulate genome sequencing
void simulateSequencing(GenomeSequence *sequence, int readLength, int numReads) {
    // Initialize random seed based on current time
    srand(time(NULL));

    // Allocate memory for reads
    char **reads = malloc(numReads * sizeof(char*));

    // Generate random reads
    for (int i = 0; i < numReads; i++) {
        int startIndex = rand() % (sequence->length - readLength) + 1;
        int endIndex = startIndex + readLength - 1;
        reads[i] = malloc(readLength + 1);
        strncpy(reads[i], sequence->sequence + startIndex, readLength);
        reads[i][readLength] = '\0';
    }

    // Print reads
    for (int i = 0; i < numReads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i]);
    }

    // Free memory
    for (int i = 0; i < numReads; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main() {
    // Generate random genome sequence
    GenomeSequence sequence = { generateRandomSequence(MAX_SEQUENCE_LENGTH), MAX_SEQUENCE_LENGTH };

    // Print initial sequence
    printSequence(&sequence);

    // Simulate genome sequencing
    int readLength = 100;
    int numReads = 10;
    simulateSequencing(&sequence, readLength, numReads);

    return 0;
}