//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_NUMBER_OF_SEQUENCES 1000

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH+1];
    char name[100];
    int length;
    int index;
} Sequence;

int main(int argc, char *argv[]) {
    int num_sequences;
    Sequence *sequences;
    int i, j, k, n, m;
    char *fasta_file;
    char *output_file;
    FILE *fp;

    if (argc!= 3) {
        printf("Usage: %s <fasta_file> <output_file>\n", argv[0]);
        exit(1);
    }

    fasta_file = argv[1];
    output_file = argv[2];

    fp = fopen(fasta_file, "r");
    if (fp == NULL) {
        printf("Error: could not open input file %s\n", fasta_file);
        exit(1);
    }

    n = 0;
    while (fgets(sequences[n].name, sizeof(sequences[n].name), fp)!= NULL) {
        m = 0;
        while (fgets(sequences[n].sequence, sizeof(sequences[n].sequence), fp)!= NULL) {
            sequences[n].sequence[strcspn(sequences[n].sequence, "\n")] = '\0';
            sequences[n].length = strlen(sequences[n].sequence);
            m++;
        }
        sequences[n].index = n;
        n++;
    }
    fclose(fp);

    num_sequences = n;

    srand(time(NULL));
    for (i = 0; i < num_sequences; i++) {
        j = rand() % num_sequences;
        Sequence temp;
        memcpy(&temp, &sequences[j], sizeof(Sequence));
        memcpy(&sequences[j], &sequences[i], sizeof(Sequence));
        memcpy(&sequences[i], &temp, sizeof(Sequence));
    }

    fp = fopen(output_file, "w");
    if (fp == NULL) {
        printf("Error: could not open output file %s\n", output_file);
        exit(1);
    }

    for (i = 0; i < num_sequences; i++) {
        fprintf(fp, ">%s\n%s\n", sequences[i].name, sequences[i].sequence);
    }

    fclose(fp);
    return 0;
}