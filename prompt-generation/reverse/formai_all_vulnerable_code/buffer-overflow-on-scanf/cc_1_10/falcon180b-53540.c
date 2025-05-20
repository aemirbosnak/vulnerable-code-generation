//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000000 // Maximum length of the genome
#define NUM_OF_NUCLEOTIDES 4 // Number of possible nucleotides (A, C, G, T)

// Function prototypes
void generateRandomGenome(char* genome, int length);
void printGenome(char* genome, int length);

int main() {
    int genomeLength;
    char* genome;
    srand(time(NULL)); // Seed the random number generator with the current time

    // Get user input for the length of the genome
    printf("Enter the length of the genome (maximum %d): ", MAX_GENOME_LENGTH);
    scanf("%d", &genomeLength);

    // Allocate memory for the genome
    genome = (char*) malloc(genomeLength + 1);
    if (genome == NULL) {
        printf("Error: Failed to allocate memory for the genome.\n");
        return 1;
    }

    // Generate a random genome
    generateRandomGenome(genome, genomeLength);

    // Print the genome
    printf("Random genome:\n");
    printGenome(genome, genomeLength);

    // Free the memory for the genome
    free(genome);
    return 0;
}

void generateRandomGenome(char* genome, int length) {
    int i;
    for (i = 0; i < length; i++) {
        genome[i] = 'A' + rand() % NUM_OF_NUCLEOTIDES; // Randomly choose a nucleotide
    }
    genome[length] = '\0'; // Add a null terminator to the end of the genome
}

void printGenome(char* genome, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}