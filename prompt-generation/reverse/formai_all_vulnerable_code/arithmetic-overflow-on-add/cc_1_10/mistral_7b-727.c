//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define N 100000
#define L 100

typedef struct {
    char base;
    int count;
} DNA_BASE;

void read_file(char *filename, DNA_BASE *dna_seq) {
    FILE *fp;
    char line[L], ch;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < L; j++) {
            ch = fgetc(fp);
            if (feof(fp)) break;
            if (isalpha(ch)) {
                ch = tolower(ch);
                if (ch == 'a') dna_seq[i].base = 'A';
                else if (ch == 'c') dna_seq[i].base = 'C';
                else if (ch == 'g') dna_seq[i].base = 'G';
                else if (ch == 't' || ch == 'u') dna_seq[i].base = 'T';
                dna_seq[i].count++;
            } else if (ch == '\n') break;
            else {
                printf("Error: Invalid character %c found in file %s at position %d\n", ch, filename, i * L + j);
                exit(1);
            }
        }
    }

    fclose(fp);
}

void print_dna_seq(DNA_BASE *dna_seq) {
    int i;

    for (i = 0; i < N; i++) {
        printf("%3d %c%c %d\n", i + 1, dna_seq[i].base, dna_seq[i].count > 1 ? 'x' : ' ', dna_seq[i].count);
    }
}

int main(int argc, char *argv[]) {
    DNA_BASE dna_seq[N];
    char filename[100];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);
    read_file(filename, dna_seq);
    print_dna_seq(dna_seq);

    return 0;
}