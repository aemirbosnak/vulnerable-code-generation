//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_NUCLEOTIDES 4
#define NUM_AMINO_ACIDS 20

typedef struct {
    char name[50];
    int length;
    char sequence[MAX_SEQUENCE_LENGTH];
} Sequence;

typedef struct {
    char name[50];
    int length;
    char sequence[MAX_SEQUENCE_LENGTH];
} AminoAcidSequence;

void generateRandomSequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        int randIndex = rand() % NUM_NUCLEOTIDES;
        seq->sequence[i] = "ACGT"[randIndex];
    }
}

void generateRandomAminoAcidSequence(AminoAcidSequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        int randIndex = rand() % NUM_AMINO_ACIDS;
        seq->sequence[i] = "ARNDCQEGHILKMFPSTWYV"[randIndex];
    }
}

int main() {
    srand(time(NULL));

    Sequence dnaSequence;
    AminoAcidSequence proteinSequence;

    printf("Enter the name of the DNA sequence: ");
    scanf("%s", dnaSequence.name);
    printf("Enter the length of the DNA sequence: ");
    scanf("%d", &dnaSequence.length);

    generateRandomSequence(&dnaSequence);

    printf("\n%s DNA sequence:\n%s\n", dnaSequence.name, dnaSequence.sequence);

    printf("\nEnter the name of the protein sequence: ");
    scanf("%s", proteinSequence.name);
    printf("Enter the length of the protein sequence: ");
    scanf("%d", &proteinSequence.length);

    generateRandomAminoAcidSequence(&proteinSequence);

    printf("\n%s protein sequence:\n%s\n", proteinSequence.name, proteinSequence.sequence);

    return 0;
}