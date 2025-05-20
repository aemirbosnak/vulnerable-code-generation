//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_READ_LENGTH 500

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *read;
    int length;
    int position;
} Read;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = (Sequence *) malloc(sizeof(Sequence));
    seq->sequence = (char *) malloc((length + 1) * sizeof(char));
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->sequence[length] = '\0';

    return seq;
}

Read *generateRandomRead(int length, Sequence *sequence) {
    Read *read = (Read *) malloc(sizeof(Read));
    read->read = (char *) malloc((length + 1) * sizeof(char));
    read->length = length;
    read->position = rand() % sequence->length;

    for (int i = 0; i < length; i++) {
        read->read[i] = sequence->sequence[read->position + i];
    }
    read->read[length] = '\0';

    return read;
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printf("Random sequence generated:\n%s\n", sequence->sequence);

    Read *read1 = generateRandomRead(MAX_READ_LENGTH, sequence);
    printf("Random read 1 generated:\n%s\n", read1->read);
    printf("Position in sequence: %d\n", read1->position);

    Read *read2 = generateRandomRead(MAX_READ_LENGTH, sequence);
    printf("Random read 2 generated:\n%s\n", read2->read);
    printf("Position in sequence: %d\n", read2->position);

    free(sequence->sequence);
    free(sequence);

    free(read1->read);
    free(read1);

    free(read2->read);
    free(read2);

    return 0;
}