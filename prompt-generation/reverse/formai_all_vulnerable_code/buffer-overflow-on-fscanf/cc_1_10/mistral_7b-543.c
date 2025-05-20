//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100000
#define LEN 50

typedef struct {
    char base;
    int count;
} base_count;

void read_file(char *filename, char seq[N][LEN]);
void count_bases(char seq[N][LEN], base_count bases[]);
void print_bases(base_count bases[4]);

int main(int argc, char *argv[]) {
    char filename[100];
    char seq[N][LEN];
    base_count bases[4] = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    if (argc < 2) {
        printf("Usage: %s <genome_file>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    read_file(filename, seq);
    count_bases(seq, bases);
    print_bases(bases);

    return 0;
}

void read_file(char *filename, char seq[N][LEN]) {
    FILE *fp;
    int i = 0, j = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", seq[i]) != EOF) {
        if (i < N && strlen(seq[i]) <= LEN) {
            strcpy(seq[i + 1], seq[i + 1]);
            strncat(seq[i], seq[i + 1], LEN - strlen(seq[i]) - 1);
            free(seq[i + 1]);
            i++;
        } else {
            printf("Error: Sequence too long or invalid format\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(fp);
}

void count_bases(char seq[N][LEN], base_count bases[]) {
    int i;

    for (i = 0; i < N; i++) {
        bases[tolower(seq[i][0]) - 'a'].count++;
    }
}

void print_bases(base_count bases[]) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%c: %d\n", bases[i].base, bases[i].count);
    }
}