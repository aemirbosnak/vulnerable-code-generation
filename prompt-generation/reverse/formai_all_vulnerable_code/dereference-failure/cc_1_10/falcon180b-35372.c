//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a genome
typedef struct {
    char *name;
    int length;
    int *sequence;
} Genome;

// Function to generate a random DNA sequence
void generateSequence(int length, char *sequence) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
}

// Function to print a DNA sequence
void printSequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

// Main function to simulate genome sequencing
int main() {
    // Define the number of genomes to sequence
    int numGenomes = 5;

    // Allocate memory for the genomes
    Genome *genomes = (Genome *)malloc(numGenomes * sizeof(Genome));

    // Initialize the genomes
    for (int i = 0; i < numGenomes; i++) {
        genomes[i].name = (char *)malloc(10 * sizeof(char));
        genomes[i].length = rand() % 1000 + 1;
        genomes[i].sequence = (int *)malloc(genomes[i].length * sizeof(int));
        sprintf(genomes[i].name, "Genome%d", i+1);
        generateSequence(genomes[i].length, (char *)genomes[i].sequence);
    }

    // Print the genomes
    for (int i = 0; i < numGenomes; i++) {
        printf("Name: %s\n", genomes[i].name);
        printf("Length: %d\n", genomes[i].length);
        printSequence((char *)genomes[i].sequence, genomes[i].length);
    }

    // Free the memory
    for (int i = 0; i < numGenomes; i++) {
        free(genomes[i].name);
        free(genomes[i].sequence);
    }
    free(genomes);

    return 0;
}