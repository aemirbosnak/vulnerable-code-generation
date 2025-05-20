//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000
#define MAX_NUM_SEQUENCES 100

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3
#define N 4

typedef struct {
    int length;
    int *sequence;
} Sequence;

void generateSequence(Sequence *seq) {
    int i;
    for (i = 0; i < seq->length; i++) {
        int base = rand() % 5; // 0-4 (A, C, G, T, N)
        seq->sequence[i] = base;
    }
}

void printSequence(Sequence seq) {
    int i;
    for (i = 0; i < seq.length; i++) {
        switch (seq.sequence[i]) {
            case A:
                printf("A");
                break;
            case C:
                printf("C");
                break;
            case G:
                printf("G");
                break;
            case T:
                printf("T");
                break;
            case N:
                printf("N");
                break;
            default:
                printf("?");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numSequences = 5;
    Sequence *sequences = malloc(numSequences * sizeof(Sequence));

    int i;
    for (i = 0; i < numSequences; i++) {
        int length = rand() % MAX_SEQUENCE_LENGTH + 1; // 1-100000
        sequences[i].length = length;
        sequences[i].sequence = malloc(length * sizeof(int));
        generateSequence(&sequences[i]);
    }

    for (i = 0; i < numSequences; i++) {
        printSequence(sequences[i]);
    }

    for (i = 0; i < numSequences; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}