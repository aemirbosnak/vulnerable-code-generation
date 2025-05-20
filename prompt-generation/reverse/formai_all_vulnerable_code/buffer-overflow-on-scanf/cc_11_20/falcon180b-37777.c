//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

int main() {
    int num_sequences;
    char input_sequence[MAX_SEQUENCE_LENGTH];
    Sequence sequences[MAX_NUM_SEQUENCES];
    int i;

    // Get number of sequences from user
    printf("Enter number of sequences: ");
    scanf("%d", &num_sequences);

    // Read sequences from user
    for (i = 0; i < num_sequences; i++) {
        printf("Enter sequence %d: ", i + 1);
        scanf("%s", input_sequence);
        sequences[i].length = strlen(input_sequence);
        strcpy(sequences[i].sequence, input_sequence);
    }

    // Print sequences
    printf("Sequences:\n");
    for (i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i].sequence);
    }

    // Analyze sequences
    int num_gc = 0;
    int num_at = 0;
    int num_gt = 0;
    int num_ac = 0;
    int num_ag = 0;
    int num_ct = 0;

    for (i = 0; i < num_sequences; i++) {
        int j;
        for (j = 0; j < sequences[i].length; j++) {
            if (sequences[i].sequence[j] == 'G' || sequences[i].sequence[j] == 'C') {
                num_gc++;
            } else if (sequences[i].sequence[j] == 'A' || sequences[i].sequence[j] == 'T') {
                num_at++;
            } else if (sequences[i].sequence[j] == 'G' && sequences[i].sequence[j + 1] == 'T') {
                num_gt++;
            } else if (sequences[i].sequence[j] == 'A' && sequences[i].sequence[j + 1] == 'C') {
                num_ac++;
            } else if (sequences[i].sequence[j] == 'A' && sequences[i].sequence[j + 1] == 'G') {
                num_ag++;
            } else if (sequences[i].sequence[j] == 'C' && sequences[i].sequence[j + 1] == 'T') {
                num_ct++;
            }
        }
    }

    printf("Number of GC pairs: %d\n", num_gc);
    printf("Number of AT pairs: %d\n", num_at);
    printf("Number of GT pairs: %d\n", num_gt);
    printf("Number of AC pairs: %d\n", num_ac);
    printf("Number of AG pairs: %d\n", num_ag);
    printf("Number of CT pairs: %d\n", num_ct);

    return 0;
}