//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// define the number of nucleotides in the genome
#define GENOME_LENGTH 1000000

// define the number of possible nucleotides
#define NUM_NUCLEOTIDES 4

// define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// define the nucleotide probabilities
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// define the nucleotide codes
#define CODE_A 0
#define CODE_C 1
#define CODE_G 2
#define CODE_T 3

// define the nucleotide codes array
int nucleotide_codes[NUM_NUCLEOTIDES] = {CODE_A, CODE_C, CODE_G, CODE_T};

// define the nucleotide probabilities array
double nucleotide_probabilities[NUM_NUCLEOTIDES] = {PROB_A, PROB_C, PROB_G, PROB_T};

// define the genome as a string
char genome[GENOME_LENGTH + 1] = "";

// define the function to generate a random nucleotide
int generate_nucleotide() {
    int i;
    for (i = 0; i < NUM_NUCLEOTIDES; i++) {
        if (rand() % 100 < nucleotide_probabilities[i] * 100) {
            return i;
        }
    }
    return -1; // should never happen
}

// define the function to print the genome
void print_genome() {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

// define the main function
int main() {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        int nucleotide = generate_nucleotide();
        genome[i] = nucleotide_codes[nucleotide];
    }
    print_genome();
    return 0;
}