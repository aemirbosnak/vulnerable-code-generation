//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = (char) ('A' + rand() % 4); // A, C, G, T
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
    srand(time(NULL));

    Sequence *genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Sequence *read = generateRandomSequence(MAX_READ_LENGTH);

    int matchCount = 0;
    for (int i = 0; i < read->length; i++) {
        if (genome->sequence[i] == read->sequence[i]) {
            matchCount++;
        }
    }

    printf("Match count: %d\n", matchCount);

    free(genome->sequence);
    free(genome);
    free(read->sequence);
    free(read);

    return 0;
}