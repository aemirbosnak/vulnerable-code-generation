//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SEQUENCE_LENGTH 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *createSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc((length + 1) * sizeof(char));
    seq->length = length;
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->sequence[length] = '\0';
    return seq;
}

void printSequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

void reverseSequence(Sequence *seq) {
    char *temp = seq->sequence;
    seq->sequence = malloc((seq->length + 1) * sizeof(char));
    for (int i = 0; i < seq->length; i++) {
        seq->sequence[i] = temp[seq->length - i - 1];
    }
    seq->sequence[seq->length] = '\0';
    free(temp);
}

int main() {
    int length = 0;
    printf("Enter the length of the sequence: ");
    scanf("%d", &length);

    Sequence *seq = createSequence(length);
    printf("Sequence: ");
    printSequence(seq);

    reverseSequence(seq);
    printf("Reversed sequence: ");
    printSequence(seq);

    free(seq->sequence);
    free(seq);
    return 0;
}