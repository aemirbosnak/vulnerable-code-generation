//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

void generateRandomSequence(Sequence* sequence) {
    srand(time(NULL));
    for (int i = 0; i < sequence->length; i++) {
        sequence->sequence[i] = rand() % 4; // 0-3 -> A, C, G, T
    }
}

int main() {
    int numSequences;
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &numSequences);

    if (numSequences > MAX_NUM_SEQUENCES) {
        printf("Error: Maximum number of sequences is %d\n", MAX_NUM_SEQUENCES);
        return 1;
    }

    Sequence* sequences = malloc(numSequences * sizeof(Sequence));

    for (int i = 0; i < numSequences; i++) {
        printf("Enter the length of sequence %d: ", i+1);
        scanf("%d", &sequences[i].length);

        if (sequences[i].length > MAX_SEQUENCE_LENGTH) {
            printf("Error: Maximum sequence length is %d\n", MAX_SEQUENCE_LENGTH);
            free(sequences);
            return 1;
        }

        generateRandomSequence(&sequences[i]);
    }

    printf("Generated sequences:\n");
    for (int i = 0; i < numSequences; i++) {
        printf("Sequence %d: %s\n", i+1, sequences[i].sequence);
    }

    free(sequences);
    return 0;
}