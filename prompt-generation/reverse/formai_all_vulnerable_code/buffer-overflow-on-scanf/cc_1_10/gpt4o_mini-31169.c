//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100
#define NUM_NUCLEOTIDES 4

char nucleotides[NUM_NUCLEOTIDES] = {'A', 'T', 'C', 'G'};

// Function to generate a random DNA sequence of a given length
void generateDNASequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        int randIndex = rand() % NUM_NUCLEOTIDES;
        sequence[i] = nucleotides[randIndex];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to transcribe DNA to RNA
void transcribeToRNA(const char* dna, char* rna) {
    for (int i = 0; i < strlen(dna); i++) {
        if (dna[i] == 'T') {
            rna[i] = 'U'; // Replace Thymine with Uracil
        } else {
            rna[i] = dna[i];
        }
    }
    rna[strlen(dna)] = '\0'; // Null-terminate the string
}

// Function to mutate a DNA sequence
void mutateDNA(char* sequence, int mutationRate) {
    for (int i = 0; i < strlen(sequence); i++) {
        if (rand() % 100 < mutationRate) {
            int randIndex = rand() % NUM_NUCLEOTIDES;
            sequence[i] = nucleotides[randIndex]; // Change to a random nucleotide
        }
    }
}

// Main function to run the simulator
int main() {
    srand(time(NULL)); // Seed the random number generator
    int length, mutationRate;
    
    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("Enter the length of the DNA sequence (max %d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &length);

    // Input validation
    if (length <= 0 || length > MAX_SEQUENCE_LENGTH) {
        printf("Invalid length. Please provide a value between 1 and %d.\n", MAX_SEQUENCE_LENGTH);
        return 1;
    }

    char dna[MAX_SEQUENCE_LENGTH + 1];
    char rna[MAX_SEQUENCE_LENGTH + 1];

    // Generate random DNA sequence
    generateDNASequence(dna, length);
    printf("Generated DNA Sequence: %s\n", dna);
    
    // Transcribe to RNA
    transcribeToRNA(dna, rna);
    printf("Transcribed RNA Sequence: %s\n", rna);
    
    // Input mutation rate
    printf("Enter the mutation rate (0 to 100): ");
    scanf("%d", &mutationRate);
    
    // Input validation for mutation rate
    if (mutationRate < 0 || mutationRate > 100) {
        printf("Invalid mutation rate. Please provide a value between 0 and 100.\n");
        return 1;
    }

    // Mutate DNA sequence
    mutateDNA(dna, mutationRate);
    printf("Mutated DNA Sequence: %s\n", dna);

    return 0;
}