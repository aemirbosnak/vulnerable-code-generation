//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->length = length;
    return sequence;
}

int main() {
    int num_sequences = 10;
    int num_reads = 100;
    Sequence **sequences = malloc(num_sequences * sizeof(Sequence *));
    for (int i = 0; i < num_sequences; i++) {
        sequences[i] = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    }
    printf("Sequences generated:\n");
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]->sequence);
    }
    printf("\n");
    int num_matches = 0;
    for (int i = 0; i < num_reads; i++) {
        Sequence *read = generate_random_sequence(MAX_READ_LENGTH);
        int j;
        for (j = 0; j < num_sequences; j++) {
            int k;
            for (k = 0; k < sequences[j]->length - read->length + 1; k++) {
                int match = 1;
                for (int l = 0; l < read->length; l++) {
                    if (read->sequence[l]!= sequences[j]->sequence[k + l]) {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    printf("Read %d matches sequence %d at position %d\n", i + 1, j + 1, k);
                    num_matches++;
                    break;
                }
            }
            if (num_matches >= 10) {
                break;
            }
        }
        free(read->sequence);
        free(read);
    }
    printf("\nTotal matches found: %d\n", num_matches);
    for (int i = 0; i < num_sequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);
    return 0;
}