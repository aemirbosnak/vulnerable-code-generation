//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4 // Number of nucleotides (A, C, G, T)
#define SEQ_LEN 100 // Maximum length of input sequence

// Define the transition probability matrix
double prob_matrix[N][N] = {
  { 0.3, 0.2, 0.4, 0.1 }, // Probability of A transitioning to each nucleotide
  { 0.1, 0.5, 0.3, 0.1 }, // Probability of C transitioning to each nucleotide
  { 0.4, 0.1, 0.4, 0.1 }, // Probability of G transitioning to each nucleotide
  { 0.2, 0.1, 0.3, 0.4 }  // Probability of T transitioning to each nucleotide
};

int main() {
  char dna_seq[SEQ_LEN];
  char next_base;

  printf("Enter your DNA sequence (up to %d bases): ", SEQ_LEN);
  scanf("%s", dna_seq);

  // Convert the input sequence to uppercase
  for (int i = 0; dna_seq[i] != '\0'; i++) {
    dna_seq[i] = toupper(dna_seq[i]);
  }

  // Initialize the transition probabilities based on the input sequence
  double trans_prob[N];
  for (int i = 0; i < N; i++) {
    trans_prob[i] = 0.0;
  }

  int seq_len = strlen(dna_seq);
  if (seq_len < 1) {
    printf("Error: Sequence must contain at least one base pair.\n");
    return 1;
  }

  trans_prob[dna_seq[0] - 'A'] = 1.0; // Set the initial probability

  // Calculate the next base pair based on the Markov model
  next_base = 'A';
  for (int i = 0; i < N; i++) {
    next_base = prob_matrix[dna_seq[0] - 'A'][i] > trans_prob[i] ? (char)(i + 'A') : next_base;
  }

  printf("Next base pair in the sequence: %c\n", next_base);
  return 0;
}