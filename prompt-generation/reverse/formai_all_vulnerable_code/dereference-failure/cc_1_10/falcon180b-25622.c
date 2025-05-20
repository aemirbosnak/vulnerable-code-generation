//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_SEQUENCE_COUNT 10000

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = (Sequence *)malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = (char *)malloc(length * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = rand() % 4 + 'A';
    }

    return seq;
}

void printSequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }
    printf("\n");
}

int main() {
    int numSequences = 10;
    int maxSequenceLength = 100;

    srand(time(NULL));

    Sequence **sequences = (Sequence **)malloc(numSequences * sizeof(Sequence *));

    for (int i = 0; i < numSequences; i++) {
        int sequenceLength = rand() % maxSequenceLength + 1;
        sequences[i] = generateRandomSequence(sequenceLength);
        printSequence(sequences[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}