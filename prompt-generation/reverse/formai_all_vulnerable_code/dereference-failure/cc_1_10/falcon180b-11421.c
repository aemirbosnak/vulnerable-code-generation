//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the length of the genome sequence
#define GENOME_LENGTH 1000000

// Define the number of nucleotides
#define NUM_NUCLEOTIDES 4

// Define the nucleotides
char nucleotides[NUM_NUCLEOTIDES] = {'A', 'C', 'G', 'T'};

// Define the function to generate a random nucleotide
char generateRandomNucleotide() {
    return nucleotides[rand() % NUM_NUCLEOTIDES];
}

// Define the function to generate a random genome sequence
void generateRandomGenomeSequence(char* genomeSequence) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genomeSequence[i] = generateRandomNucleotide();
    }
}

// Define the function to print the genome sequence
void printGenomeSequence(char* genomeSequence) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genomeSequence[i]);
    }
}

// Define the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the genome sequence
    char* genomeSequence = (char*) malloc(GENOME_LENGTH * sizeof(char));

    // Generate the random genome sequence
    generateRandomGenomeSequence(genomeSequence);

    // Print the genome sequence
    printf("Random genome sequence:\n");
    printGenomeSequence(genomeSequence);

    // Free the memory
    free(genomeSequence);

    return 0;
}