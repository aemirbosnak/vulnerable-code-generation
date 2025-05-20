//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random base
char generateBase() {
  int r = rand() % 4;
  switch (r) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
    default:
      return 'N';
  }
}

// Function to generate a random sequence of bases
char *generateSequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generateBase();
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to write a sequence to a file
void writeSequenceToFile(char *filename, char *sequence) {
  FILE *fp = fopen(filename, "w");
  fprintf(fp, "%s", sequence);
  fclose(fp);
}

// Main function
int main() {
  // Get the length of the sequence from the user
  int length;
  printf("Enter the length of the sequence you want to generate: ");
  scanf("%d", &length);

  // Generate a random sequence of bases
  char *sequence = generateSequence(length);

  // Write the sequence to a file
  writeSequenceToFile("sequence.txt", sequence);

  // Print the sequence to the console
  printf("The generated sequence is: %s\n", sequence);

  // Free the allocated memory
  free(sequence);

  return 0;
}