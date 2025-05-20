//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCES 100
#define MAX_LENGTH 100
#define NUCLEOTIDES "ACGT"

void generateRandomDNA(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = NUCLEOTIDES[rand() % 4];  // Randomly select A, C, G, or T
    }
    sequence[length] = '\0';  // Null-terminate the string
}

void calculateNucleotideComposition(const char *sequence, int *composition) {
    for (int i = 0; sequence[i] != '\0'; i++) {
        switch (sequence[i]) {
            case 'A': composition[0]++; break;
            case 'C': composition[1]++; break;
            case 'G': composition[2]++; break;
            case 'T': composition[3]++; break;
        }
    }
}

void printComposition(int *composition, int length) {
    printf("Nucleotide Composition:\n");
    printf("A: %d\n", composition[0]);
    printf("C: %d\n", composition[1]);
    printf("G: %d\n", composition[2]);
    printf("T: %d\n", composition[3]);
}

void visualizeDNA(const char *sequence) {
    for (int i = 0; sequence[i] != '\0'; i++) {
        printf("%c ", sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    int numberOfSequences;
    int lengthOfSequences;

    printf("Enter the number of DNA sequences to generate (max %d): ", MAX_SEQUENCES);
    scanf("%d", &numberOfSequences);
    if (numberOfSequences > MAX_SEQUENCES) {
        printf("Exceeded maximum number of sequences. Setting to %d.\n", MAX_SEQUENCES);
        numberOfSequences = MAX_SEQUENCES;
    }

    printf("Enter the length of each DNA sequence (max %d): ", MAX_LENGTH);
    scanf("%d", &lengthOfSequences);
    if (lengthOfSequences > MAX_LENGTH) {
        printf("Exceeded maximum length. Setting to %d.\n", MAX_LENGTH);
        lengthOfSequences = MAX_LENGTH;
    }

    char sequences[MAX_SEQUENCES][MAX_LENGTH + 1];
    int compositions[MAX_SEQUENCES][4] = {0};

    // Generate DNA sequences
    for (int i = 0; i < numberOfSequences; i++) {
        generateRandomDNA(sequences[i], lengthOfSequences);
        calculateNucleotideComposition(sequences[i], compositions[i]);
    }

    // Print sequences and their compositions
    for (int i = 0; i < numberOfSequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
        printComposition(compositions[i], 4);
        visualizeDNA(sequences[i]);
    }
    
    return 0;
}