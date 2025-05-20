//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define BASES 4
#define LENGTH 100000
#define BUFFER_SIZE 512

typedef struct {
    unsigned char base;
    int count;
} base_count;

void read_fasta(FILE *fp, char *seq, base_count *bases) {
    char line[BUFFER_SIZE];
    char name[BUFFER_SIZE];
    int base_index;

    fgets(line, BUFFER_SIZE, fp);
    sscanf(line, ">%s", name);

    memset(bases, 0, sizeof(base_count) * BASES);

    for (int i = 0; i < LENGTH; i++) {
        seq[i] = tolower(fgetc(fp));
        switch (seq[i]) {
            case 'a':
                bases[0].count++;
                break;
            case 'c':
                bases[1].count++;
                break;
            case 'g':
                bases[2].count++;
                break;
            case 't':
                bases[3].count++;
                break;
            default:
                break;
        }
    }
}

void print_results(base_count *bases) {
    double proportions[BASES];

    for (int i = 0; i < BASES; i++) {
        proportions[i] = (double) bases[i].count / LENGTH;
        printf("Base %c: %f\n", bases[i].base, proportions[i]);
    }

    double total = 0;
    for (int i = 0; i < BASES; i++) {
        total += proportions[i];
    }

    printf("Total: %f\n", total);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char seq[LENGTH];
    base_count bases[BASES];

    read_fasta(fp, seq, bases);
    print_results(bases);

    fclose(fp);
    return 0;
}