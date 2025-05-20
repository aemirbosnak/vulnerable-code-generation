//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000 // maximum length of sequence to simulate
#define SEQUENCE_FILE_NAME "sequence.txt" // name of output sequence file
#define BASE_COUNT_FILE_NAME "base_count.txt" // name of output base count file

int main(int argc, char *argv[]) {
    int sequence_length;
    int base_counts[4] = {0}; // initialize base counts to 0
    char sequence[MAX_SEQUENCE_LENGTH];

    // prompt user for sequence length
    printf("Enter sequence length (1-%d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);

    // generate random sequence of specified length
    srand(time(NULL));
    for (int i = 0; i < sequence_length; i++) {
        int base = rand() % 4; // randomly choose one of four bases
        sequence[i] = "ACGT"[base]; // add chosen base to sequence
        base_counts[base]++; // increase count of chosen base
    }

    // write sequence to output file
    FILE *sequence_file = fopen(SEQUENCE_FILE_NAME, "w");
    if (sequence_file == NULL) {
        printf("Error: could not open sequence file for writing.\n");
        exit(1);
    }
    fprintf(sequence_file, "Sequence: %s\n", sequence);
    fclose(sequence_file);

    // write base counts to output file
    FILE *base_count_file = fopen(BASE_COUNT_FILE_NAME, "w");
    if (base_count_file == NULL) {
        printf("Error: could not open base count file for writing.\n");
        exit(1);
    }
    fprintf(base_count_file, "A: %d\n", base_counts[0]);
    fprintf(base_count_file, "C: %d\n", base_counts[1]);
    fprintf(base_count_file, "G: %d\n", base_counts[2]);
    fprintf(base_count_file, "T: %d\n", base_counts[3]);
    fclose(base_count_file);

    // print success message
    printf("Sequence and base count files generated successfully.\n");

    return 0;
}