//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

Sequence *generate_random_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = sequence;
    seq->length = length;
    return seq;
}

Genome *generate_random_genome(int num_sequences, int max_sequence_length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequences = malloc(num_sequences * sizeof(Sequence));
    genome->num_sequences = num_sequences;
    for (int i = 0; i < num_sequences; i++) {
        int sequence_length = rand() % max_sequence_length + 1;
        Sequence *seq = generate_random_sequence(sequence_length);
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
    srand(time(NULL));
    Genome *genome = generate_random_genome(10, MAX_SEQUENCE_LENGTH);
    print_genome(genome);
    for (int i = 0; i < genome->num_sequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
    free(genome);
    return 0;
}