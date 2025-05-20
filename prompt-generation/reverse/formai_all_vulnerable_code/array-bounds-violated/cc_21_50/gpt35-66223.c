//FormAI DATASET v1.0 Category: Computer Biology ; Style: relaxed
#include <stdio.h>

int main() {
  // Define the DNA sequence
  char dna[] = "ACTGACCGTATCAGCA";

  // Display the DNA sequence
  printf("Original DNA Sequence: %s\n", dna);

  // Convert the DNA sequence to RNA
  for (int i = 0; i < sizeof(dna); i++) {
    if (dna[i] == 'T') {
      dna[i] = 'U';
    }
  }

  // Display the RNA sequence
  printf("Converted RNA Sequence: %s\n", dna);

  // Determine the amino acid sequence
  char codon[3];
  char amino_acid;
  int counter = 0;
  printf("Amino Acid Sequence:\n");
  for (int i = 0; i < sizeof(dna); i += 3) {
    codon[0] = dna[i];
    codon[1] = dna[i + 1];
    codon[2] = dna[i + 2];

    if (codon[0] == 'A' && codon[1] == 'U' && codon[2] == 'G') {
      amino_acid = 'M';
    } else if ((codon[0] == 'G' && codon[1] == 'C') ||
               (codon[0] == 'G' && codon[1] == 'U' && codon[2] == 'A') ||
               (codon[0] == 'G' && codon[1] == 'U' && codon[2] == 'G')) {
      amino_acid = 'A';
    } else if ((codon[0] == 'A' && codon[1] == 'A') ||
               (codon[0] == 'A' && codon[1] == 'G' && codon[2] == 'A') ||
               (codon[0] == 'A' && codon[1] == 'G' && codon[2] == 'G')) {
      amino_acid = 'K';
    } else if ((codon[0] == 'U' && codon[1] == 'C') ||
               (codon[0] == 'U' && codon[1] == 'U' && codon[2] == 'A') ||
               (codon[0] == 'U' && codon[1] == 'U' && codon[2] == 'G') ||
               (codon[0] == 'U' && codon[1] == 'C' && codon[2] == 'A') ||
               (codon[0] == 'U' && codon[1] == 'C' && codon[2] == 'G')) {
      amino_acid = 'S';
    } else if ((codon[0] == 'U' && codon[1] == 'A') ||
               (codon[0] == 'U' && codon[1] == 'G' && codon[2] == 'A') ||
               (codon[0] == 'U' && codon[1] == 'G' && codon[2] == 'G')) {
      amino_acid = ' ';
    } else {
      amino_acid = 'X';
    }

    printf("%c", amino_acid);
    counter++;

    if (counter == 3) {
      printf(" ");
      counter = 0;
    }
  }

  return 0;
}