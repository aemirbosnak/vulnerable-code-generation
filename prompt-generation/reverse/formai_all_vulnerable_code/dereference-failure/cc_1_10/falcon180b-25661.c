//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_READS 1000000

typedef struct {
    char *name;
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *name;
    int length;
    int start;
    int end;
} Read;

Sequence *generate_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->name = "Sequence";
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->length = length;
    return seq;
}

Read *generate_read(Sequence *seq, int read_length) {
    Read *read = malloc(sizeof(Read));
    read->name = "Read";
    read->length = read_length;
    read->start = rand() % seq->length;
    read->end = read->start + read_length - 1;
    if (read->end >= seq->length) {
        read->end = seq->length - 1;
    }
    return read;
}

void print_sequence(Sequence *seq) {
    printf("Sequence name: %s\n", seq->name);
    printf("Sequence length: %d\n", seq->length);
    printf("Sequence:\n%s\n", seq->sequence);
}

void print_read(Read *read) {
    printf("Read name: %s\n", read->name);
    printf("Read length: %d\n", read->length);
    printf("Read start position: %d\n", read->start);
    printf("Read end position: %d\n", read->end);
}

int main() {
    srand(time(NULL));

    Sequence *seq = generate_sequence(MAX_SEQUENCE_LENGTH);
    Read *read = generate_read(seq, MAX_READ_LENGTH);

    print_sequence(seq);
    print_read(read);

    free(seq->sequence);
    free(seq);
    free(read);

    return 0;
}