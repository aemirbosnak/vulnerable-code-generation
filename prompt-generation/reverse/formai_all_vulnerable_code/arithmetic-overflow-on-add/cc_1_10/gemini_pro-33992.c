//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_LENGTH 1000

// Declare the function to generate a random nucleotide
char generate_nucleotide() {
  // Get a random number between 0 and 3
  int n = rand() % 4;

  // Return the corresponding nucleotide
  switch (n) {
    case 0:
      return A;
    case 1:
      return C;
    case 2:
      return G;
    case 3:
      return T;
  }
}

// Declare the function to generate a random genome
char *generate_genome(int length) {
  // Allocate memory for the genome
  char *genome = malloc(length + 1);

  // Generate each nucleotide in the genome
  for (int i = 0; i < length; i++) {
    genome[i] = generate_nucleotide();
  }

  // Terminate the string with a null character
  genome[length] = '\0';

  // Return the genome
  return genome;
}

// Declare the main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the length of the genome from the user
  printf("Enter the length of the genome: ");
  int length;
  scanf("%d", &length);

  // Generate the genome
  char *genome = generate_genome(length);

  // Print the genome to the console
  printf("The genome is: %s\n", genome);

  // Free the memory allocated for the genome
  free(genome);

  // Return 0 to indicate success
  return 0;
}