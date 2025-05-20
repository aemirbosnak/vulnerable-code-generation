//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_SEQUENCE_COUNT 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generateRandomSequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
}

int compareSequences(const void *a, const void *b) {
    Sequence *seqA = (Sequence *)a;
    Sequence *seqB = (Sequence *)b;

    int result = strcmp(seqA->sequence, seqB->sequence);

    if (result == 0) {
        result = seqA->length - seqB->length;
    }

    return result;
}

int main() {
    srand(time(NULL));

    int sequenceCount = rand() % MAX_SEQUENCE_COUNT + 1;
    Sequence *sequences = malloc(sequenceCount * sizeof(Sequence));

    for (int i = 0; i < sequenceCount; i++) {
        sequences[i].sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        generateRandomSequence(sequences[i].sequence, sequences[i].length);
    }

    qsort(sequences, sequenceCount, sizeof(Sequence), compareSequences);

    for (int i = 0; i < sequenceCount; i++) {
        printf("%s (%d bp)\n", sequences[i].sequence, sequences[i].length);
    }

    free(sequences);

    return 0;
}