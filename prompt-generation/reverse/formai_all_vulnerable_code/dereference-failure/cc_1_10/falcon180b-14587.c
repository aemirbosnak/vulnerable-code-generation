//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUCLEOTIDE_BASES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % NUCLEOTIDE_BASES;
    }
    sequence[length] = '\0';
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = sequence;
    seq->length = length;
    return seq;
}

void printSequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

int main() {
    srand(time(NULL));

    int numSequences = 10;
    int maxSequenceLength = 100;
    int minSequenceLength = 50;

    Sequence **sequences = malloc(numSequences * sizeof(Sequence *));

    for (int i = 0; i < numSequences; i++) {
        int length = rand() % (maxSequenceLength - minSequenceLength + 1) + minSequenceLength;
        sequences[i] = generateRandomSequence(length);
    }

    for (int i = 0; i < numSequences; i++) {
        printSequence(sequences[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}