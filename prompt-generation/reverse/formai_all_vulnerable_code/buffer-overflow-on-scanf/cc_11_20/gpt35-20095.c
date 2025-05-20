//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/** 
 * This program takes a gene sequence as input and identifies 
 * the most occurring nucleotide along with its frequency. 
**/

int main() {
    char gene_sequence[1000], nucleotide;
    int frequency = 0, nucleotide_count[4] = {0};

    printf("Enter the gene sequence: ");
    scanf("%s", gene_sequence);

    // convert the gene sequence to uppercase
    int n = strlen(gene_sequence);
    for(int i=0; i<n; i++) {
        gene_sequence[i] = toupper(gene_sequence[i]);
    }

    // iterate through the gene sequence and count nucleotides
    for(int i=0; i<n; i++) {
        switch(gene_sequence[i]) {
            case 'A':
                nucleotide_count[0]++;
                break;
            case 'C':
                nucleotide_count[1]++;
                break;
            case 'G':
                nucleotide_count[2]++;
                break;
            case 'T':
                nucleotide_count[3]++;
                break;
        }
    }

    // identify the most occurring nucleotide
    for(int i=0; i<4; i++) {
        if(nucleotide_count[i] > frequency) {
            frequency = nucleotide_count[i];
            switch(i) {
                case 0:
                    nucleotide = 'A';
                    break;
                case 1:
                    nucleotide = 'C';
                    break;
                case 2:
                    nucleotide = 'G';
                    break;
                case 3:
                    nucleotide = 'T';
                    break;
            }
        }
    }

    // print the output
    printf("Most occurring nucleotide: %c\n", nucleotide);
    printf("Frequency: %d\n", frequency);

    return 0;
}