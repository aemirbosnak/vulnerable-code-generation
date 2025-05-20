//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include <stdio.h>

// Function that takes in a DNA sequence as a string and returns the amino acid sequence as a string
char* dna_to_protein(char* dna_sequence) {
    int i;
    char* protein_sequence = (char*) malloc((strlen(dna_sequence) / 3) + 1);
    char codon[4] = {'\0', '\0', '\0', '\0'};
    int protein_index = 0;

    // Loop through the DNA sequence by groups of 3 (codons) and match them to the corresponding amino acid using a switch statement
    for (i = 0; i < strlen(dna_sequence); i += 3) {
        codon[0] = dna_sequence[i];
        codon[1] = dna_sequence[i+1];
        codon[2] = dna_sequence[i+2];

        switch (codon[0]) {
            case 'A':
                switch (codon[1]) {
                    case 'A':
                        switch (codon[2]) {
                            case 'A':
                            case 'G':
                                protein_sequence[protein_index] = 'K';
                                break;
                            default:
                                protein_sequence[protein_index] = 'N';
                        }
                        break;
                    case 'C':
                    case 'T':
                        protein_sequence[protein_index] = 'T';
                        break;
                    case 'G':
                        switch (codon[2]) {
                            case 'A':
                            case 'G':
                                protein_sequence[protein_index] = 'R';
                                break;
                            default:
                                protein_sequence[protein_index] = 'S';
                        }
                        break;
                }
                break;
            case 'C':
                switch (codon[1]) {
                    case 'A':
                        switch (codon[2]) {
                            case 'A':
                            case 'G':
                                protein_sequence[protein_index] = 'Q';
                                break;
                            default:
                                protein_sequence[protein_index] = 'H';
                        }
                        break;
                    case 'C':
                        protein_sequence[protein_index] = 'P';
                        break;
                    case 'G':
                        protein_sequence[protein_index] = 'R';
                        break;
                    case 'T':
                        protein_sequence[protein_index] = 'L';
                        break;
                }
                break;
            case 'G':
                switch (codon[1]) {
                    case 'A':
                        protein_sequence[protein_index] = 'E';
                        break;
                    case 'C':
                        protein_sequence[protein_index] = 'A';
                        break;
                    case 'G':
                        protein_sequence[protein_index] = 'G';
                        break;
                    case 'T':
                        protein_sequence[protein_index] = 'V';
                        break;
                }
                break;
            case 'T':
                switch (codon[1]) {
                    case 'A':
                        switch (codon[2]) {
                            case 'A':
                            case 'G':
                                protein_sequence[protein_index] = 'STOP';
                                break;
                            default:
                                protein_sequence[protein_index] = 'Y';
                        }
                        break;
                    case 'C':
                        protein_sequence[protein_index] = 'S';
                        break;
                    case 'G':
                        switch (codon[2]) {
                            case 'A':
                            case 'G':
                                protein_sequence[protein_index] = 'STOP';
                                break;
                            default:
                                protein_sequence[protein_index] = 'C';
                        }
                        break;
                    case 'T':
                        switch (codon[2]) {
                            case 'A':
                            case 'G':
                                protein_sequence[protein_index] = 'L';
                                break;
                            default:
                                protein_sequence[protein_index] = 'F';
                        }
                        break;
                }
                break;
        }
        protein_index++;
    }

    protein_sequence[protein_index] = '\0';
    return protein_sequence;
}

int main() {
    char* dna_sequence = "AAATGCCGTCTAGATTAACAGGTGTCTTACTTTTGCTCTGTCAGTTGAGGGTTTGAGCGCGCAGTTAG";
    char* protein_sequence = dna_to_protein(dna_sequence);

    printf("DNA Sequence: %s\n", dna_sequence);
    printf("Protein Sequence: %s\n", protein_sequence);

    free(protein_sequence);
    return 0;
}