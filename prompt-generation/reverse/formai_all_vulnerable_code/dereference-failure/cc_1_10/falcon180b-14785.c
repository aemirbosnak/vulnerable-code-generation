//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_NUCLEOTIDES 4
#define NUM_AMINO_ACIDS 20

typedef struct {
    char *name;
    int length;
    char *sequence;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->name = "Random Sequence";
    seq->length = length;
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % NUM_NUCLEOTIDES;
    }
    seq->sequence[length] = '\0';
    return seq;
}

void printSequence(Sequence *seq) {
    printf("Sequence Name: %s\n", seq->name);
    printf("Sequence Length: %d\n", seq->length);
    printf("Sequence: %s\n", seq->sequence);
}

int main() {
    srand(time(NULL));

    Sequence *seq1 = generateRandomSequence(50);
    Sequence *seq2 = generateRandomSequence(100);
    Sequence *seq3 = generateRandomSequence(200);

    printSequence(seq1);
    printSequence(seq2);
    printSequence(seq3);

    free(seq1->sequence);
    free(seq1);
    free(seq2->sequence);
    free(seq2);
    free(seq3->sequence);
    free(seq3);

    return 0;
}