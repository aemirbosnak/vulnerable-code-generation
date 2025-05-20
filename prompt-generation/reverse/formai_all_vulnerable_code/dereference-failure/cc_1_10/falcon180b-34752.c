//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SEQUENCE_LENGTH 1000000

typedef struct {
    char* sequence;
    int length;
} Sequence;

Sequence* createSequence() {
    Sequence* seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    seq->length = 0;
    return seq;
}

void appendToSequence(Sequence* seq, char c) {
    if (seq->length >= MAX_SEQUENCE_LENGTH) {
        printf("Error: sequence is too long!\n");
        exit(1);
    }
    seq->sequence[seq->length++] = c;
}

void printSequence(Sequence* seq) {
    printf("Sequence: ");
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }
    printf("\n");
}

void reverseSequence(Sequence* seq) {
    for (int i = 0; i < seq->length / 2; i++) {
        char temp = seq->sequence[i];
        seq->sequence[i] = seq->sequence[seq->length - i - 1];
        seq->sequence[seq->length - i - 1] = temp;
    }
}

int countBases(Sequence* seq, char base) {
    int count = 0;
    for (int i = 0; i < seq->length; i++) {
        if (seq->sequence[i] == base) {
            count++;
        }
    }
    return count;
}

int main() {
    Sequence* seq = createSequence();
    char input;
    while ((input = getchar())!= EOF) {
        if (isalpha(input)) {
            appendToSequence(seq, toupper(input));
        }
    }
    printSequence(seq);
    reverseSequence(seq);
    printSequence(seq);
    int aCount = countBases(seq, 'A');
    int cCount = countBases(seq, 'C');
    int gCount = countBases(seq, 'G');
    int tCount = countBases(seq, 'T');
    printf("A: %d\n", aCount);
    printf("C: %d\n", cCount);
    printf("G: %d\n", gCount);
    printf("T: %d\n", tCount);
    return 0;
}