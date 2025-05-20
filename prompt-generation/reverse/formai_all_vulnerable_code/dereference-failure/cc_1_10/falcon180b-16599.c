//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_ALLELES 5
#define MAX_LOCUS 10

typedef struct {
    int start;
    int end;
    int allele;
} Locus;

typedef struct {
    char *sequence;
    int length;
    Locus loci[MAX_LOCUS];
} Genome;

int main() {
    srand(time(NULL));

    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    genome->length = rand() % MAX_SEQUENCE_LENGTH + 1;

    for (int i = 0; i < MAX_LOCUS; i++) {
        int start = rand() % genome->length;
        int end = rand() % genome->length;
        int allele = rand() % MAX_ALLELES + 1;

        genome->loci[i] = (Locus) {
           .start = start,
           .end = end,
           .allele = allele
        };
    }

    printf("Genome sequence:\n%s\n", genome->sequence);

    for (int i = 0; i < MAX_LOCUS; i++) {
        printf("Locus %d: %d-%d (%d)\n", i+1, genome->loci[i].start, genome->loci[i].end, genome->loci[i].allele);
    }

    free(genome->sequence);
    free(genome);

    return 0;
}