//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *readSequencesFromFile(FILE *file, int *numSequences) {
    Sequence *sequences = malloc(MAX_NUM_SEQUENCES * sizeof(Sequence));
    int numRead = 0;

    while (numRead < MAX_NUM_SEQUENCES && fscanf(file, "%s", sequences[numRead].sequence)!= EOF) {
        sequences[numRead].length = strlen(sequences[numRead].sequence);
        numRead++;
    }

    *numSequences = numRead;
    return sequences;
}

void generateRandomSequence(char *sequence, int length) {
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 4 + 'A';
    }

    sequence[length] = '\0';
}

void printSequences(Sequence *sequences, int numSequences) {
    for (int i = 0; i < numSequences; i++) {
        printf("%s\n", sequences[i].sequence);
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    Sequence *sequences = NULL;
    int numSequences = 0;

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    sequences = readSequencesFromFile(inputFile, &numSequences);
    fclose(inputFile);

    if (numSequences == 0) {
        printf("Error: no sequences found in input file.\n");
        return 1;
    }

    printf("Sequences:\n");
    printSequences(sequences, numSequences);

    return 0;
}