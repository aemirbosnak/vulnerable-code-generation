//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_BASES 4
#define NUM_AMINO_ACIDS 20
#define NUM_CODON_PER_AMINO_ACID 3

typedef struct {
    char* sequence;
    int length;
} Sequence;

typedef struct {
    char* codon;
    char amino_acid;
} Codon;

Sequence* generateRandomSequence(int length) {
    Sequence* sequence = malloc(sizeof(Sequence));
    sequence->sequence = calloc(length + 1, sizeof(char));
    sequence->length = length;

    for (int i = 0; i < length; i++) {
        int base = rand() % NUM_BASES;
        sequence->sequence[i] = "ACGT"[base];
    }

    return sequence;
}

void printSequence(Sequence* sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

Codon* generateRandomCodon() {
    Codon* codon = malloc(sizeof(Codon));
    codon->codon = calloc(NUM_CODON_PER_AMINO_ACID, sizeof(char));
    codon->amino_acid = rand() % NUM_AMINO_ACIDS;

    for (int i = 0; i < NUM_CODON_PER_AMINO_ACID; i++) {
        int base = rand() % NUM_BASES;
        codon->codon[i] = "ACGT"[base];
    }

    return codon;
}

void printCodon(Codon* codon) {
    for (int i = 0; i < NUM_CODON_PER_AMINO_ACID; i++) {
        printf("%c", codon->codon[i]);
    }
    printf(" -> %c\n", codon->amino_acid);
}

int main() {
    srand(time(NULL));

    Sequence* sequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printf("Random DNA sequence:\n");
    printSequence(sequence);

    Codon* codon = generateRandomCodon();
    printf("Random codon:\n");
    printCodon(codon);

    return 0;
}