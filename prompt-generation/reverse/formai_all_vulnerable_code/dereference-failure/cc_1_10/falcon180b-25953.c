//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000
#define MAX_NUM_MUTATIONS 1000

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start_pos;
    int end_pos;
} Read;

typedef struct {
    int num_reads;
    Read reads[MAX_NUM_READS];
} ReadSet;

void generate_sequence(Sequence *seq, int length) {
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = rand() % 4;
    }
    seq->sequence[length] = '\0';
    seq->length = length;
}

void generate_reads(ReadSet *reads, Sequence *seq, int num_reads, int read_length) {
    for (int i = 0; i < num_reads; i++) {
        int start_pos = rand() % seq->length;
        int end_pos = start_pos + read_length - 1;
        if (end_pos >= seq->length) {
            end_pos = seq->length - 1;
        }
        reads->reads[i].sequence = malloc((end_pos - start_pos + 1) * sizeof(char));
        strncpy(reads->reads[i].sequence, seq->sequence + start_pos, end_pos - start_pos + 1);
        reads->reads[i].sequence[end_pos - start_pos] = '\0';
        reads->reads[i].start_pos = start_pos;
        reads->reads[i].end_pos = end_pos;
    }
    reads->num_reads = num_reads;
}

void apply_mutations(Sequence *seq, int num_mutations) {
    for (int i = 0; i < num_mutations; i++) {
        int pos = rand() % seq->length;
        seq->sequence[pos] = rand() % 4;
    }
}

int main() {
    srand(time(NULL));

    Sequence reference_seq;
    generate_sequence(&reference_seq, MAX_SEQUENCE_LENGTH);

    ReadSet reads;
    generate_reads(&reads, &reference_seq, MAX_NUM_READS, MAX_READ_LENGTH);

    apply_mutations(&reference_seq, MAX_NUM_MUTATIONS);

    return 0;
}