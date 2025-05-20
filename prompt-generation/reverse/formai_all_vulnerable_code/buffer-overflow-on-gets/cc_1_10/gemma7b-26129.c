//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str[200];
  int i, x, y, z;

  printf("You are in the dim light of the Musgrave Club, Mr. Holmes.\n");
  printf("A mysterious letter has been received, and it is your job to decipher its contents.\n");

  // Read the letter
  printf("Please enter the message: ");
  gets(str);

  // Analyze the letter
  x = 0;
  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      x++;
    }
  }

  // Count the number of words
  y = 0;
  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ' ')
    {
      y++;
    }
  }

  // Determine the location of the crime
  z = 0;
  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      z++;
    }
  }

  // Print the results
  printf("The letter contains %d words and %d letters.\n", y, x);
  printf("The location of the crime is at %d.%c.\n", z, str[z]);

  return 0;
}