//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000

// Structure for a base in the sequence
typedef struct {
    char base;
    int quality;
} Base;

// Structure for the sequence
typedef struct {
    Base *bases;
    int length;
} Sequence;

// Function to generate a random base with a given quality
Base generateBase(int quality) {
    Base base;
    base.base = 'A' + rand() % 4; // A, C, G, or T
    base.quality = quality;
    return base;
}

// Function to generate a random sequence of given length and quality
Sequence generateSequence(int length, int quality) {
    Sequence seq;
    seq.bases = malloc(length * sizeof(Base));
    seq.length = length;
    for (int i = 0; i < length; i++) {
        seq.bases[i] = generateBase(quality);
    }
    return seq;
}

// Function to print the sequence
void printSequence(Sequence seq) {
    for (int i = 0; i < seq.length; i++) {
        printf("%c%d ", seq.bases[i].base, seq.bases[i].quality);
    }
    printf("\n");
}

// Function to free the memory used by the sequence
void freeSequence(Sequence seq) {
    free(seq.bases);
}

// Function to simulate genome sequencing with errors
Sequence simulateSequencing(Sequence originalSeq, int errorRate) {
    Sequence resultSeq;
    resultSeq.length = originalSeq.length;
    resultSeq.bases = malloc(resultSeq.length * sizeof(Base));
    for (int i = 0; i < resultSeq.length; i++) {
        if (rand() % 100 < errorRate) {
            resultSeq.bases[i].base = 'N'; // N for unknown base
            resultSeq.bases[i].quality = 0;
        } else {
            resultSeq.bases[i] = originalSeq.bases[i];
        }
    }
    return resultSeq;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    Sequence seq = generateSequence(MAX_SEQUENCE_LENGTH, 30);
    printf("Original sequence:\n");
    printSequence(seq);

    Sequence resultSeq = simulateSequencing(seq, 5);
    printf("Sequencing result with 5% error rate:\n");
    printSequence(resultSeq);

    freeSequence(seq);
    freeSequence(resultSeq);

    return 0;
}