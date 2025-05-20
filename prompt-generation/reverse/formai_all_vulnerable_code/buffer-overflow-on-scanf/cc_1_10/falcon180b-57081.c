//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_SEQUENCES 10

typedef struct {
    char name[20];
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

int main() {
    int num_sequences, i, j, k;
    Sequence sequences[MAX_SEQUENCES];

    printf("Welcome to the C Genome Sequencing Simulator!\n");
    printf("How many sequences do you want to simulate? ");
    scanf("%d", &num_sequences);

    for (i = 0; i < num_sequences; i++) {
        printf("Enter the name of sequence %d: ", i+1);
        scanf("%s", sequences[i].name);

        printf("Enter the sequence: ");
        scanf("%s", sequences[i].sequence);

        sequences[i].length = strlen(sequences[i].sequence);
    }

    printf("\nSequences:\n");
    for (i = 0; i < num_sequences; i++) {
        printf("Name: %s\n", sequences[i].name);
        printf("Sequence: ");
        for (j = 0; j < sequences[i].length; j++) {
            if (sequences[i].sequence[j] == 'A') {
                printf("A");
            } else if (sequences[i].sequence[j] == 'C') {
                printf("C");
            } else if (sequences[i].sequence[j] == 'G') {
                printf("G");
            } else if (sequences[i].sequence[j] == 'T') {
                printf("T");
            } else {
                printf("N");
            }
        }
        printf("\n");
    }

    return 0;
}