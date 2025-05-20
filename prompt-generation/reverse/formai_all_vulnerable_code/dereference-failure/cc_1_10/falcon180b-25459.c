//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_ALLELES 4

typedef struct {
    char *sequence;
    int length;
    int num_alleles;
    int *allele_lengths;
} Genome;

Genome *generate_genome(int num_alleles) {
    Genome *genome = malloc(sizeof(Genome));
    genome->num_alleles = num_alleles;
    genome->allele_lengths = malloc(num_alleles * sizeof(int));
    for (int i = 0; i < num_alleles; i++) {
        genome->allele_lengths[i] = rand() % 100 + 1;
    }
    genome->length = 0;
    for (int i = 0; i < num_alleles; i++) {
        genome->length += genome->allele_lengths[i];
    }
    genome->sequence = malloc(genome->length * sizeof(char));
    for (int i = 0; i < genome->length; i++) {
        genome->sequence[i] = rand() % 4 + 'A';
    }
    return genome;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_alleles; i++) {
        printf("Allele %d: ", i + 1);
        for (int j = 0; j < genome->allele_lengths[i]; j++) {
            printf("%c", genome->sequence[i * genome->allele_lengths[i] + j]);
        }
        printf("\n");
    }
}

void free_genome(Genome *genome) {
    free(genome->sequence);
    free(genome->allele_lengths);
    free(genome);
}

int main() {
    srand(time(NULL));

    Genome *genome = generate_genome(2);
    print_genome(genome);

    free_genome(genome);

    return 0;
}