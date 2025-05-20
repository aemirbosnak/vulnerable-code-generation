//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 100000
#define MAX_NUM_THREADS 8

typedef struct {
    int start;
    int end;
    int strand;
} Gene;

typedef struct {
    char *name;
    int length;
    int num_reads;
    Gene *genes;
} Chromosome;

typedef struct {
    Chromosome *chromosomes;
    int num_chromosomes;
} Genome;

void generate_random_dna(char *dna, int length) {
    for (int i = 0; i < length; i++) {
        dna[i] = 'A' + rand() % 4;
    }
    dna[length] = '\0';
}

void generate_random_gene(Gene *gene) {
    gene->start = rand() % MAX_SEQUENCE_LENGTH;
    gene->end = gene->start + rand() % (MAX_SEQUENCE_LENGTH - gene->start + 1);
    gene->strand = rand() % 2;
}

void generate_random_chromosome(Chromosome *chromosome) {
    chromosome->name = (char *)malloc(sizeof(char) * 10);
    sprintf(chromosome->name, "chr%d", rand() % 23);
    chromosome->length = rand() % MAX_SEQUENCE_LENGTH + 1;
    chromosome->num_reads = rand() % MAX_NUM_READS + 1;
    chromosome->genes = (Gene *)malloc(sizeof(Gene) * chromosome->num_reads);
    for (int i = 0; i < chromosome->num_reads; i++) {
        generate_random_gene(&chromosome->genes[i]);
    }
}

void generate_random_genome(Genome *genome) {
    genome->num_chromosomes = rand() % 24 + 1;
    genome->chromosomes = (Chromosome *)malloc(sizeof(Chromosome) * genome->num_chromosomes);
    for (int i = 0; i < genome->num_chromosomes; i++) {
        generate_random_chromosome(&genome->chromosomes[i]);
    }
}

void print_gene(Gene gene) {
    printf("Gene: (%d, %d) Strand: %d\n", gene.start, gene.end, gene.strand);
}

void print_chromosome(Chromosome chromosome) {
    printf("Chromosome: %s Length: %d Num Reads: %d\n", chromosome.name, chromosome.length, chromosome.num_reads);
    for (int i = 0; i < chromosome.num_reads; i++) {
        print_gene(chromosome.genes[i]);
    }
}

void print_genome(Genome genome) {
    printf("Genome:\n");
    for (int i = 0; i < genome.num_chromosomes; i++) {
        print_chromosome(genome.chromosomes[i]);
    }
}

int main() {
    srand(time(NULL));

    Genome genome;
    generate_random_genome(&genome);
    print_genome(genome);

    return 0;
}