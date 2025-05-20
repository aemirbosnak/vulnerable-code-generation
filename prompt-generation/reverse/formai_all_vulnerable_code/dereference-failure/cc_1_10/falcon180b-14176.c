//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the length of the genome
#define GENOME_LENGTH 1000000

// define the number of nucleotides
#define NUM_NUCLEOTIDES 4

// define the nucleotides
typedef enum {
    A = 0,
    C = 1,
    G = 2,
    T = 3
} Nucleotide;

// define the genome structure
typedef struct {
    Nucleotide* sequence;
    int length;
} Genome;

// function to generate a random nucleotide
Nucleotide generateRandomNucleotide() {
    int random = rand() % NUM_NUCLEOTIDES;
    return (Nucleotide)random;
}

// function to generate a random genome
Genome generateRandomGenome(int length) {
    Genome genome;
    genome.sequence = (Nucleotide*)malloc(length * sizeof(Nucleotide));
    for (int i = 0; i < length; i++) {
        genome.sequence[i] = generateRandomNucleotide();
    }
    genome.length = length;
    return genome;
}

// function to print the genome
void printGenome(Genome genome) {
    for (int i = 0; i < genome.length; i++) {
        printf("%c", "ACGT"[genome.sequence[i]]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // generate a random genome
    Genome genome = generateRandomGenome(GENOME_LENGTH);

    // print the original genome
    printf("Original Genome:\n");
    printGenome(genome);

    // mutate the genome
    for (int i = 0; i < genome.length; i++) {
        int random = rand() % NUM_NUCLEOTIDES;
        genome.sequence[i] = (Nucleotide)random;
    }

    // print the mutated genome
    printf("Mutated Genome:\n");
    printGenome(genome);

    return 0;
}