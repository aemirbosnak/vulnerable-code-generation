//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100
#define MAX_NUM_BASES 4

typedef struct {
    char name[20];
    int length;
    char *sequence;
} Sequence;

void generateSequence(char *sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_NUM_BASES;
    }
    sequence[length] = '\0';
}

int main() {
    int numSequences;
    printf("Enter the number of sequences: ");
    scanf("%d", &numSequences);

    Sequence *sequences = malloc(numSequences * sizeof(Sequence));

    for (int i = 0; i < numSequences; i++) {
        printf("Enter the name of sequence %d: ", i + 1);
        scanf("%s", sequences[i].name);
        printf("Enter the length of sequence %s: ", sequences[i].name);
        scanf("%d", &sequences[i].length);
        sequences[i].sequence = malloc(sequences[i].length + 1);
        generateSequence(sequences[i].sequence, sequences[i].length);
    }

    printf("\n");
    for (int i = 0; i < numSequences; i++) {
        printf("Sequence %s:\n%s\n", sequences[i].name, sequences[i].sequence);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}