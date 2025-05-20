//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10
#define NUM_BASES 4
#define NUM_SEQUENCE_TYPES 5

typedef struct {
    char *name;
    char *sequence;
    int length;
    int base_count[NUM_BASES];
    int sequence_type;
} Sequence;

Sequence *generate_sequences(int num_sequences) {
    Sequence *sequences = malloc(sizeof(Sequence) * num_sequences);
    srand(time(NULL));
    for (int i = 0; i < num_sequences; i++) {
        sequences[i].name = "Sequence " + i;
        sequences[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        sequences[i].sequence = malloc(sizeof(char) * sequences[i].length);
        for (int j = 0; j < sequences[i].length; j++) {
            int base = rand() % NUM_BASES;
            sequences[i].sequence[j] = "ACGT"[base];
            sequences[i].base_count[base]++;
        }
        sequences[i].sequence_type = rand() % NUM_SEQUENCE_TYPES;
    }
    return sequences;
}

void print_sequences(Sequence *sequences, int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d:\n", i);
        printf("Name: %s\n", sequences[i].name);
        printf("Length: %d\n", sequences[i].length);
        printf("Sequence: %s\n", sequences[i].sequence);
        printf("Base counts: A %d, C %d, G %d, T %d\n",
               sequences[i].base_count[0], sequences[i].base_count[1],
               sequences[i].base_count[2], sequences[i].base_count[3]);
        printf("Sequence type: %d\n\n", sequences[i].sequence_type);
    }
}

int main() {
    int num_sequences = NUM_SEQUENCES;
    Sequence *sequences = generate_sequences(num_sequences);
    print_sequences(sequences, num_sequences);
    free(sequences);
    return 0;
}