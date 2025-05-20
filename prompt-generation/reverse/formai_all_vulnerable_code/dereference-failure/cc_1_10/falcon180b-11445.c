//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 1000000

typedef struct {
    char *name;
    int length;
    char *sequence;
} Sequence;

Sequence *create_sequence(char *name, int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->name = strdup(name);
    seq->length = length;
    seq->sequence = malloc(length + 1);
    memset(seq->sequence, 'N', length);
    seq->sequence[length] = '\0';
    return seq;
}

void print_sequence(Sequence *seq) {
    printf("Name: %s\n", seq->name);
    printf("Length: %d\n", seq->length);
    printf("Sequence: %s\n", seq->sequence);
}

void free_sequence(Sequence *seq) {
    free(seq->name);
    free(seq->sequence);
    free(seq);
}

int main() {
    int num_sequences;
    scanf("%d", &num_sequences);

    Sequence **sequences = malloc(num_sequences * sizeof(Sequence *));

    for (int i = 0; i < num_sequences; i++) {
        char name[100];
        scanf("%s", name);
        int length;
        scanf("%d", &length);

        if (length > MAX_SEQUENCE_LENGTH) {
            printf("Error: Sequence length exceeds maximum allowed length.\n");
            exit(1);
        }

        Sequence *seq = create_sequence(name, length);
        sequences[i] = seq;
    }

    for (int i = 0; i < num_sequences; i++) {
        print_sequence(sequences[i]);
    }

    for (int i = 0; i < num_sequences; i++) {
        free_sequence(sequences[i]);
    }
    free(sequences);

    return 0;
}