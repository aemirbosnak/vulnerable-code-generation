//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10
#define NUCLEOTIDES "ACGT"

// Function prototypes
void generateRandomSequence(char* sequence, int length);
void mutateSequence(char* sequence, int mutationRate);
void printStatistics(char sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH], int seqCount);
void writeToFile(const char* filename, char sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH], int seqCount);

int main() {
    char sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH];
    int sequenceLength;
    int mutationRate;

    // Seed random number generator
    srand(time(NULL));

    printf("Welcome to the C Genome Sequencing Simulator!\n");
    printf("Enter the length of each sequence (max %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequenceLength);
    
    if (sequenceLength < 1 || sequenceLength > MAX_SEQUENCE_LENGTH) {
        printf("Invalid sequence length. Please enter a value between 1 and %d.\n", MAX_SEQUENCE_LENGTH);
        return 1;
    }

    printf("Enter mutation rate (percentage, e.g. 5 for 5%%): ");
    scanf("%d", &mutationRate);
    
    if (mutationRate < 0 || mutationRate > 100) {
        printf("Invalid mutation rate. Please enter a value between 0 and 100.\n");
        return 1;
    }

    // Generate random sequences
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        generateRandomSequence(sequences[i], sequenceLength);
    }

    // Mutate sequences based on mutation rate
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        mutateSequence(sequences[i], mutationRate);
    }

    // Print statistical analysis of sequences
    printStatistics(sequences, NUM_SEQUENCES);

    // Optional: Write sequences to a output file
    writeToFile("sequences_output.txt", sequences, NUM_SEQUENCES);

    printf("All processing complete. The sequences have been saved to 'sequences_output.txt'.\n");
    return 0;
}

// Function to generate a random DNA sequence
void generateRandomSequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = NUCLEOTIDES[rand() % 4];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to apply mutations to a DNA sequence
void mutateSequence(char* sequence, int mutationRate) {
    int sequenceLength = strlen(sequence);
    for (int i = 0; i < sequenceLength; i++) {
        if (rand() % 100 < mutationRate) { // Mutation occurs according to the mutation rate
            sequence[i] = NUCLEOTIDES[rand() % 4]; // Change to a different nucleotide
        }
    }
}

// Function to print statistics of generated sequences
void printStatistics(char sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH], int seqCount) {
    printf("\nStatistics of generated sequences:\n");
    for (int i = 0; i < seqCount; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

// Function to write sequences to a file
void writeToFile(const char* filename, char sequences[NUM_SEQUENCES][MAX_SEQUENCE_LENGTH], int seqCount) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < seqCount; i++) {
        fprintf(file, "Sequence %d: %s\n", i + 1, sequences[i]);
    }
    
    fclose(file);
}