//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100000
#define MAX_BASE_TYPES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    int (*get_base)(void *data);
    void *data;
} BaseGenerator;

int generate_random_base(void *data) {
    return rand() % MAX_BASE_TYPES;
}

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    sequence->length = length;

    for (int i = 0; i < length; i++) {
        int base = generate_random_base(NULL);
        sequence->sequence[i] = "ACGT"[base];
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    print_sequence(sequence);

    free(sequence->sequence);
    free(sequence);

    return 0;
}