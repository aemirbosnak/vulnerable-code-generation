//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of a genome
#define MAX_GENOME_LENGTH 1000000

// Define the number of possible nucleotide bases
#define NUM_BASES 4

// Define the possible nucleotide bases as characters
char bases[] = {'A', 'C', 'G', 'T'};

// Define the structure of a genome
typedef struct {
    char *genome;
    int length;
} Genome;

// Function to generate a random nucleotide base
char getBase() {
    return bases[rand() % NUM_BASES];
}

// Function to generate a random genome
Genome *generateGenome(int length) {
    Genome *genome = (Genome *)malloc(sizeof(Genome));
    genome->genome = (char *)malloc((length + 1) * sizeof(char));
    genome->length = length;
    for (int i = 0; i < length; i++) {
        genome->genome[i] = getBase();
    }
    genome->genome[length] = '\0';
    return genome;
}

// Function to print a genome
void printGenome(Genome *genome) {
    printf("Genome: %s\n", genome->genome);
    printf("Length: %d\n", genome->length);
}

// Function to compare two genomes for similarity
int compareGenomes(Genome *genome1, Genome *genome2) {
    int matches = 0;
    for (int i = 0; i < genome1->length; i++) {
        if (genome1->genome[i] == genome2->genome[i]) {
            matches++;
        }
    }
    return (matches * 100) / genome1->length;
}

int main() {
    srand(time(NULL));

    // Generate two random genomes
    Genome *genome1 = generateGenome(rand() % MAX_GENOME_LENGTH + 1);
    Genome *genome2 = generateGenome(rand() % MAX_GENOME_LENGTH + 1);

    // Print the genomes
    printf("Genome 1:\n");
    printGenome(genome1);
    printf("Genome 2:\n");
    printGenome(genome2);

    // Compare the genomes for similarity
    int similarity = compareGenomes(genome1, genome2);
    printf("Similarity: %d%%\n", similarity);

    // Free the memory allocated for the genomes
    free(genome1->genome);
    free(genome1);
    free(genome2->genome);
    free(genome2);

    return 0;
}