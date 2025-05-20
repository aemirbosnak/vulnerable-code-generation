//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_BASES 4
#define NUM_AMINO_ACIDS 20

typedef struct {
    char *name;
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

Sequence *create_sequence(char *name, int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->name = name;
    seq->length = length;
    return seq;
}

void print_sequence(Sequence *seq) {
    printf("Sequence: %s\n", seq->name);
    printf("Length: %d\n", seq->length);
    printf("Sequence: ");
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Sequence *dna_seq = create_sequence("DNA", rand() % MAX_SEQUENCE_LENGTH + 1);
    Sequence *rna_seq = create_sequence("RNA", rand() % MAX_SEQUENCE_LENGTH + 1);
    Sequence *amino_acid_seq = create_sequence("Amino Acid", rand() % MAX_SEQUENCE_LENGTH + 1);

    for (int i = 0; i < dna_seq->length; i++) {
        dna_seq->sequence[i] = 'A' + rand() % NUM_BASES;
    }

    for (int i = 0; i < rna_seq->length; i++) {
        rna_seq->sequence[i] = 'A' + rand() % NUM_BASES;
    }

    for (int i = 0; i < amino_acid_seq->length; i++) {
        amino_acid_seq->sequence[i] = 'A' + rand() % NUM_AMINO_ACIDS;
    }

    print_sequence(dna_seq);
    print_sequence(rna_seq);
    print_sequence(amino_acid_seq);

    free(dna_seq);
    free(rna_seq);
    free(amino_acid_seq);

    return 0;
}