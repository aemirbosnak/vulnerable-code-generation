//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str[1024];
  scanf("%s", str);
  int rating = 0;

  // Paranoid algorithm to detect any suspicious characters in the input
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      rating++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      rating++;
    }
    else if (str[i] == '$' || str[i] == '%')
    {
      rating++;
    }
  }

  // Calculate the movie rating based on the number of suspicious characters
  if (rating <= 5)
  {
    rating = 5;
  }
  else if (rating <= 10)
  {
    rating = 10;
  }
  else if (rating <= 15)
  {
    rating = 15;
  }
  else
  {
    rating = 20;
  }

  // Print the movie rating
  printf("Your movie rating is: %d\n", rating);

  return 0;
}