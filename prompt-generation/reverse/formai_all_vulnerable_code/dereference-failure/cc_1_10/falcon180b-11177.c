//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_MUTATION_RATE 0.01
#define MAX_SEQUENCE_COUNT 100
#define MAX_SIMULATION_TIME 10000

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

void generate_random_sequence(Sequence *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->length = length;
}

int compare_sequences(Sequence *sequence1, Sequence *sequence2) {
    for (int i = 0; i < sequence1->length && i < sequence2->length; i++) {
        if (sequence1->sequence[i]!= sequence2->sequence[i]) {
            return 1;
        }
    }
    return 0;
}

void mutate_sequence(Sequence *sequence, double mutation_rate) {
    for (int i = 0; i < sequence->length; i++) {
        if (rand() % 100 < mutation_rate * 100) {
            sequence->sequence[i] = 'A' + rand() % 4;
        }
    }
}

int main() {
    srand(time(NULL));

    int sequence_count = rand() % MAX_SEQUENCE_COUNT + 1;
    Sequence *sequences = malloc(sequence_count * sizeof(Sequence));

    for (int i = 0; i < sequence_count; i++) {
        int length = rand() % MAX_SEQUENCE_LENGTH + 1;
        generate_random_sequence(&sequences[i], length);
    }

    int simulation_time = rand() % MAX_SIMULATION_TIME + 1;

    for (int i = 0; i < simulation_time; i++) {
        for (int j = 0; j < sequence_count - 1; j++) {
            for (int k = j + 1; k < sequence_count; k++) {
                if (compare_sequences(&sequences[j], &sequences[k]) == 0) {
                    mutate_sequence(&sequences[j], MAX_MUTATION_RATE);
                    mutate_sequence(&sequences[k], MAX_MUTATION_RATE);
                }
            }
        }
    }

    for (int i = 0; i < sequence_count; i++) {
        printf("%s\n", sequences[i].sequence);
    }

    free(sequences);

    return 0;
}