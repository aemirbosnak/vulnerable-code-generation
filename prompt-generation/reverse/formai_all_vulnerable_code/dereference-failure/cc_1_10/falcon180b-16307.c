//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_MUTATION_RATE 0.001

typedef struct {
    char *sequence;
    int length;
} Genome;

Genome *generate_random_genome(int length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequence = malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % 4;
    }
    genome->sequence[length] = '\0';

    return genome;
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

void mutate_genome(Genome *genome, double mutation_rate) {
    for (int i = 0; i < genome->length; i++) {
        if (rand() % 1000 < (int)(mutation_rate * 1000)) {
            genome->sequence[i] = 'A' + rand() % 4;
        }
    }
}

int main() {
    srand(time(NULL));

    int sequence_length = MAX_SEQUENCE_LENGTH;
    double mutation_rate = MAX_MUTATION_RATE;

    Genome *initial_genome = generate_random_genome(sequence_length);
    printf("Initial genome:\n");
    print_genome(initial_genome);

    for (int generation = 0; generation < 10; generation++) {
        Genome *next_genome = malloc(sizeof(Genome));
        next_genome->sequence = malloc(sequence_length + 1);
        next_genome->length = sequence_length;

        for (int i = 0; i < sequence_length; i++) {
            next_genome->sequence[i] = initial_genome->sequence[i];
        }

        mutate_genome(next_genome, mutation_rate);

        printf("Generation %d:\n", generation + 1);
        print_genome(next_genome);

        free(initial_genome->sequence);
        free(initial_genome);
        initial_genome = next_genome;
    }

    return 0;
}