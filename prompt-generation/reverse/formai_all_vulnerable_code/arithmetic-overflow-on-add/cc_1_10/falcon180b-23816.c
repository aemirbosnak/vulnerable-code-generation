//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_CHARACTERS 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        int random_index = rand() % MAX_CHARACTERS;
        sequence->sequence[i] = "ACGT"[random_index];
    }
}

int main() {
    int num_sequences, sequence_length;
    Sequence *sequences;
    srand(time(NULL));

    printf("Enter the number of sequences to generate: ");
    scanf("%d", &num_sequences);

    printf("Enter the length of each sequence: ");
    scanf("%d", &sequence_length);

    sequences = (Sequence *) malloc(num_sequences * sizeof(Sequence));

    int i;
    for (i = 0; i < num_sequences; i++) {
        sequences[i].sequence = (char *) malloc(sequence_length + 1);
        sequences[i].length = sequence_length;
        generate_random_sequence(&sequences[i]);
    }

    int j;
    for (j = 0; j < num_sequences; j++) {
        printf("Sequence %d: %s\n", j + 1, sequences[j].sequence);
    }

    for (j = 0; j < num_sequences; j++) {
        free(sequences[j].sequence);
    }
    free(sequences);

    return 0;
}