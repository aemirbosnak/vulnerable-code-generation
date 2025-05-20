//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERROR_RATE 0.05
#define MAX_NUM_READS 10000

typedef struct {
    char* name;
    char* sequence;
    int length;
} Sequence;

Sequence* generateRandomSequence(int length) {
    Sequence* sequence = (Sequence*) malloc(sizeof(Sequence));
    sequence->name = "Random";
    sequence->length = length;
    sequence->sequence = (char*) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->sequence[length] = '\0';
    return sequence;
}

void printSequence(Sequence* sequence) {
    printf("Name: %s\n", sequence->name);
    printf("Length: %d\n", sequence->length);
    printf("Sequence: %s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));
    Sequence* referenceSequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printSequence(referenceSequence);

    int numReads = rand() % MAX_NUM_READS + 1;
    printf("Number of reads: %d\n", numReads);

    Sequence** reads = (Sequence**) malloc(numReads * sizeof(Sequence*));
    for (int i = 0; i < numReads; i++) {
        int readLength = rand() % MAX_READ_LENGTH + 1;
        reads[i] = generateRandomSequence(readLength);
        printf("Read %d: Length %d\n", i+1, reads[i]->length);
        printSequence(reads[i]);
    }

    return 0;
}