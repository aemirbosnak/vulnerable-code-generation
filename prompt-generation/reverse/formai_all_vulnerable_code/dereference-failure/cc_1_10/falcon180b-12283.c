//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random nucleotide
char generateNucleotide() {
    int random = rand() % 4;
    switch (random) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

// Function to print the generated genome sequence
void printGenomeSequence(char* sequence, int length) {
    printf("Genome Sequence:\n");
    for (int i = 0; i < length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

// Function to simulate genome sequencing
void simulateGenomeSequencing(char* sequence, int length) {
    int reads = length / 100; // Number of reads to simulate
    int readLength = length / reads; // Length of each read
    char* readsSequence = malloc(reads * readLength * sizeof(char)); // Allocate memory for reads sequence
    for (int i = 0; i < reads; i++) {
        int startIndex = i * readLength;
        int endIndex = startIndex + readLength - 1;
        if (endIndex >= length) {
            endIndex = length - 1;
        }
        for (int j = startIndex; j <= endIndex; j++) {
            readsSequence[i * readLength + j - startIndex] = sequence[j];
        }
    }
    printf("Reads Sequence:\n");
    for (int i = 0; i < reads; i++) {
        for (int j = 0; j < readLength; j++) {
            printf("%c", readsSequence[i * readLength + j]);
        }
        printf("\n");
    }
    free(readsSequence); // Free memory allocated for reads sequence
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    int length = 1000; // Length of the genome sequence to simulate
    char* sequence = malloc(length * sizeof(char)); // Allocate memory for the genome sequence

    // Generate the genome sequence
    for (int i = 0; i < length; i++) {
        sequence[i] = generateNucleotide();
    }

    // Print the genome sequence
    printGenomeSequence(sequence, length);

    // Simulate genome sequencing
    simulateGenomeSequencing(sequence, length);

    free(sequence); // Free memory allocated for the genome sequence
    return 0;
}