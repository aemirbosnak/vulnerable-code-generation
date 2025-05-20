//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define GENELEN 50
#define ALPHABET_SIZE 4
#define BASES "ACGT"

typedef struct {
    char base;
    int count;
} base_t;

void seq_gen(char *seq, int len) {
    char curr_base;
    int rand_num;

    for (int i = 0; i < len; i++) {
        curr_base = seq[i];
        rand_num = rand() % ALPHABET_SIZE;
        seq[i] = BASES[rand_num];
    }
}

void print_seq(char *seq) {
    int len = strlen(seq);

    for (int i = 0; i < len; i++) {
        printf("%c", seq[i]);
    }
}

void count_bases(char *seq, base_t *bases) {
    for (int i = 0; i < strlen(seq); i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (seq[i] == BASES[j]) {
                bases[j].count++;
                break;
            }
        }
    }
}

int main() {
    char seq[GENELEN];
    base_t bases[ALPHABET_SIZE];
    int len = GENELEN;

    // Generate random sequence
    seq_gen(seq, len);

    // Print sequence
    printf("Sequence: ");
    print_seq(seq);
    printf("\n");

    // Count bases
    count_bases(seq, bases);

    // Print base counts
    printf("Base counts:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", BASES[i], bases[i].count);
    }

    return 0;
}