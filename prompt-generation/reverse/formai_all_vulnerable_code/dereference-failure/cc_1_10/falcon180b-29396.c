//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
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
    int max_sequence_length;
    int alphabet_size;
} Genome;

Sequence *create_sequence(char *sequence, int length) {
    Sequence *new_sequence = malloc(sizeof(Sequence));
    new_sequence->sequence = malloc(length + 1);
    strcpy(new_sequence->sequence, sequence);
    new_sequence->length = length;
    return new_sequence;
}

Genome *create_genome(int num_sequences, int max_sequence_length, int alphabet_size) {
    Genome *new_genome = malloc(sizeof(Genome));
    new_genome->sequences = malloc(num_sequences * sizeof(Sequence));
    new_genome->num_sequences = num_sequences;
    new_genome->max_sequence_length = max_sequence_length;
    new_genome->alphabet_size = alphabet_size;
    return new_genome;
}

void destroy_sequence(Sequence *sequence) {
    free(sequence->sequence);
    free(sequence);
}

void destroy_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        destroy_sequence(genome->sequences + i);
    }
    free(genome->sequences);
    free(genome);
}

void generate_random_sequence(Sequence *sequence, int length, int alphabet_size) {
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % alphabet_size;
    }
    sequence->sequence[length] = '\0';
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        print_sequence(genome->sequences + i);
    }
}

int main() {
    srand(time(NULL));

    Genome *genome = create_genome(10, 100, 26); // 10 sequences, each with a length of 100 and an alphabet size of 26 (A-Z)

    for (int i = 0; i < genome->num_sequences; i++) {
        generate_random_sequence(genome->sequences + i, genome->max_sequence_length, genome->alphabet_size);
    }

    print_genome(genome);

    destroy_genome(genome);

    return 0;
}