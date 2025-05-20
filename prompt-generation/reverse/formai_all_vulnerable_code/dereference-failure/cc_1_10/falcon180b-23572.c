//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_SEQUENCE_COUNT 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int count;
} Genome;

void init_genome(Genome *genome) {
    genome->sequences = NULL;
    genome->count = 0;
}

void free_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->count; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
}

void add_sequence(Genome *genome, char *sequence, int length) {
    Sequence *new_sequence = malloc(sizeof(Sequence));
    new_sequence->sequence = malloc(length + 1);
    strcpy(new_sequence->sequence, sequence);
    new_sequence->length = length;
    genome->sequences = realloc(genome->sequences, sizeof(Sequence) * (genome->count + 1));
    genome->sequences[genome->count++] = *new_sequence;
}

void print_genome(Genome *genome) {
    int i;
    for (i = 0; i < genome->count; i++) {
        printf("%s\n", genome->sequences[i].sequence);
    }
}

int main() {
    char input[MAX_SEQUENCE_LENGTH];
    Genome genome;
    init_genome(&genome);

    while (fgets(input, MAX_SEQUENCE_LENGTH, stdin)!= NULL) {
        int length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[--length] = '\0';
        }
        add_sequence(&genome, input, length);
    }

    print_genome(&genome);

    free_genome(&genome);

    return 0;
}