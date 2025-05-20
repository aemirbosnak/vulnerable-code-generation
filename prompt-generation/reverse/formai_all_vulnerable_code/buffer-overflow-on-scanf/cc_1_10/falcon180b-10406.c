//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000
#define MAX_NUM_SEQ 1000

typedef struct {
    char *name;
    int length;
    char *sequence;
} Sequence;

int generate_random_sequence(char *sequence, int length) {
    int i;
    for (i = 0; i < length; i++) {
        sequence[i] = rand() % 4 + 'A';
    }
    sequence[length] = '\0';
    return 0;
}

int compare_sequences(const void *a, const void *b) {
    Sequence *seq1 = (Sequence *)a;
    Sequence *seq2 = (Sequence *)b;
    return strcmp(seq1->sequence, seq2->sequence);
}

int main() {
    srand(time(NULL));
    int num_sequences;
    printf("Enter the number of sequences: ");
    scanf("%d", &num_sequences);

    Sequence *sequences = malloc(num_sequences * sizeof(Sequence));

    int i;
    for (i = 0; i < num_sequences; i++) {
        char name[10];
        sprintf(name, "Seq%d", i+1);
        sequences[i].name = strdup(name);
        sequences[i].length = rand() % MAX_SEQ_LENGTH + 1;
        sequences[i].sequence = malloc(sequences[i].length + 1);
        generate_random_sequence(sequences[i].sequence, sequences[i].length);
    }

    qsort(sequences, num_sequences, sizeof(Sequence), compare_sequences);

    printf("Sorted sequences:\n");
    for (i = 0; i < num_sequences; i++) {
        printf("%s (%d bp): %s\n", sequences[i].name, sequences[i].length, sequences[i].sequence);
    }

    for (i = 0; i < num_sequences; i++) {
        free(sequences[i].name);
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}