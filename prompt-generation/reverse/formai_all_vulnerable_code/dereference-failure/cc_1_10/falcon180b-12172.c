//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000000

typedef struct {
    char *genome;
    int genome_length;
    char **reads;
    int num_reads;
} Genome;

Genome *create_genome(int genome_length) {
    Genome *genome = malloc(sizeof(Genome));

    genome->genome = malloc(genome_length * sizeof(char));
    for (int i = 0; i < genome_length; i++) {
        genome->genome[i] = 'A' + rand() % 4;
    }

    genome->genome_length = genome_length;
    genome->num_reads = 0;
    genome->reads = NULL;

    return genome;
}

void destroy_genome(Genome *genome) {
    free(genome->genome);
    for (int i = 0; i < genome->num_reads; i++) {
        free(genome->reads[i]);
    }
    free(genome->reads);
    free(genome);
}

void add_read(Genome *genome, char *read) {
    genome->reads = realloc(genome->reads, sizeof(char *) * (genome->num_reads + 1));
    genome->reads[genome->num_reads] = read;
    genome->num_reads++;
}

int main() {
    srand(time(NULL));

    Genome *genome = create_genome(MAX_GENOME_LENGTH);
    for (int i = 0; i < MAX_NUM_READS; i++) {
        char *read = malloc(MAX_READ_LENGTH * sizeof(char));
        for (int j = 0; j < MAX_READ_LENGTH; j++) {
            read[j] = 'A' + rand() % 4;
        }
        add_read(genome, read);
    }

    printf("The genome is %d bases long.\n", genome->genome_length);
    printf("There are %d reads.\n", genome->num_reads);

    destroy_genome(genome);

    return 0;
}