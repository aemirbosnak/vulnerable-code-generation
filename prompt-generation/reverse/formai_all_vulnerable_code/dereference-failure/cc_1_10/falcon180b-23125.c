//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READS 10000
#define MAX_READ_LENGTH 100

typedef struct {
    char *name;
    char *sequence;
    int length;
} Contig;

typedef struct {
    int start;
    int end;
    int length;
} Read;

Contig *contigs;
int num_contigs;
Read *reads;
int num_reads;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int num_contigs_input = 10;
    int num_reads_input = 100;
    int max_read_length_input = 100;

    if (argc > 1) {
        num_contigs_input = atoi(argv[1]);
    }

    if (argc > 2) {
        num_reads_input = atoi(argv[2]);
    }

    if (argc > 3) {
        max_read_length_input = atoi(argv[3]);
    }

    contigs = (Contig *) malloc(num_contigs_input * sizeof(Contig));
    num_contigs = 0;

    for (int i = 0; i < num_contigs_input; i++) {
        char name[10];
        sprintf(name, "C%d", i);
        Contig contig = {name, (char *) malloc(MAX_SEQUENCE_LENGTH), 0};
        generate_random_sequence(contig.sequence, MAX_SEQUENCE_LENGTH);
        contig.length = strlen(contig.sequence);
        contigs[num_contigs++] = contig;
    }

    reads = (Read *) malloc(num_reads_input * sizeof(Read));
    num_reads = 0;

    for (int i = 0; i < num_reads_input; i++) {
        int start = rand() % MAX_SEQUENCE_LENGTH;
        int length = rand() % max_read_length_input + 1;
        Read read = {start, start + length - 1, length};
        reads[num_reads++] = read;
    }

    return 0;
}