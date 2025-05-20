//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

int compare_sequences(const void *a, const void *b) {
    const Sequence *seq1 = a;
    const Sequence *seq2 = b;

    return strcmp(seq1->sequence, seq2->sequence);
}

int main() {
    srand(time(NULL));

    int num_sequences;
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &num_sequences);

    Sequence *sequences = malloc(num_sequences * sizeof(Sequence));

    for (int i = 0; i < num_sequences; i++) {
        char sequence[MAX_SEQUENCE_LENGTH];
        int length;

        printf("Enter the length of sequence %d: ", i + 1);
        scanf("%d", &length);

        if (length > MAX_SEQUENCE_LENGTH) {
            printf("Sequence length must be less than or equal to %d.\n", MAX_SEQUENCE_LENGTH);
            exit(1);
        }

        generate_random_sequence(sequence, length);
        sequences[i].sequence = strdup(sequence);
        sequences[i].length = length;
    }

    qsort(sequences, num_sequences, sizeof(Sequence), compare_sequences);

    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i].sequence);
    }

    for (int i = 0; i < num_sequences; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}