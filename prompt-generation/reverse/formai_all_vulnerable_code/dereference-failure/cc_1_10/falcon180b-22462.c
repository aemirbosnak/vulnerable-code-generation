//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_NUCLEOTIDES 4
#define NUM_AMINO_ACIDS 20

typedef struct {
    char *name;
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->name = "Random";
    sequence->sequence = malloc(length + 1);
    sequence->length = length;

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % NUM_NUCLEOTIDES;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

Sequence *reverse_complement(Sequence *sequence) {
    Sequence *complement = malloc(sizeof(Sequence));
    complement->name = "Reverse Complement";
    complement->sequence = malloc(sequence->length + 1);
    complement->length = sequence->length;

    for (int i = 0; i < sequence->length; i++) {
        char base = sequence->sequence[i];
        if (base == 'A') {
            complement->sequence[i] = 'T';
        } else if (base == 'C') {
            complement->sequence[i] = 'G';
        } else if (base == 'G') {
            complement->sequence[i] = 'C';
        } else {
            complement->sequence[i] = 'A';
        }
    }
    complement->sequence[sequence->length] = '\0';

    return complement;
}

void print_sequence(Sequence *sequence) {
    printf("Name: %s\n", sequence->name);
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_random_sequence(500);
    print_sequence(sequence);

    Sequence *complement = reverse_complement(sequence);
    print_sequence(complement);

    free(sequence->sequence);
    free(sequence);
    free(complement->sequence);
    free(complement);

    return 0;
}