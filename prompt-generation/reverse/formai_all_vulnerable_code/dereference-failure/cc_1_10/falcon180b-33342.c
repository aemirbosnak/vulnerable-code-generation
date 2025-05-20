//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALLELES 4
#define MAX_GENES 10

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence *sequence;
    int start;
    int end;
} Gene;

void generateRandomSequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = rand() % 4 + 'A';
    }
}

void printSequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

int compareSequences(Sequence *s1, Sequence *s2) {
    int i;
    for (i = 0; i < s1->length && i < s2->length; i++) {
        if (s1->sequence[i]!= s2->sequence[i]) {
            return 0;
        }
    }
    return 1;
}

void generateRandomGenes(Gene *genes, int numGenes, int maxGeneLength) {
    int i, j;
    for (i = 0; i < numGenes; i++) {
        genes[i].sequence = malloc(sizeof(Sequence));
        genes[i].sequence->length = rand() % maxGeneLength + 1;
        generateRandomSequence(genes[i].sequence);
        genes[i].start = rand() % genes[i].sequence->length;
        genes[i].end = rand() % genes[i].sequence->length;
        if (genes[i].start > genes[i].end) {
            int temp = genes[i].start;
            genes[i].start = genes[i].end;
            genes[i].end = temp;
        }
    }
}

void printGenes(Gene *genes, int numGenes) {
    int i;
    for (i = 0; i < numGenes; i++) {
        printf("Gene %d: ", i+1);
        printSequence(genes[i].sequence);
        printf("Start: %d, End: %d\n", genes[i].start, genes[i].end);
    }
}

int main() {
    srand(time(NULL));

    Sequence genome;
    generateRandomSequence(&genome);

    Gene genes[MAX_GENES];
    int numGenes = rand() % MAX_GENES + 1;
    generateRandomGenes(genes, numGenes, genome.length);

    printGenes(genes, numGenes);

    return 0;
}