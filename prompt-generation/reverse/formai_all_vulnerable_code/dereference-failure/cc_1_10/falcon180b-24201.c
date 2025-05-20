//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000000
#define MAX_SEQUENCE_LENGTH_STR "10000000"
#define MAX_SEQUENCE_LENGTH_LOG 7

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = malloc(length + 1);

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = rand() % 4 + 'A';
    }
    seq->sequence[length] = '\0';

    return seq;
}

void print_sequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sequence_length>\n", argv[0]);
        return 1;
    }

    int sequence_length = atoi(argv[1]);

    if (sequence_length <= 0 || sequence_length > MAX_SEQUENCE_LENGTH) {
        printf("Invalid sequence length.\n");
        return 1;
    }

    Sequence *sequence = generate_random_sequence(sequence_length);
    print_sequence(sequence);

    free(sequence->sequence);
    free(sequence);

    return 0;
}