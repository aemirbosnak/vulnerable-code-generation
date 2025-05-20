//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_MUTATION_RATE 0.01

typedef struct {
    char *sequence;
    int length;
} Genome;

Genome *generate_random_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = rand() % 4; // A, C, G, or T
    }
    genome->sequence[length] = '\0';

    return genome;
}

void mutate_genome(Genome *genome, double mutation_rate) {
    for (int i = 0; i < genome->length; i++) {
        if (rand() / (double) RAND_MAX < mutation_rate) {
            genome->sequence[i] = rand() % 4;
        }
    }
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Genome *genome1 = generate_random_genome(100);
    Genome *genome2 = generate_random_genome(100);

    printf("Genome 1:\n");
    print_genome(genome1);
    printf("Genome 2:\n");
    print_genome(genome2);

    double mutation_rate = MAX_MUTATION_RATE;
    int mutations = 0;

    while (mutations < MAX_MUTATION_RATE * genome1->length) {
        mutate_genome(genome1, mutation_rate);
        mutations += count_differences(genome1, genome2);
        mutate_genome(genome2, mutation_rate);
        mutations += count_differences(genome1, genome2);
    }

    printf("Final genomes:\n");
    print_genome(genome1);
    print_genome(genome2);

    return 0;
}

int count_differences(Genome *genome1, Genome *genome2) {
    int differences = 0;

    for (int i = 0; i < genome1->length; i++) {
        if (genome1->sequence[i]!= genome2->sequence[i]) {
            differences++;
        }
    }

    return differences;
}