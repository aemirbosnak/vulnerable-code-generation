//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHROMOSOMES 100
#define MAX_BASES 1000000

typedef struct {
    char name[10];
    int length;
    char *sequence;
} Chromosome;

void create_chromosome(Chromosome *chromosome, char *name, int length) {
    strcpy(chromosome->name, name);
    chromosome->length = length;
    chromosome->sequence = (char *) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        chromosome->sequence[i] = rand() % 4; // A, C, G, T
    }
}

int compare_chromosomes(const void *a, const void *b) {
    return strcmp(((Chromosome *) a)->name, ((Chromosome *) b)->name);
}

void print_chromosome(Chromosome *chromosome) {
    printf("%s: %d bases\n", chromosome->name, chromosome->length);
    printf("Sequence: %s\n", chromosome->sequence);
}

int main() {
    int num_chromosomes;
    scanf("%d", &num_chromosomes);

    Chromosome *chromosomes = (Chromosome *) malloc(num_chromosomes * sizeof(Chromosome));

    for (int i = 0; i < num_chromosomes; i++) {
        char name[10];
        scanf("%s", name);
        int length;
        scanf("%d", &length);
        create_chromosome(&chromosomes[i], name, length);
    }

    qsort(chromosomes, num_chromosomes, sizeof(Chromosome), compare_chromosomes);

    for (int i = 0; i < num_chromosomes; i++) {
        print_chromosome(&chromosomes[i]);
    }

    return 0;
}