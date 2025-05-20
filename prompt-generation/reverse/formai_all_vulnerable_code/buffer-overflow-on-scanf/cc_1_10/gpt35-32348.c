//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Declare variables
  char symbol[3], correct[3];
  int atomicNum, numCorrect = 0, numWrong = 0;

  // Open the file containing periodic table data
  FILE *fptr;
  fptr = fopen("periodictable.dat", "rb");

  // Check if file was successfully opened
  if (fptr == NULL)
  {
    printf("Error opening file");
    exit(0);
  }

  printf("\nWelcome to the Periodic Table Quiz!\n");
  printf("-----------------------------------\n");

  // Loop through the file and display each element
  while (fread(&symbol, sizeof(symbol), 1, fptr))
  {
    fread(&atomicNum, sizeof(atomicNum), 1, fptr);

    // Ask the user to enter the correct atomic number
    printf("What is the atomic number of %s? ", symbol);
    scanf("%d", &correct);

    // Compare user's answer with correct answer
    if (correct == atomicNum)
    {
      printf("Correct!\n");
      numCorrect++;
    }
    else
    {
      printf("Incorrect. The correct answer is %d.\n", atomicNum);
      numWrong++;
    }
  }

  printf("\nQuiz complete!\n");
  printf("----------------\n");
  printf("Total correct: %d\n", numCorrect);
  printf("Total wrong: %d\n", numWrong);

  // Close the file
  fclose(fptr);

  return 0;
}