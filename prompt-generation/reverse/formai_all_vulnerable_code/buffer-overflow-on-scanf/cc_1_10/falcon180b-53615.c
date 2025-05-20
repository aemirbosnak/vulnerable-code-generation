//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
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
} Genome;

void generate_random_sequence(char *sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

Genome *create_genome(int num_sequences, int max_sequence_length) {
    Genome *genome = malloc(sizeof(Genome));
    genome->sequences = malloc(sizeof(Sequence) * num_sequences);
    genome->num_sequences = num_sequences;
    genome->max_sequence_length = max_sequence_length;

    for (int i = 0; i < num_sequences; i++) {
        genome->sequences[i].sequence = malloc(sizeof(char) * max_sequence_length);
        genome->sequences[i].length = 0;
    }

    return genome;
}

void destroy_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
    free(genome);
}

void print_genome(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        printf("Sequence %d: %s\n", i+1, genome->sequences[i].sequence);
    }
}

int main() {
    int num_sequences;
    printf("Enter the number of sequences: ");
    scanf("%d", &num_sequences);

    int max_sequence_length;
    printf("Enter the maximum sequence length: ");
    scanf("%d", &max_sequence_length);

    Genome *genome = create_genome(num_sequences, max_sequence_length);

    for (int i = 0; i < num_sequences; i++) {
        generate_random_sequence(genome->sequences[i].sequence, max_sequence_length);
        genome->sequences[i].length = strlen(genome->sequences[i].sequence);
    }

    printf("Generated genome:\n");
    print_genome(genome);

    destroy_genome(genome);

    return 0;
}