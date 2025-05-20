//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *name;
    int length;
    int start;
} Gene;

typedef struct {
    char *sequence;
    int length;
} Chromosome;

int main() {
    srand(time(NULL));

    int num_chromosomes = rand() % 50 + 1;
    Chromosome *chromosomes = malloc(sizeof(Chromosome) * num_chromosomes);

    for (int i = 0; i < num_chromosomes; i++) {
        int chromosome_length = rand() % 100000 + 1;
        chromosomes[i].sequence = malloc(sizeof(char) * chromosome_length);
        chromosomes[i].length = chromosome_length;

        for (int j = 0; j < chromosome_length; j++) {
            chromosomes[i].sequence[j] = 'A' + rand() % 4;
        }
    }

    int num_genes = rand() % 100 + 1;
    Gene *genes = malloc(sizeof(Gene) * num_genes);

    for (int i = 0; i < num_genes; i++) {
        int gene_length = rand() % 1000 + 1;
        genes[i].name = malloc(sizeof(char) * (gene_length + 1));
        genes[i].length = gene_length;
        genes[i].start = rand() % chromosomes[0].length;

        for (int j = 0; j < gene_length; j++) {
            genes[i].name[j] = 'A' + rand() % 26;
        }
        genes[i].name[gene_length] = '\0';
    }

    printf("Chromosome Sequences:\n");
    for (int i = 0; i < num_chromosomes; i++) {
        printf("Chromosome %d: %s\n", i + 1, chromosomes[i].sequence);
    }

    printf("\nGene Information:\n");
    for (int i = 0; i < num_genes; i++) {
        printf("Gene %d: %s (%d bp) starts at position %d\n", i + 1, genes[i].name, genes[i].length, genes[i].start);
    }

    free(chromosomes);
    free(genes);

    return 0;
}