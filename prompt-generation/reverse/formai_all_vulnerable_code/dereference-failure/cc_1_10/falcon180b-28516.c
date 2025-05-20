//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000

// Function to generate a random DNA sequence
void generateSequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4; // A, C, G, T
    }
    sequence[length] = '\0';
}

// Function to print a DNA sequence
void printSequence(char* sequence) {
    printf("%s\n", sequence);
}

// Function to reverse a DNA sequence
void reverseSequence(char* sequence) {
    int length = strlen(sequence);
    for (int i = 0; i < length / 2; i++) {
        char temp = sequence[i];
        sequence[i] = sequence[length - i - 1];
        sequence[length - i - 1] = temp;
    }
}

// Function to simulate genome sequencing
void simulateSequencing(char* sequence, int readLength, int numReads) {
    int overlap = readLength - 1;
    int step = MAX_SEQUENCE_LENGTH - readLength;

    for (int i = 0; i < numReads; i++) {
        int startIndex = rand() % (MAX_SEQUENCE_LENGTH - readLength) + 1;
        char* read = (char*) malloc(readLength * sizeof(char));
        strncpy(read, &sequence[startIndex], readLength);
        read[readLength - 1] = '\0';
        printSequence(read);
    }
}

int main() {
    srand(time(NULL));

    char* sequence = (char*) malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    generateSequence(sequence, MAX_SEQUENCE_LENGTH);

    int readLength = 100;
    int numReads = 10;

    printf("Original Sequence:\n");
    printSequence(sequence);

    printf("Simulating genome sequencing with read length %d and %d reads:\n", readLength, numReads);
    simulateSequencing(sequence, readLength, numReads);

    free(sequence);
    return 0;
}