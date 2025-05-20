//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_SIZE 1000000
#define MAX_SEQUENCE_LENGTH 100

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

void generate_random_genome(Genome *genome) {
    srand(time(NULL));
    int i;

    for (i = 0; i < MAX_GENOME_SIZE; i++) {
        Sequence sequence;
        sequence.length = rand() % MAX_SEQUENCE_LENGTH + 1;
        sequence.sequence[sequence.length - 1] = '\0';

        int j;
        for (j = 0; j < sequence.length - 1; j++) {
            sequence.sequence[j] = 'A' + rand() % 4;
        }

        genome->sequences[genome->num_sequences] = sequence;
        genome->num_sequences++;
    }
}

void print_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->num_sequences; i++) {
        printf("%s\n", genome->sequences[i].sequence);
    }
}

int main() {
    Genome genome;
    generate_random_genome(&genome);
    print_genome(&genome);

    return 0;
}