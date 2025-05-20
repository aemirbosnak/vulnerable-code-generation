//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_DNA_SEQUENCE_LENGTH 1000000
#define DNA_SEQUENCE_FILE "DNA.txt"
#define DNA_SEQUENCE_FILE_MODE "r"

int main() {
    char dna_sequence[MAX_DNA_SEQUENCE_LENGTH];
    FILE *dna_file = fopen(DNA_SEQUENCE_FILE, DNA_SEQUENCE_FILE_MODE);

    if (dna_file == NULL) {
        fprintf(stderr, "Error: could not open DNA sequence file.\n");
        exit(1);
    }

    fseek(dna_file, 0, SEEK_END);
    long dna_sequence_length = ftell(dna_file);
    fseek(dna_file, 0, SEEK_SET);

    if (dna_sequence_length > MAX_DNA_SEQUENCE_LENGTH) {
        fprintf(stderr, "Error: DNA sequence is too long.\n");
        exit(1);
    }

    fread(dna_sequence, 1, dna_sequence_length, dna_file);

    fclose(dna_file);

    int *counts = malloc(sizeof(int) * 26);
    memset(counts, 0, sizeof(int) * 26);

    int i = 0;
    while (dna_sequence[i]!= '\0') {
        if (isalpha(dna_sequence[i])) {
            dna_sequence[i] = toupper(dna_sequence[i]);
            counts[(int) dna_sequence[i] - 65]++;
        }
        i++;
    }

    fprintf(stdout, "DNA sequence: %s\n", dna_sequence);
    fprintf(stdout, "A: %d\n", counts[0]);
    fprintf(stdout, "C: %d\n", counts[1]);
    fprintf(stdout, "G: %d\n", counts[2]);
    fprintf(stdout, "T: %d\n", counts[3]);

    free(counts);

    return 0;
}