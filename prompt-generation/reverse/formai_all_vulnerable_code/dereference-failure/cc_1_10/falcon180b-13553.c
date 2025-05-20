//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start;
    int end;
    int strand;
} Read;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = (char) rand() % 4; // A, C, G, or T
    }
    seq->length = length;
    return seq;
}

Read *generate_random_read(Sequence *seq, int read_length) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(sizeof(char) * read_length);
    int start = rand() % seq->length;
    int end = start + read_length - 1;
    if (end >= seq->length) {
        end = seq->length - 1;
    }
    for (int i = 0; i < read_length; i++) {
        read->sequence[i] = seq->sequence[start + i];
    }
    read->start = start;
    read->end = end;
    read->strand = (rand() % 2)? 1 : -1; // 1 for forward, -1 for reverse
    return read;
}

void print_sequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    printf("Read: %s\n", read->sequence);
    printf("Start: %d\n", read->start);
    printf("End: %d\n", read->end);
    printf("Strand: %d\n", read->strand);
}

int main() {
    srand(time(NULL));

    Sequence *genome = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    Read *reads[NUM_READS];

    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = generate_random_read(genome, MAX_READ_LENGTH);
    }

    for (int i = 0; i < NUM_READS; i++) {
        print_read(reads[i]);
    }

    return 0;
}