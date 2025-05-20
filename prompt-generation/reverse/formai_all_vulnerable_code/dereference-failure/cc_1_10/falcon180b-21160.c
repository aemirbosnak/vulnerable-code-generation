//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *name;
    Sequence *sequence;
} Contig;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4;
    }

    return sequence;
}

Contig *generateRandomContig(int length) {
    Contig *contig = malloc(sizeof(Contig));
    contig->name = malloc(10 * sizeof(char));
    sprintf(contig->name, "Contig_%d", rand() % 1000);
    contig->sequence = generateRandomSequence(length);

    return contig;
}

void printSequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i] + 'A');
    }
}

int main() {
    srand(time(NULL));

    Sequence *genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Contig *contigs[NUM_READS];

    for (int i = 0; i < NUM_READS; i++) {
        int readLength = rand() % MAX_READ_LENGTH + 1;
        Contig *contig = generateRandomContig(readLength);
        memcpy(contig->sequence->sequence, genome->sequence + i * readLength, readLength);

        printf("Read %d: ", i + 1);
        printSequence(contig->sequence);
        printf("\n");

        contigs[i] = contig;
    }

    return 0;
}