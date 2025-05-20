//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

int main() {
  // Create two genome strands
  char strand1[MAX_LENGTH], strand2[MAX_LENGTH];
  int i, j, size, mutation_count = 0;

  // Prompt the user for input strands
  printf("Enter first genome strand: ");
  fgets(strand1, MAX_LENGTH, stdin);
  printf("Enter second genome strand: ");
  fgets(strand2, MAX_LENGTH, stdin);

  // Remove newline characters from the strands
  size = strlen(strand1);
  if (strand1[size - 1] == '\n') {
    strand1[size - 1] = '\0';
  }
  size = strlen(strand2);
  if (strand2[size - 1] == '\n') {
    strand2[size - 1] = '\0';
  }

  // Check if the strands are of the same length
  if (strlen(strand1) != strlen(strand2)) {
    printf("Error: Strands are of different lengths.\n");
    return(1);
  }

  // Print out the strands
  printf("Strand 1: %s\n", strand1);
  printf("Strand 2: %s\n", strand2);

  // Compare the strands and count the mutations
  for (i = 0; i < strlen(strand1); i++) {
    if (strand1[i] != strand2[i]) {
      mutation_count++;
    }
  }

  // Print out the number of mutations
  printf("Number of mutations: %d\n", mutation_count);

  // Print out whether the strands are a match or not
  if (mutation_count == 0) {
    printf("The two genome strands match perfectly!\n");
  } else if (mutation_count <= 10) {
    printf("The two genome strands are a slight match.\n");
  } else if (mutation_count <= 30) {
    printf("The two genome strands are a moderate match.\n");
  } else if (mutation_count <= 50) {
    printf("The two genome strands are a strong match.\n");
  } else {
    printf("The two genome strands are not a match.\n");
  }

  return(0);
}