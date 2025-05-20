//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

Sequence* createSequence(int length) {
    Sequence* seq = (Sequence*) malloc(sizeof(Sequence));
    seq->length = length;
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    seq->sequence[length] = '\0';
    return seq;
}

void printSequence(Sequence* seq) {
    printf("Sequence: %s\n", seq->sequence);
    printf("Length: %d\n", seq->length);
}

int compareSequences(Sequence* seq1, Sequence* seq2) {
    int minLength = (seq1->length < seq2->length)? seq1->length : seq2->length;
    for (int i = 0; i < minLength; i++) {
        if (seq1->sequence[i]!= seq2->sequence[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    Sequence* seq1 = createSequence(rand() % MAX_SEQUENCE_LENGTH + 1);
    Sequence* seq2 = createSequence(rand() % MAX_SEQUENCE_LENGTH + 1);
    printf("Sequences created:\n");
    printSequence(seq1);
    printSequence(seq2);
    if (compareSequences(seq1, seq2)) {
        printf("Sequences match!\n");
    } else {
        printf("Sequences do not match.\n");
    }
    return 0;
}