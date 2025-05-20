//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100000
#define L 50

typedef struct {
    char base;
    int count;
} BaseCount;

void seq_read(char *seq, int *len) {
    char c;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            seq[i++] = c;
            if (i == *len) {
                *len += L;
                seq = realloc(seq, *len * sizeof(char));
            }
        }
    }
    seq[i] = '\0';
    *len = i;
}

void base_count(char *seq, BaseCount bases[4]) {
    int i, len = strlen(seq);

    for (i = 0; i < len; i++) {
        switch (seq[i]) {
            case 'A':
                bases[0].count++;
                break;
            case 'C':
                bases[1].count++;
                break;
            case 'G':
                bases[2].count++;
                break;
            case 'T':
                bases[3].count++;
                break;
        }
    }
}

void print_result(BaseCount bases[4]) {
    printf("\nBase counts:\n");
    int i;

    for (i = 0; i < 4; i++) {
        printf("Base %c: %d\n", i + 'A', bases[i].count);
    }
}

int main() {
    srand(time(NULL));
    char seq[N];
    int len = 0;
    BaseCount bases[4];

    seq_read(seq, &len);
    base_count(seq, bases);
    print_result(bases);

    free(seq);
    return 0;
}