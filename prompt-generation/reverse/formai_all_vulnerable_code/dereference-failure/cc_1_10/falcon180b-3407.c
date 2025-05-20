//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_BASES 4
#define NUM_AMINO_ACIDS 20

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *read_sequence_from_file(FILE *fp) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    seq->length = 0;

    int c;
    while ((c = fgetc(fp))!= EOF) {
        if (isalpha(c)) {
            seq->sequence[seq->length++] = tolower(c);
        }
    }

    seq->sequence[seq->length] = '\0';
    return seq;
}

void print_sequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }
    printf("\n");
}

void translate_sequence(Sequence *seq) {
    int codon_start = 0;
    int codon_end = 0;
    int aa_index = 0;

    while (codon_end < seq->length) {
        int codon = 0;

        for (int i = codon_start; i < codon_end; i++) {
            codon = codon * NUM_BASES + (int)seq->sequence[i] - (int)'a';
        }

        int aa = codon % NUM_AMINO_ACIDS;
        printf("%c", aa);

        codon_start++;
        codon_end += 3;
        aa_index++;
    }
}

int main() {
    FILE *fp = fopen("sequence.txt", "r");
    Sequence *seq = read_sequence_from_file(fp);
    fclose(fp);

    printf("Sequence:\n");
    print_sequence(seq);

    printf("Translation:\n");
    translate_sequence(seq);

    return 0;
}