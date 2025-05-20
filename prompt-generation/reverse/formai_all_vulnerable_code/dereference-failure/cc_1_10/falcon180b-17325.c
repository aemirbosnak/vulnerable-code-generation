//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100
#define NUM_READS 10000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start;
    int end;
} Read;

Sequence *generateSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->length = length;
    return seq;
}

Read *generateRead(Sequence *seq, int readLength) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(readLength + 1);
    int start = rand() % (seq->length - readLength + 1);
    for (int i = 0; i < readLength; i++) {
        read->sequence[i] = seq->sequence[start + i];
    }
    read->start = start;
    read->end = start + readLength - 1;
    return read;
}

void printSequence(Sequence *seq) {
    printf("Sequence: %s\n", seq->sequence);
    printf("Length: %d\n", seq->length);
}

void printRead(Read *read) {
    printf("Read: %s\n", read->sequence);
    printf("Start: %d\n", read->start);
    printf("End: %d\n", read->end);
}

int main() {
    srand(time(NULL));

    Sequence *genome = generateSequence(MAX_SEQUENCE_LENGTH);
    printf("Genome: ");
    printSequence(genome);

    Read *reads[NUM_READS];
    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = generateRead(genome, MAX_READ_LENGTH);
        printf("Read %d: ", i + 1);
        printRead(reads[i]);
    }

    return 0;
}