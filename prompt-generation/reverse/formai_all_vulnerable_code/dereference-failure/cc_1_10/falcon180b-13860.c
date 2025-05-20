//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *name;
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *name;
    int start;
    int end;
    int length;
    char *sequence;
} Read;

Sequence *generateSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->name = "Sequence";
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->length = length;
    return seq;
}

Read *generateRead(Sequence *sequence, int readLength) {
    Read *read = malloc(sizeof(Read));
    read->name = "Read";
    read->start = rand() % sequence->length;
    read->end = read->start + readLength - 1;
    if (read->end >= sequence->length) {
        read->end = sequence->length - 1;
    }
    read->length = readLength;
    read->sequence = malloc((readLength + 1) * sizeof(char));
    for (int i = 0; i < readLength; i++) {
        read->sequence[i] = sequence->sequence[read->start + i];
    }
    read->sequence[readLength] = '\0';
    return read;
}

int main() {
    srand(time(NULL));
    Sequence *sequence = generateSequence(MAX_SEQUENCE_LENGTH);
    Read *read = generateRead(sequence, MAX_READ_LENGTH);

    printf("Sequence: %s\n", sequence->sequence);
    printf("Read: %s\n", read->sequence);

    free(sequence->sequence);
    free(sequence);
    free(read->sequence);
    free(read);

    return 0;
}