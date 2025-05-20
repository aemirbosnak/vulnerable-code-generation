//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

Sequence generateRandomSequence(int length) {
    Sequence seq = {0};
    seq.length = length;

    for (int i = 0; i < length; i++) {
        char base = 'A' + rand() % 4;
        strncat(seq.sequence, &base, 1);
    }

    return seq;
}

void printSequence(Sequence seq) {
    printf("Sequence: %s\n", seq.sequence);
    printf("Length: %d\n", seq.length);
}

int main() {
    srand(time(NULL));

    int numSequences = 10;
    Sequence *sequences = malloc(numSequences * sizeof(Sequence));

    for (int i = 0; i < numSequences; i++) {
        int length = rand() % 100 + 1;
        sequences[i] = generateRandomSequence(length);
    }

    printf("Generated %d sequences:\n", numSequences);

    for (int i = 0; i < numSequences; i++) {
        printSequence(sequences[i]);
    }

    free(sequences);

    return 0;
}