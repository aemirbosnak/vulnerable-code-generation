//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DNA_SEQUENCE_LENGTH 1000000
#define DNA_BASES 4

typedef struct {
    char *sequence;
    int length;
} DNA;

DNA *generateRandomDNA(int length) {
    DNA *dna = malloc(sizeof(DNA));
    dna->sequence = malloc(sizeof(char) * length + 1);
    dna->length = length;

    for (int i = 0; i < length; i++) {
        char base = rand() % DNA_BASES;
        dna->sequence[i] = "ACGT"[base];
    }
    dna->sequence[length] = '\0';

    return dna;
}

void printDNA(DNA *dna) {
    printf("%s\n", dna->sequence);
}

int main() {
    srand(time(NULL));

    int numSequences = 10;
    int maxSequenceLength = 10000;
    int minSequenceLength = 1000;

    DNA **sequences = malloc(sizeof(DNA *) * numSequences);

    for (int i = 0; i < numSequences; i++) {
        int sequenceLength = rand() % (maxSequenceLength - minSequenceLength + 1) + minSequenceLength;
        sequences[i] = generateRandomDNA(sequenceLength);
    }

    for (int i = 0; i < numSequences; i++) {
        printDNA(sequences[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}