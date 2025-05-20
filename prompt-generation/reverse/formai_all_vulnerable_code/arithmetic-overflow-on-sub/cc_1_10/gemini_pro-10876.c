//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
// Embark on a visionary odyssey through the labyrinthine enigma of C's genome!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our genetic repository, a tapestry of nucleotide sequences
char *genome;
int genomeLen;

// A random nucleotide generator, a harbinger of genetic diversity
char randNucleotide() {
  static char nucleotides[] = {'A', 'C', 'G', 'T'};
  return nucleotides[rand() % 4];
}

// Simulate the revolutionary process of genome sequencing, unraveling the secrets of life's blueprint
void sequenceGenome() {
  genome = malloc(genomeLen);  // Allocating a haven for our genetic blueprints
  for (int i = 0; i < genomeLen; i++) {
    genome[i] = randNucleotide();  // Injecting randomness, the essence of genetic variability
  }
}

// Unveiling the hidden patterns within our simulated genome, a testament to computational biology's prowess
void analyzeGenome() {
  int nucleotideCounts[4] = {0};  // Tallying the prevalence of each nucleotide, a beacon of statistical insight
  for (int i = 0; i < genomeLen; i++) {
    switch (genome[i]) {
      case 'A': nucleotideCounts[0]++; break;
      case 'C': nucleotideCounts[1]++; break;
      case 'G': nucleotideCounts[2]++; break;
      case 'T': nucleotideCounts[3]++; break;
      default: printf("Anomalous nucleotide encountered: %c\n", genome[i]);
    }
  }

  // Presenting the genetic profile, a tapestry of nucleotide frequencies
  printf("Nucleotide Composition:\n");
  printf("A: %d (%.2f%%)\n", nucleotideCounts[0], (double)nucleotideCounts[0] / genomeLen * 100);
  printf("C: %d (%.2f%%)\n", nucleotideCounts[1], (double)nucleotideCounts[1] / genomeLen * 100);
  printf("G: %d (%.2f%%)\n", nucleotideCounts[2], (double)nucleotideCounts[2] / genomeLen * 100);
  printf("T: %d (%.2f%%)\n\n", nucleotideCounts[3], (double)nucleotideCounts[3] / genomeLen * 100);

  // Searching for hidden patterns, the cornerstone of genetic exploration
  char currMotif[5] = {0};  // A window into the genome, seeking recurring sequences
  int motifCount = 0;  // A beacon of motif prevalence
  for (int i = 0; i < genomeLen - 4; i++) {
    strncpy(currMotif, genome + i, 4);
    int foundMotif = 0;
    for (int j = i + 1; j < genomeLen - 4; j++) {
      if (!strcmp(currMotif, genome + j)) {
        foundMotif = 1;
        motifCount++;
        break;
      }
    }
    if (foundMotif) printf("Motif found: %s\n", currMotif);
  }

  if (!motifCount) printf("No motifs found.\n\n");
}

// A testament to the power of simulation, a glimpse into the enigmatic realm of genomics
int main() {
  printf("Enter the length of the genome to be sequenced: ");
  scanf("%d", &genomeLen);

  sequenceGenome();
  printf("Genome sequenced successfully.\n\n");

  analyzeGenome();

  free(genome);
  return 0;
}