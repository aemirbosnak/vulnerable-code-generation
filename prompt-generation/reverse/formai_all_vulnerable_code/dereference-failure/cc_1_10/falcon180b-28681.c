//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_ALPHABET_SIZE 4
#define MAX_MUTATION_RATE 0.01

typedef struct {
    char *sequence;
    int length;
} Genome;

void generate_random_genome(Genome *genome, int length, char *alphabet) {
    srand(time(NULL));
    genome->length = length;
    genome->sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = alphabet[rand() % strlen(alphabet)];
    }
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

int compare_genomes(Genome *genome1, Genome *genome2) {
    for (int i = 0; i < genome1->length; i++) {
        if (genome1->sequence[i]!= genome2->sequence[i]) {
            return 1;
        }
    }
    return 0;
}

void mutate_genome(Genome *genome, double mutation_rate) {
    for (int i = 0; i < genome->length; i++) {
        if (rand() % 100 < mutation_rate * 100) {
            genome->sequence[i] = rand() % 4 + 'A';
        }
    }
}

int main() {
    Genome genome1, genome2;
    char alphabet[] = "ACGT";
    int length = 1000;

    generate_random_genome(&genome1, length, alphabet);
    generate_random_genome(&genome2, length, alphabet);

    printf("Initial genomes:\n");
    print_genome(&genome1);
    print_genome(&genome2);

    int iterations = 1000;
    for (int i = 0; i < iterations; i++) {
        mutate_genome(&genome1, MAX_MUTATION_RATE);
        mutate_genome(&genome2, MAX_MUTATION_RATE);
    }

    printf("\nGenomes after %d iterations:\n", iterations);
    print_genome(&genome1);
    print_genome(&genome2);

    if (compare_genomes(&genome1, &genome2)) {
        printf("The genomes are different.\n");
    } else {
        printf("The genomes are the same.\n");
    }

    free(genome1.sequence);
    free(genome2.sequence);

    return 0;
}