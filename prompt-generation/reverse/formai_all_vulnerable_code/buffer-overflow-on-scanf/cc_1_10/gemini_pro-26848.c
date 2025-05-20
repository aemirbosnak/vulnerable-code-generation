//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_GENOME_LENGTH 1000000

// Define the probability of each nucleotide base
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Generate a random nucleotide base
char generate_nucleotide() {
  double r = (double)rand() / RAND_MAX;

  if (r < PROB_A) {
    return A;
  } else if (r < PROB_A + PROB_C) {
    return C;
  } else if (r < PROB_A + PROB_C + PROB_G) {
    return G;
  } else {
    return T;
  }
}

// Generate a random genome sequence
char *generate_genome(int length) {
  char *genome = malloc(length + 1);

  for (int i = 0; i < length; i++) {
    genome[i] = generate_nucleotide();
  }

  genome[length] = '\0';

  return genome;
}

// Print the genome sequence to a file
void print_genome(char *genome, char *filename) {
  FILE *fp = fopen(filename, "w");

  fprintf(fp, "%s", genome);

  fclose(fp);
}

// Main function
int main() {
  // Get the length of the genome from the user
  int length;

  printf("Enter the length of the genome: ");
  scanf("%d", &length);

  // Generate the genome sequence
  char *genome = generate_genome(length);

  // Print the genome sequence to a file
  print_genome(genome, "genome.txt");

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}