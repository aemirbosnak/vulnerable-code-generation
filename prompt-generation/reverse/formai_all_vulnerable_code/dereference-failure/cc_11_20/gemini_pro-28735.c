//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 8-bit DNA bases
#define A 0x01
#define C 0x02
#define G 0x04
#define T 0x08

// 16-bit DNA codons
#define AAA 0x0101
#define AAC 0x0102
#define AAG 0x0104
#define AAT 0x0108
#define ACA 0x0201
#define ACC 0x0202
#define ACG 0x0204
#define ACT 0x0208
#define AGA 0x0401
#define AGC 0x0402
#define AGG 0x0404
#define AGT 0x0408
#define ATA 0x0801
#define ATC 0x0802
#define ATG 0x0804
#define ATT 0x0808
#define CAA 0x1001
#define CAC 0x1002
#define CAG 0x1004
#define CAT 0x1008
#define CCA 0x2001
#define CCC 0x2002
#define CCG 0x2004
#define CCT 0x2008
#define CGA 0x4001
#define CGC 0x4002
#define CGG 0x4004
#define CGT 0x4008
#define CTA 0x8001
#define CTC 0x8002
#define CTG 0x8004
#define CTT 0x8008
#define GAA 0x1010
#define GAC 0x1020
#define GAG 0x1040
#define GAT 0x1080
#define GCA 0x2010
#define GCC 0x2020
#define GCG 0x2040
#define GCT 0x2080
#define GGA 0x4010
#define GGC 0x4020
#define GGG 0x4040
#define GGT 0x4080
#define GTA 0x8010
#define GTC 0x8020
#define GTG 0x8040
#define GTT 0x8080
#define TAA 0x1100
#define TAC 0x1200
#define TAG 0x1400
#define TAT 0x1800
#define TCA 0x2100
#define TCC 0x2200
#define TCG 0x2400
#define TCT 0x2800
#define TGA 0x4100
#define TGC 0x4200
#define TGG 0x4400
#define TGT 0x4800
#define TTA 0x8100
#define TTC 0x8200
#define TTG 0x8400
#define TTT 0x8800

// Generate a random DNA sequence of length n
unsigned char *generate_dna(int n) {
  unsigned char *dna = malloc(n);
  for (int i = 0; i < n; i++) {
    dna[i] = rand() & 0x0f;
  }
  return dna;
}

// Print a DNA sequence
void print_dna(unsigned char *dna, int n) {
  for (int i = 0; i < n; i++) {
    switch (dna[i]) {
      case A:
        printf("A");
        break;
      case C:
        printf("C");
        break;
      case G:
        printf("G");
        break;
      case T:
        printf("T");
        break;
    }
  }
  printf("\n");
}

// Convert a DNA sequence to a protein sequence
unsigned char *dna_to_protein(unsigned char *dna, int n) {
  unsigned char *protein = malloc(n / 3);
  for (int i = 0; i < n; i += 3) {
    unsigned short codon = (dna[i] << 8) | (dna[i + 1] << 4) | dna[i + 2];
    switch (codon) {
      case AAA:
      case AAC:
      case AAG:
      case AAT:
        protein[i / 3] = 'K';
        break;
      case ACA:
      case ACC:
      case ACG:
      case ACT:
        protein[i / 3] = 'T';
        break;
      case AGA:
      case AGC:
      case AGG:
      case AGT:
        protein[i / 3] = 'R';
        break;
      case ATA:
      case ATC:
      case ATG:
      case ATT:
        protein[i / 3] = 'I';
        break;
      case CAA:
      case CAC:
      case CAG:
      case CAT:
        protein[i / 3] = 'Q';
        break;
      case CCA:
      case CCC:
      case CCG:
      case CCT:
        protein[i / 3] = 'P';
        break;
      case CGA:
      case CGC:
      case CGG:
      case CGT:
        protein[i / 3] = 'R';
        break;
      case CTA:
      case CTC:
      case CTG:
      case CTT:
        protein[i / 3] = 'L';
        break;
      case GAA:
      case GAC:
      case GAG:
      case GAT:
        protein[i / 3] = 'E';
        break;
      case GCA:
      case GCC:
      case GCG:
      case GCT:
        protein[i / 3] = 'A';
        break;
      case GGA:
      case GGC:
      case GGG:
      case GGT:
        protein[i / 3] = 'G';
        break;
      case GTA:
      case GTC:
      case GTG:
      case GTT:
        protein[i / 3] = 'V';
        break;
      case TAA:
      case TAG:
      case TAT:
        protein[i / 3] = '*';
        break;
      case TCA:
      case TCC:
      case TCG:
      case TCT:
        protein[i / 3] = 'S';
        break;
      case TGA:
        protein[i / 3] = '*';
        break;
      case TGC:
      case TGG:
        protein[i / 3] = 'W';
        break;
      case TGT:
      case TTA:
      case TTC:
      case TTG:
      case TTT:
        protein[i / 3] = 'L';
        break;
    }
  }
  return protein;
}

// Print a protein sequence
void print_protein(unsigned char *protein, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c", protein[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  unsigned char *dna = generate_dna(100);

  // Print the DNA sequence
  printf("DNA sequence:\n");
  print_dna(dna, 100);

  // Convert the DNA sequence to a protein sequence
  unsigned char *protein = dna_to_protein(dna, 100);

  // Print the protein sequence
  printf("Protein sequence:\n");
  print_protein(protein, 100);

  // Free the allocated memory
  free(dna);
  free(protein);

  return 0;
}