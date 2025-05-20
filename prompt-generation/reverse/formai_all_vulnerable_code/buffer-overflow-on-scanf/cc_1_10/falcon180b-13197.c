//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUM_SEQUENCES 100
#define MAX_SEQUENCE_NAME_LENGTH 50

typedef struct {
    char name[MAX_SEQUENCE_NAME_LENGTH];
    char sequence[MAX_SEQUENCE_LENGTH];
} Sequence;

int main() {
    int num_sequences;
    Sequence sequences[MAX_NUM_SEQUENCES];
    char alphabet[MAX_ALPHABET_SIZE] = "ACGT";
    int i, j, k, l, m, n;
    char *ptr;
    FILE *fp;

    // Get number of sequences from user
    printf("Enter the number of sequences: ");
    scanf("%d", &num_sequences);

    // Get sequence names from user
    for (i = 0; i < num_sequences; i++) {
        printf("Enter the name of sequence %d: ", i + 1);
        scanf("%s", sequences[i].name);
    }

    // Generate random sequences
    srand(time(NULL));
    for (i = 0; i < num_sequences; i++) {
        for (j = 0; j < MAX_SEQUENCE_LENGTH; j++) {
            sequences[i].sequence[j] = alphabet[rand() % MAX_ALPHABET_SIZE];
        }
        sequences[i].sequence[MAX_SEQUENCE_LENGTH - 1] = '\0';
    }

    // Print sequences
    printf("\nSequences:\n");
    for (i = 0; i < num_sequences; i++) {
        printf("Sequence %s:\n%s\n", sequences[i].name, sequences[i].sequence);
    }

    // Write sequences to file
    fp = fopen("sequences.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    for (i = 0; i < num_sequences; i++) {
        fprintf(fp, ">%s\n%s\n", sequences[i].name, sequences[i].sequence);
    }
    fclose(fp);

    return 0;
}