//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_CHARS_PER_READ 500

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} read_t;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Failed to open input file\n");
        return 1;
    }

    read_t reads[MAX_CHARS_PER_READ];
    int num_reads = 0;

    char line[MAX_CHARS_PER_READ];
    while (fgets(line, sizeof(line), input_file)) {
        if (num_reads == MAX_CHARS_PER_READ) {
            fprintf(stderr, "Too many reads, aborting\n");
            return 1;
        }

        if (sscanf(line, "@%s/1", reads[num_reads].sequence)!= 1) {
            fprintf(stderr, "Invalid read format, skipping\n");
            continue;
        }

        reads[num_reads].length = strlen(reads[num_reads].sequence);
        num_reads++;
    }

    fclose(input_file);

    int num_bases = 0;
    int num_bases_per_read = 0;

    char bases[MAX_SEQUENCE_LENGTH];
    int num_bases_in_sequence = 0;

    for (int i = 0; i < num_reads; i++) {
        int num_bases_in_read = reads[i].length - 1;
        for (int j = 0; j < num_bases_in_read; j++) {
            bases[num_bases_in_sequence] = reads[i].sequence[j + 1];
            num_bases_in_sequence++;
        }
        num_bases_in_sequence += reads[i].length - num_bases_in_read - 1;

        num_bases += num_bases_in_read;
        num_bases_per_read += num_bases_in_read;
    }

    printf("Number of bases: %d\n", num_bases);
    printf("Number of bases per read: %d\n", num_bases_per_read);

    return 0;
}