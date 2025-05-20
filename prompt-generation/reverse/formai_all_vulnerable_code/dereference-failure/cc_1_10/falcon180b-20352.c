//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000
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

int compare_sequences(const void *a, const void *b) {
    Sequence *seq_a = (Sequence *)a;
    Sequence *seq_b = (Sequence *)b;

    return strcmp(seq_a->sequence, seq_b->sequence);
}

void print_sequences(Genome *genome) {
    for (int i = 0; i < genome->num_sequences; i++) {
        printf("%s\n", genome->sequences[i].sequence);
    }
}

int main() {
    Genome genome;
    genome.sequences = NULL;
    genome.num_sequences = 0;
    genome.max_sequence_length = 0;

    int num_sequences;
    printf("Enter the number of sequences: ");
    scanf("%d", &num_sequences);

    genome.sequences = malloc(num_sequences * sizeof(Sequence));

    for (int i = 0; i < num_sequences; i++) {
        Sequence sequence;
        printf("Enter the length of sequence %d: ", i + 1);
        scanf("%d", &sequence.length);

        if (sequence.length > MAX_SEQ_LENGTH) {
            printf("Sequence length must be less than or equal to %d.\n", MAX_SEQ_LENGTH);
            exit(1);
        }

        sequence.sequence = malloc((sequence.length + 1) * sizeof(char));
        generate_random_sequence(sequence.sequence, sequence.length);

        genome.sequences[i] = sequence;

        if (sequence.length > genome.max_sequence_length) {
            genome.max_sequence_length = sequence.length;
        }
    }

    qsort(genome.sequences, num_sequences, sizeof(Sequence), compare_sequences);

    printf("Sorted sequences:\n");
    print_sequences(&genome);

    free(genome.sequences);
    return 0;
}