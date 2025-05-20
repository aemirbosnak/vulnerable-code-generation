//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SEQ_LEN 1000

// Nucleotide frequencies
#define A_FREQ 0.25
#define C_FREQ 0.25
#define G_FREQ 0.25
#define T_FREQ 0.25

// Error rates
#define INSERTION_RATE 0.001
#define DELETION_RATE 0.001
#define SUBSTITUTION_RATE 0.001

// Random number generator
#define RAND_MAX 2147483647

// Function to generate a random nucleotide
char random_nucleotide() {
  double r = (double) rand() / RAND_MAX;
  if (r < A_FREQ) {
    return 'A';
  } else if (r < A_FREQ + C_FREQ) {
    return 'C';
  } else if (r < A_FREQ + C_FREQ + G_FREQ) {
    return 'G';
  } else {
    return 'T';
  }
}

// Function to generate a random sequence of nucleotides
char *random_sequence(int length) {
  char *seq = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    seq[i] = random_nucleotide();
  }
  seq[length] = '\0';
  return seq;
}

// Function to introduce sequencing errors into a sequence
char *introduce_errors(char *seq) {
  int length = strlen(seq);
  char *err_seq = malloc(length + 1);
  strcpy(err_seq, seq);

  // Introduce insertions
  for (int i = 0; i < length; i++) {
    double r = (double) rand() / RAND_MAX;
    if (r < INSERTION_RATE) {
      err_seq = realloc(err_seq, length + 2);
      for (int j = length; j > i; j--) {
        err_seq[j + 1] = err_seq[j];
      }
      err_seq[i] = random_nucleotide();
      length++;
    }
  }

  // Introduce deletions
  for (int i = 0; i < length; i++) {
    double r = (double) rand() / RAND_MAX;
    if (r < DELETION_RATE) {
      for (int j = i + 1; j < length; j++) {
        err_seq[j - 1] = err_seq[j];
      }
      length--;
    }
  }

  // Introduce substitutions
  for (int i = 0; i < length; i++) {
    double r = (double) rand() / RAND_MAX;
    if (r < SUBSTITUTION_RATE) {
      err_seq[i] = random_nucleotide();
    }
  }

  err_seq[length] = '\0';
  return err_seq;
}

// Main function
int main() {
  // Get the length of the sequence to be generated
  int length;
  printf("Enter the length of the sequence to be generated: ");
  scanf("%d", &length);

  // Generate a random sequence of nucleotides
  char *seq = random_sequence(length);

  // Introduce sequencing errors into the sequence
  char *err_seq = introduce_errors(seq);

  // Print the original sequence and the sequence with sequencing errors
  printf("Original sequence: %s\n", seq);
  printf("Sequence with sequencing errors: %s\n", err_seq);

  // Free the allocated memory
  free(seq);
  free(err_seq);

  return 0;
}