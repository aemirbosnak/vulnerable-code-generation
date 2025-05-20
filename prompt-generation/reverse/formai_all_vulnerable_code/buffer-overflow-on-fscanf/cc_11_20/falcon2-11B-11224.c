//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <fasta_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *fasta_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    char sequence[MAX_SEQUENCE_LENGTH];
    char current_base = 'A';

    int count = 0;
    while (fscanf(fasta_file, "%s", sequence)!= EOF) {
        int length = strlen(sequence);

        if (length > MAX_SEQUENCE_LENGTH) {
            fprintf(stderr, "Sequence length exceeds maximum allowed length of %d\n", MAX_SEQUENCE_LENGTH);
            exit(1);
        }

        if (sequence[0]!= '>') {
            for (int i = 0; i < length; i++) {
                if (sequence[i] == 'A') {
                    current_base = 'A';
                } else if (sequence[i] == 'T') {
                    current_base = 'T';
                } else if (sequence[i] == 'C') {
                    current_base = 'C';
                } else if (sequence[i] == 'G') {
                    current_base = 'G';
                } else {
                    fprintf(stderr, "Invalid base character: %c\n", sequence[i]);
                    exit(1);
                }

                if (count == 0 && current_base!= 'N') {
                    fprintf(output_file, "%c", current_base);
                    count++;
                } else if (current_base == 'N') {
                    count--;
                } else if (current_base!= 'N' && (count % 2) == 0) {
                    fprintf(output_file, "%c", current_base);
                    count++;
                }
            }

            fprintf(output_file, "\n");
        } else {
            fprintf(output_file, "//\n");
        }
    }

    fclose(fasta_file);
    fclose(output_file);

    return 0;
}