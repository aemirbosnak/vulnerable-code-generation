//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int position;
    char nucleotide;
} DNA;

int main() {
    char input[100];
    printf("Enter DNA sequence: ");
    scanf("%s", input);

    // Convert input sequence to DNA struct array
    int len = strlen(input);
    DNA* sequence = malloc(len * sizeof(DNA));
    for (int i = 0; i < len; i++) {
        sequence[i].position = i;
        sequence[i].nucleotide = input[i];
    }

    // Print DNA sequence
    printf("POSITION\tNUCLEOTIDE\n");
    for (int i = 0; i < len; i++) {
        printf("%d\t\t%c\n", sequence[i].position, sequence[i].nucleotide);
    }

    // Count nucleotides
    int counts[4] = {0}; // A, C, G, T
    for (int i = 0; i < len; i++) {
        if (sequence[i].nucleotide == 'A') {
            counts[0]++;
        } else if (sequence[i].nucleotide == 'C') {
            counts[1]++;
        } else if (sequence[i].nucleotide == 'G') {
            counts[2]++;
        } else if (sequence[i].nucleotide == 'T') {
            counts[3]++;
        }
    }

    // Print nucleotide counts
    printf("NUCLEOTIDE COUNTS\n");
    printf("A: %d\n", counts[0]);
    printf("C: %d\n", counts[1]);
    printf("G: %d\n", counts[2]);
    printf("T: %d\n", counts[3]);

    // Randomly mutate sequence
    srand(42); // Seed random number generator
    printf("MUTATED SEQUENCE\n");
    for (int i = 0; i < len; i++) {
        DNA dna = sequence[i];
        if (rand() < RAND_MAX / 10) { // 10% chance of mutation
            if (dna.nucleotide == 'A') {
                dna.nucleotide = 'C';
            } else if (dna.nucleotide == 'C') {
                dna.nucleotide = 'G';
            } else if (dna.nucleotide == 'G') {
                dna.nucleotide = 'T';
            } else if (dna.nucleotide == 'T') {
                dna.nucleotide = 'A';
            }
        }
        sequence[i] = dna;
        printf("%c", dna.nucleotide);
    }
    printf("\n");

    // Free memory
    free(sequence);

    return 0;
}