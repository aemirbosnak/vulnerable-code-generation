//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} Genome;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

Genome *create_genome(int num_sequences, int sequence_length) {
    Genome *genome = (Genome *) malloc(sizeof(Genome));
    genome->num_sequences = num_sequences;
    genome->sequences = (Sequence *) malloc(num_sequences * sizeof(Sequence));

    for (int i = 0; i < num_sequences; i++) {
        genome->sequences[i].sequence = (char *) malloc(sequence_length + 1);
        genome->sequences[i].length = sequence_length;
        generate_random_sequence(genome->sequences[i].sequence, sequence_length);
    }

    return genome;
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        print_sequence(&genome->sequences[i]);
    }
}

int main() {
    srand(time(NULL));

    Genome *genome = create_genome(10, 100);
    print_genome(genome);

    for (int i = 0; i < genome->num_sequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
    free(genome);

    return 0;
}