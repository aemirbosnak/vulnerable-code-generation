//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000

//Structure to store sequence data
typedef struct {
    char* sequence;
    int length;
} Sequence;

Sequence* generateRandomSequence(int length) {
    Sequence* seq = (Sequence*)malloc(sizeof(Sequence));
    seq->sequence = (char*)malloc(length + 1);
    seq->length = length;

    //Fill sequence with random nucleotides
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4; //Random nucleotide
    }
    seq->sequence[length] = '\0'; //Null terminate sequence

    return seq;
}

void printSequence(Sequence* seq) {
    printf("Sequence: %s\n", seq->sequence);
    printf("Length: %d\n", seq->length);
}

int main() {
    srand(time(NULL));
    int numSequences = 10;
    int maxSequenceLength = 1000000;
    Sequence* sequences[numSequences];

    //Generate random sequences
    for (int i = 0; i < numSequences; i++) {
        int sequenceLength = rand() % maxSequenceLength + 1;
        sequences[i] = generateRandomSequence(sequenceLength);
    }

    //Print sequences
    for (int i = 0; i < numSequences; i++) {
        printSequence(sequences[i]);
    }

    return 0;
}