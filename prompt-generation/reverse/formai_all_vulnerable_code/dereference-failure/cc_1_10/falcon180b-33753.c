//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_ALLELES 4
#define MAX_SNP 1000

typedef struct {
    char allele1[MAX_ALLELES];
    char allele2[MAX_ALLELES];
    int position;
    int length;
} SNP;

void generateSNP(SNP *snp) {
    int i;
    for (i = 0; i < snp->length; i++) {
        snp->allele1[i] = rand() % 4 + 'A';
        snp->allele2[i] = rand() % 4 + 'A';
    }
}

int main() {
    srand(time(NULL));
    int sequenceLength = rand() % MAX_SEQUENCE_LENGTH + 1;
    char sequence[MAX_SEQUENCE_LENGTH];
    char *genome = (char *)malloc(sequenceLength * sizeof(char));
    int numSNPs = rand() % MAX_SNP + 1;
    SNP *snps = (SNP *)malloc(numSNPs * sizeof(SNP));

    printf("Sequence Length: %d\n", sequenceLength);
    printf("Number of SNPs: %d\n", numSNPs);

    int i;
    for (i = 0; i < sequenceLength; i++) {
        genome[i] = rand() % 4 + 'A';
    }
    genome[sequenceLength - 1] = '\0';

    printf("Genome:\n%s\n", genome);

    for (i = 0; i < numSNPs; i++) {
        SNP *snp = &snps[i];
        snp->position = rand() % sequenceLength + 1;
        snp->length = rand() % MAX_ALLELES + 1;
        generateSNP(snp);
        printf("SNP %d: Position %d, Length %d, Alleles 1: %s, Alleles 2: %s\n", i + 1, snp->position, snp->length, snp->allele1, snp->allele2);
    }

    free(genome);
    free(snps);

    return 0;
}