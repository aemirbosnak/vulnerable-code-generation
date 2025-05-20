//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READS 1000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int position;
    int length;
} Read;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length * sizeof(char));
    sequence->length = length;

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }

    return sequence;
}

Read *generateRandomRead(int length) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(length * sizeof(char));
    read->position = rand() % MAX_SEQUENCE_LENGTH;
    read->length = length;

    for (int i = 0; i < length; i++) {
        read->sequence[i] = 'A' + rand() % 4;
    }

    return read;
}

void printSequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void printRead(Read *read) {
    printf("Position: %d, Length: %d, Sequence: ", read->position, read->length);
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Sequence *genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Read *reads[MAX_READS];

    for (int i = 0; i < MAX_READS; i++) {
        reads[i] = generateRandomRead(MAX_READ_LENGTH);
    }

    for (int i = 0; i < MAX_READS; i++) {
        printRead(reads[i]);
    }

    return 0;
}