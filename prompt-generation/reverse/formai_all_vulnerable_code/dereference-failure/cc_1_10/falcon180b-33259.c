//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MIN_SEQUENCE_LENGTH 100
#define MAX_NUM_SEQUENCES 100
#define MIN_NUM_SEQUENCES 1

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(Sequence *sequence) {
    int i;
    for (i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = (char) ('A' + rand() % 4);
    }
}

int main(int argc, char *argv[]) {
    int num_sequences;
    int sequence_length;
    Sequence *sequences;

    srand(time(NULL));

    printf("Enter the number of sequences to generate (between %d and %d): ", MIN_NUM_SEQUENCES, MAX_NUM_SEQUENCES);
    scanf("%d", &num_sequences);

    printf("Enter the length of each sequence (between %d and %d): ", MIN_SEQUENCE_LENGTH, MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);

    sequences = malloc(num_sequences * sizeof(Sequence));
    if (sequences == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 1;
    }

    for (int i = 0; i < num_sequences; i++) {
        sequences[i].sequence = malloc(sequence_length * sizeof(char));
        if (sequences[i].sequence == NULL) {
            printf("Error: Could not allocate memory.\n");
            return 1;
        }
        sequences[i].length = sequence_length;
        generate_random_sequence(&sequences[i]);
    }

    printf("Sequences generated:\n");
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i].sequence);
    }

    free(sequences);
    return 0;
}