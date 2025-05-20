//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 5
#define MAX_NUM_READS 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int num_errors;
} Read;

Sequence *generate_sequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4; // A, C, G, or T
    }
    seq->sequence[length] = '\0';
    return seq;
}

Read *generate_read(Sequence *sequence, int read_length) {
    Read *read = malloc(sizeof(Read));
    read->length = read_length;
    read->num_errors = rand() % MAX_ERRORS + 1;
    read->sequence = malloc(read_length + 1);
    int start_pos = rand() % (sequence->length - read_length + 1);
    for (int i = 0; i < read_length; i++) {
        read->sequence[i] = sequence->sequence[start_pos + i];
    }
    read->sequence[read_length] = '\0';
    return read;
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

void print_read(Read *read) {
    printf("Read: %s\n", read->sequence);
    printf("Length: %d\n", read->length);
    printf("Number of errors: %d\n", read->num_errors);
}

int main() {
    srand(time(NULL));

    Sequence *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);
    Read *reads[MAX_NUM_READS];

    int num_reads = 0;
    while (num_reads < MAX_NUM_READS && sequence->length >= MAX_READ_LENGTH) {
        Read *read = generate_read(sequence, MAX_READ_LENGTH);
        reads[num_reads++] = read;
    }

    printf("Sequence:\n");
    print_sequence(sequence);

    printf("Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        print_read(reads[i]);
    }

    return 0;
}