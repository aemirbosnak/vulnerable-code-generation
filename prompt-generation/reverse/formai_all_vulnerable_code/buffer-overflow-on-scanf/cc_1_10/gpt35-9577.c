//FormAI DATASET v1.0 Category: Computer Biology ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program simulates the process of genetic transcription and translation
 * in biology using a user input DNA sequence. It outputs the resulting mRNA
 * sequence and subsequently the amino acid sequence.
 */

// Define a struct to hold the genetic code table
struct codon {
  char *sequence;
  char amino_acid;
};

// Define the genetic code table
struct codon genetic_code[64] = {
    {"TTT", 'F'}, {"TTC", 'F'}, {"TTA", 'L'}, {"TTG", 'L'},
    {"CTT", 'L'}, {"CTC", 'L'}, {"CTA", 'L'}, {"CTG", 'L'},
    {"ATT", 'I'}, {"ATC", 'I'}, {"ATA", 'I'}, {"ATG", 'M'},
    {"GTT", 'V'}, {"GTC", 'V'}, {"GTA", 'V'}, {"GTG", 'V'},
    {"TCT", 'S'}, {"TCC", 'S'}, {"TCA", 'S'}, {"TCG", 'S'},
    {"CCT", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
    {"ACT", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
    {"GCT", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
    {"TAT", 'Y'}, {"TAC", 'Y'}, {"TAA", '*'}, {"TAG", '*'},
    {"CAT", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'},
    {"AAT", 'N'}, {"AAC", 'N'}, {"AAA", 'K'}, {"AAG", 'K'},
    {"GAT", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
    {"TGT", 'C'}, {"TGC", 'C'}, {"TGA", '*'}, {"TGG", 'W'},
    {"CGT", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
    {"AGT", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'},
    {"GGT", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}
};

// Define a function to find the corresponding amino acid from a given codon
char get_amino_acid(char *codon) {
  for (int i = 0; i < 64; i++) {
    if (strcmp(codon, genetic_code[i].sequence) == 0) {
      return genetic_code[i].amino_acid;
    }
  }
  // If the codon is not in the genetic code table, return an error
  return '\0';
}

int main() {
  char dna_sequence[1000];
  char mrna_sequence[1000];
  char amino_acid_sequence[1000];

  // Get user input for the DNA sequence
  printf("Please enter a DNA sequence (A, T, C, G only): ");
  scanf("%s", dna_sequence);

  // Transcribe the DNA sequence into mRNA
  for (int i = 0; i < strlen(dna_sequence); i++) {
    if (dna_sequence[i] == 'A') {
      mrna_sequence[i] = 'U';
    } else if (dna_sequence[i] == 'T') {
      mrna_sequence[i] = 'A';
    } else if (dna_sequence[i] == 'C') {
      mrna_sequence[i] = 'G';
    } else if (dna_sequence[i] == 'G') {
      mrna_sequence[i] = 'C';
    }
  }
  mrna_sequence[strlen(dna_sequence)] = '\0';
  printf("mRNA sequence: %s\n", mrna_sequence);

  // Translate the mRNA sequence into an amino acid sequence
  for (int i = 0; i < strlen(mrna_sequence); i += 3) {
    char codon[4];
    strncpy(codon, &mrna_sequence[i], 3);
    codon[3] = '\0';
    char amino_acid = get_amino_acid(codon);
    amino_acid_sequence[i / 3] = amino_acid;
  }
  amino_acid_sequence[strlen(mrna_sequence) / 3] = '\0';
  printf("Amino acid sequence: %s\n", amino_acid_sequence);

  return 0;
}