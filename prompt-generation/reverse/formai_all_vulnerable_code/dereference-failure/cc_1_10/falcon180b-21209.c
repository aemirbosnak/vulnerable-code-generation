//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 4
#define MAX_GENOME_SIZE (MAX_SEQUENCE_LENGTH * MAX_ALPHABET_SIZE)

typedef struct {
    int sequence_length;
    int alphabet_size;
    char *genome;
} Genome;

Genome *create_genome(int sequence_length, int alphabet_size) {
    Genome *genome = (Genome *) malloc(sizeof(Genome));
    genome->sequence_length = sequence_length;
    genome->alphabet_size = alphabet_size;
    genome->genome = (char *) malloc(sequence_length * alphabet_size * sizeof(char));
    int i, j;
    for (i = 0; i < sequence_length; i++) {
        for (j = 0; j < alphabet_size; j++) {
            genome->genome[i * alphabet_size + j] = (char) ('A' + rand() % alphabet_size);
        }
    }
    return genome;
}

void print_genome(Genome *genome) {
    int i, j;
    for (i = 0; i < genome->sequence_length; i++) {
        for (j = 0; j < genome->alphabet_size; j++) {
            printf("%c", genome->genome[i * genome->alphabet_size + j]);
        }
        printf("\n");
    }
}

void free_genome(Genome *genome) {
    free(genome->genome);
    free(genome);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int sequence_length = MAX_SEQUENCE_LENGTH;
    int alphabet_size = MAX_ALPHABET_SIZE;
    Genome *genome = create_genome(sequence_length, alphabet_size);
    print_genome(genome);
    free_genome(genome);
    return 0;
}