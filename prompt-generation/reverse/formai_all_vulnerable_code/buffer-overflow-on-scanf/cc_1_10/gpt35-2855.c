//FormAI DATASET v1.0 Category: Computer Biology ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GENES 1000
#define MAX_CHROMOSOMES 100

typedef struct {
    char name[20];
    char sequence[100];
    int length;
} Gene;

typedef struct {
    Gene genes[MAX_GENES];
    int count;
} Chromosome;

typedef struct {
    Chromosome chromosomes[MAX_CHROMOSOMES];
    int count;
} Genome;

void print_gene(Gene gene) {
    printf("Name: %s\n", gene.name);
    printf("Sequence: %s\n", gene.sequence);
    printf("Length: %d\n", gene.length);
}

void print_chromosome(Chromosome chromosome) {
    printf("Number of Genes: %d\n", chromosome.count);
    for(int i=0; i<chromosome.count; i++) {
        print_gene(chromosome.genes[i]);
    }
}

void print_genome(Genome genome) {
    printf("Number of Chromosomes: %d\n", genome.count);
    for(int i=0; i<genome.count; i++) {
        print_chromosome(genome.chromosomes[i]);
    }
}

Gene create_gene(char* name, char* sequence) {
    Gene gene;
    strcpy(gene.name, name);
    strcpy(gene.sequence, sequence);
    gene.length = strlen(sequence);
    return gene;
}

Chromosome create_chromosome(int num_genes) {
    Chromosome chromosome;
    for(int i=0; i<num_genes; i++) {
        char name[20];
        char sequence[100];
        printf("Enter gene name: ");
        scanf("%s", name);
        printf("Enter gene sequence: ");
        scanf("%s", sequence);
        chromosome.genes[i] = create_gene(name, sequence);
    }
    chromosome.count = num_genes;
    return chromosome;
}

Genome create_genome(int num_chromosomes) {
    Genome genome;
    for(int i=0; i<num_chromosomes; i++) {
        int num_genes;
        printf("Enter the number of genes in chromosome %d: ", i+1);
        scanf("%d", &num_genes);
        genome.chromosomes[i] = create_chromosome(num_genes);
    }
    genome.count = num_chromosomes;
    return genome;
}

int main() {
    int num_chromosomes;
    printf("Enter the number of chromosomes in the genome: ");
    scanf("%d", &num_chromosomes);
    Genome genome = create_genome(num_chromosomes);
    printf("\nGenome:\n");
    print_genome(genome);
    return 0;
}