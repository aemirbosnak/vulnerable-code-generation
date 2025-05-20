//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide characters
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Recursive function to generate a random DNA sequence
char *generate_dna(int length) {
  // Base case: stop when the desired length is reached
  if (length == 0) {
    return "";
  }

  // Recursive case: generate a random nucleotide and append it to the sequence
  char *sequence = generate_dna(length - 1);
  int random_index = rand() % 4;
  char random_nucleotide = nucleotides[random_index];
  char *new_sequence = malloc(strlen(sequence) + 2);
  strcpy(new_sequence, sequence);
  new_sequence[strlen(sequence)] = random_nucleotide;
  new_sequence[strlen(sequence) + 1] = '\0';

  // Free the memory allocated for the previous sequence
  free(sequence);

  // Return the new sequence
  return new_sequence;
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // User input
  int sequence_length;
  printf("Enter the desired length of the DNA sequence: ");
  scanf("%d", &sequence_length);

  // Generate the DNA sequence
  char *sequence = generate_dna(sequence_length);

  // Print the DNA sequence
  printf("DNA sequence: %s\n", sequence);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}