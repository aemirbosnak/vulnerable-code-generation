//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of a genome sequence
#define MAX_SEQUENCE_LENGTH 1000

// Define the number of nucleotides
#define NUM_NUCLEOTIDES 4

char nucleotides[NUM_NUCLEOTIDES] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide
char generateRandomNucleotide() {
    return nucleotides[rand() % NUM_NUCLEOTIDES];
}

// Function to generate a random genome sequence
char* generateRandomSequence(int length) {
    char* sequence = malloc(length + 1); // Allocate memory for the sequence and a null terminator
    for (int i = 0; i < length; i++) {
        sequence[i] = generateRandomNucleotide();
    }
    sequence[length] = '\0'; // Add a null terminator to the end of the sequence
    return sequence;
}

// Function to print a genome sequence
void printSequence(char* sequence) {
    printf("%s\n", sequence);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Prompt the user for the length of the genome sequence
    printf("Enter the length of the genome sequence: ");
    int length = 0;
    scanf("%d", &length);

    // Validate the length of the genome sequence
    while (length <= 0 || length > MAX_SEQUENCE_LENGTH) {
        printf("Invalid sequence length. Please enter a number between 1 and %d: ", MAX_SEQUENCE_LENGTH);
        scanf("%d", &length);
    }

    // Generate a random genome sequence
    char* sequence = generateRandomSequence(length);

    // Print the genome sequence
    printf("Random genome sequence:\n");
    printSequence(sequence);

    // Free the memory allocated for the sequence
    free(sequence);

    return 0;
}