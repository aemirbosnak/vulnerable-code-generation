//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int start;
    int end;
    char strand;
    int length;
} Gene;

typedef struct {
    char *name;
    int length;
    Gene *genes;
} Chromosome;

typedef struct {
    Chromosome *chromosomes;
    int num_chromosomes;
} Genome;

void generate_genome(Genome *genome) {
    srand(time(NULL));
    genome->num_chromosomes = rand() % 10 + 1;
    genome->chromosomes = (Chromosome *) malloc(genome->num_chromosomes * sizeof(Chromosome));
    for (int i = 0; i < genome->num_chromosomes; i++) {
        Chromosome *chromosome = &genome->chromosomes[i];
        chromosome->name = (char *) malloc(10 * sizeof(char));
        sprintf(chromosome->name, "chr%d", i + 1);
        chromosome->length = rand() % 1000000 + 1;
        chromosome->genes = (Gene *) malloc(chromosome->length * sizeof(Gene));
        for (int j = 0; j < chromosome->length; j++) {
            Gene *gene = &chromosome->genes[j];
            gene->start = rand() % chromosome->length + 1;
            gene->end = gene->start + rand() % 1000 + 1;
            gene->strand = rand() % 2;
            gene->length = gene->end - gene->start;
        }
    }
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_chromosomes; i++) {
        Chromosome *chromosome = &genome->chromosomes[i];
        printf("Chromosome %s:\n", chromosome->name);
        for (int j = 0; j < chromosome->length; j++) {
            Gene *gene = &chromosome->genes[j];
            printf("Gene %d-%d (%d bp) on strand %c\n", gene->start, gene->end, gene->length, gene->strand == 0? '+' : '-');
        }
        printf("\n");
    }
}

int main() {
    Genome genome;
    generate_genome(&genome);
    print_genome(&genome);
    return 0;
}