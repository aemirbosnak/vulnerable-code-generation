//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MIN_SEQUENCE_LENGTH 100
#define MAX_READ_LENGTH 100
#define MIN_READ_LENGTH 50

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
} Read;

Sequence generateSequence(int length) {
    char *sequence = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
    Sequence result = { sequence, length };
    return result;
}

Read generateRead(Sequence sequence, int readLength) {
    int startIndex = rand() % (sequence.length - readLength + 1);
    char *readSequence = (char *)malloc(readLength + 1);
    for (int i = 0; i < readLength; i++) {
        readSequence[i] = sequence.sequence[startIndex + i];
    }
    readSequence[readLength] = '\0';
    Read result = { readSequence, readLength };
    return result;
}

void printSequence(Sequence sequence) {
    printf("Sequence: %s\n", sequence.sequence);
    printf("Length: %d\n", sequence.length);
}

void printRead(Read read) {
    printf("Read: %s\n", read.sequence);
    printf("Length: %d\n", read.length);
}

int main() {
    srand(time(NULL));

    int sequenceLength = rand() % (MAX_SEQUENCE_LENGTH - MIN_SEQUENCE_LENGTH + 1) + MIN_SEQUENCE_LENGTH;
    Sequence genome = generateSequence(sequenceLength);
    printSequence(genome);

    int numReads = rand() % (MAX_READ_LENGTH - MIN_READ_LENGTH + 1) + MIN_READ_LENGTH;
    Read *reads = (Read *)malloc(numReads * sizeof(Read));
    for (int i = 0; i < numReads; i++) {
        reads[i] = generateRead(genome, rand() % (MAX_READ_LENGTH - MIN_READ_LENGTH + 1) + MIN_READ_LENGTH);
        printRead(reads[i]);
    }

    return 0;
}