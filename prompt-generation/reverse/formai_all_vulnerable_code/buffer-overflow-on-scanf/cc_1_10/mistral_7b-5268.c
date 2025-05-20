//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUCLEOTIDES 4
#define SEQ_MAX_LEN 1000

typedef enum {ADENINE, THYMINE, GUANINE, CYTOZINE} Nucleotide;

Nucleotide nucleotides[NUCLEOTIDES] = {ADENINE, THYMINE, GUANINE, CYTOZINE};

void readSequence(char *fileName, char *sequence, int *seqLength) {
    FILE *fp = fopen(fileName, "r");
    int i = 0;

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%c", &sequence[i]) != EOF) {
        if (i == SEQ_MAX_LEN - 1) {
            printf("Error: Sequence too long\n");
            exit(EXIT_FAILURE);
        }

        if (sequence[i] != 'A' && sequence[i] != 'C' && sequence[i] != 'G' && sequence[i] != 'T') {
            printf("Error: Invalid character %c in sequence\n", sequence[i]);
            exit(EXIT_FAILURE);
        }

        i++;
    }

    sequence[i] = '\0';
    *seqLength = i;

    fclose(fp);
}

void printNucleotide(Nucleotide n) {
    switch (n) {
        case ADENINE: printf("A"); break;
        case THYMINE: printf("T"); break;
        case GUANINE: printf("G"); break;
        case CYTOZINE: printf("C"); break;
    }
}

void printSequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        printNucleotide(nucleotides[(int)sequence[i]]);
    }
    printf("\n");
}

int main() {
    char fileName[100];
    char sequence[SEQ_MAX_LEN];
    int seqLength;

    printf("Enter file name: ");
    scanf("%s", fileName);

    readSequence(fileName, sequence, &seqLength);

    printf("Sequenced genome: ");
    printSequence(sequence, seqLength);

    return EXIT_SUCCESS;
}