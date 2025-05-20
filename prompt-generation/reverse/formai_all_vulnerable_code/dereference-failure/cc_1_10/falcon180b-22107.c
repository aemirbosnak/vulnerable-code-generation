//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *name;
    char *sequence;
    int length;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
}

void print_genome(Genome *genome) {
    printf("ID: %d\n", genome->id);
    printf("Name: %s\n", genome->name);
    printf("Sequence: %s\n", genome->sequence);
    printf("Length: %d\n", genome->length);
}

int main() {
    srand(time(NULL));

    int num_genomes = 10;
    Genome *genomes = malloc(num_genomes * sizeof(Genome));

    for (int i = 0; i < num_genomes; i++) {
        genomes[i].id = i + 1;
        genomes[i].name = "Genome ";
        genomes[i].sequence = malloc(100 * sizeof(char));
        generate_random_sequence(genomes[i].sequence, 100);
        genomes[i].length = 100;
    }

    for (int i = 0; i < num_genomes; i++) {
        print_genome(&genomes[i]);
    }

    for (int i = 0; i < num_genomes; i++) {
        free(genomes[i].sequence);
        free(genomes[i].name);
    }
    free(genomes);

    return 0;
}