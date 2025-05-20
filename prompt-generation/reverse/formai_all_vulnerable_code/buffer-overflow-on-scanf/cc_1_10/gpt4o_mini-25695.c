//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

void generateRandomDNA(char *sequence, int length) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4];
    }
    sequence[length] = '\0';  // Null-terminate the string
}

void printSequence(const char *title, const char *sequence) {
    printf("%s: %s\n", title, sequence);
}

void reverseComplement(const char *dna, char *rc) {
    int length = strlen(dna);
    for (int i = 0; i < length; i++) {
        switch (dna[length - 1 - i]) {
            case 'A': rc[i] = 'T'; break;
            case 'T': rc[i] = 'A'; break;
            case 'C': rc[i] = 'G'; break;
            case 'G': rc[i] = 'C'; break;
            default: rc[i] = 'N'; break;  // Unknown nucleotide
        }
    }
    rc[length] = '\0';  // Null-terminate the string
}

void transcribeDNAtoRNA(const char *dna, char *rna) {
    int length = strlen(dna);
    for (int i = 0; i < length; i++) {
        rna[i] = (dna[i] == 'T') ? 'U' : dna[i];
    }
    rna[length] = '\0';  // Null-terminate the string
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    char dna[MAX_LENGTH];
    char rc[MAX_LENGTH];
    char rna[MAX_LENGTH];
    
    int length;
    printf("Enter the length of the DNA sequence (max %d): ", MAX_LENGTH-1);
    scanf("%d", &length);

    if (length <= 0 || length >= MAX_LENGTH) {
        printf("Invalid length! Must be between 1 and %d.\n", MAX_LENGTH-1);
        return 1;
    }

    generateRandomDNA(dna, length);
    printSequence("Generated DNA", dna);
    
    reverseComplement(dna, rc);
    printSequence("Reverse Complement", rc);
    
    transcribeDNAtoRNA(dna, rna);
    printSequence("Transcribed RNA", rna);

    printf("Thank you for using the Genome Sequencing Simulator!\n");
    
    return 0;
}