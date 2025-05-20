//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_ALPHABET_SIZE 26
#define MAX_GENOME_SIZE 1000000

typedef struct {
    char *sequence;
    int length;
} Genome;

Genome *createGenome(int length) {
    Genome *genome = (Genome *)malloc(sizeof(Genome));
    genome->sequence = (char *)malloc(length * sizeof(char));
    genome->length = length;
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    return genome;
}

void printGenome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

void freeGenome(Genome *genome) {
    free(genome->sequence);
    free(genome);
}

int main() {
    srand(time(NULL));

    Genome *genome1 = createGenome(1000);
    Genome *genome2 = createGenome(5000);

    printf("Genome 1:\n");
    printGenome(genome1);
    printf("Genome 2:\n");
    printGenome(genome2);

    int overlap = 0;
    for (int i = 0; i < genome1->length && i < genome2->length; i++) {
        if (genome1->sequence[i] == genome2->sequence[i]) {
            overlap++;
        } else {
            break;
        }
    }

    printf("Overlap: %d\n", overlap);

    freeGenome(genome1);
    freeGenome(genome2);

    return 0;
}