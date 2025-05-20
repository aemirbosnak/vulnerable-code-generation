//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MIN_READ_LENGTH 50

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(length + 1);
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->sequence[length] = '\0';

    return seq;
}

Genome *generate_random_genome(int num_sequences, int min_length, int max_length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->num_sequences = num_sequences;
    genome->sequences = malloc(num_sequences * sizeof(Sequence));

    srand(time(NULL));

    for (int i = 0; i < num_sequences; i++) {
        int length = min_length + rand() % (max_length - min_length + 1);
        Sequence *seq = generate_random_sequence(length);
        genome->sequences[i] = *seq;
        free(seq->sequence);
        free(seq);
    }

    return genome;
}

void print_sequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        print_sequence(genome->sequences + i);
    }
}

int main() {
    Genome *genome = generate_random_genome(10, 50, 100);
    print_genome(genome);

    free(genome->sequences);
    free(genome);

    return 0;
}