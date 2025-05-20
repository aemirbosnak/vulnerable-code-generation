//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the structure of a chromosome
typedef struct {
    char *name;
    int length;
    char *sequence;
} Chromosome;

// Function to generate a random nucleotide
char rand_nucleotide() {
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    return nucleotides[rand() % 4];
}

// Function to generate a random chromosome sequence
void rand_chromosome(Chromosome *chromosome) {
    chromosome->sequence = (char *)malloc(chromosome->length * sizeof(char));
    for (int i = 0; i < chromosome->length; i++) {
        chromosome->sequence[i] = rand_nucleotide();
    }
}

// Function to print a chromosome sequence
void print_chromosome(Chromosome *chromosome) {
    printf("Chromosome: %s\n", chromosome->name);
    printf("Length: %d\n", chromosome->length);
    printf("Sequence: %s\n", chromosome->sequence);
    printf("\n");
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(int num_chromosomes, int min_length, int max_length) {
    srand(time(NULL));
    Chromosome *chromosomes = (Chromosome *)malloc(num_chromosomes * sizeof(Chromosome));
    for (int i = 0; i < num_chromosomes; i++) {
        chromosomes[i].name = (char *)malloc(10 * sizeof(char));
        sprintf(chromosomes[i].name, "Chr%d", i + 1);
        chromosomes[i].length = rand() % (max_length - min_length + 1) + min_length;
        rand_chromosome(&chromosomes[i]);
    }
    for (int i = 0; i < num_chromosomes; i++) {
        print_chromosome(&chromosomes[i]);
    }
    free(chromosomes);
}

int main() {
    int num_chromosomes, min_length, max_length;
    printf("Enter the number of chromosomes to simulate: ");
    scanf("%d", &num_chromosomes);
    printf("Enter the minimum length of each chromosome: ");
    scanf("%d", &min_length);
    printf("Enter the maximum length of each chromosome: ");
    scanf("%d", &max_length);
    simulate_genome_sequencing(num_chromosomes, min_length, max_length);
    return 0;
}