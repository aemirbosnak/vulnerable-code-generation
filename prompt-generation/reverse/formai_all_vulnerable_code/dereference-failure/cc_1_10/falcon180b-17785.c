//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int start;
} Read;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

void generate_reads(Sequence *genome, Read *reads, int num_reads, int read_length) {
    srand(time(NULL));
    for (int i = 0; i < num_reads; i++) {
        reads[i].sequence = malloc(read_length + 1);
        reads[i].length = read_length;
        reads[i].start = rand() % genome->length;
        strncpy(reads[i].sequence, genome->sequence + reads[i].start, read_length);
        reads[i].sequence[read_length] = '\0';
    }
}

int main() {
    Sequence genome;
    Read reads[10];

    generate_random_sequence(genome.sequence, MAX_SEQUENCE_LENGTH);
    genome.length = MAX_SEQUENCE_LENGTH;

    generate_reads(&genome, reads, 10, MAX_READ_LENGTH);

    for (int i = 0; i < 10; i++) {
        printf("Read %d: %s\n", i + 1, reads[i].sequence);
    }

    return 0;
}