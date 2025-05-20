//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 10
#define MAX_NUM_READS 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start;
    int length;
} Read;

typedef struct {
    Read *reads;
    int num_reads;
} ReadSet;

void generate_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

void generate_reads(Sequence *sequence, ReadSet *read_set) {
    int num_reads = rand() % MAX_NUM_READS + 1;
    read_set->num_reads = num_reads;
    read_set->reads = malloc(num_reads * sizeof(Read));

    for (int i = 0; i < num_reads; i++) {
        int read_length = rand() % (MAX_READ_LENGTH - 1) + 1;
        int start_pos = rand() % (sequence->length - read_length);
        Read *read = &read_set->reads[i];
        read->sequence = malloc((read_length + 1) * sizeof(char));
        read->start = start_pos;
        read->length = read_length;
        strncpy(read->sequence, &sequence->sequence[start_pos], read_length);
        read->sequence[read_length] = '\0';
    }
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
}

void print_read(Read *read) {
    printf("Read: %s\n", read->sequence);
}

void print_read_set(ReadSet *read_set) {
    printf("Number of reads: %d\n", read_set->num_reads);
    for (int i = 0; i < read_set->num_reads; i++) {
        print_read(&read_set->reads[i]);
    }
}

int main() {
    srand(time(NULL));

    Sequence sequence;
    generate_sequence(sequence.sequence, sequence.length);

    ReadSet read_set;
    generate_reads(&sequence, &read_set);

    print_sequence(&sequence);
    print_read_set(&read_set);

    return 0;
}