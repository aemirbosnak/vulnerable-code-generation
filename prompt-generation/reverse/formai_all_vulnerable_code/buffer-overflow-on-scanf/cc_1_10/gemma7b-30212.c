//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void rate_movie()
{
  int rating;
  char genre;
  printf("What is the genre of the movie? (Comedy, Drama, Action)\n");
  scanf(" %c", &genre);

  printf("What is your rating of the movie? (1-5)\n");
  scanf(" %d", &rating);

  switch (genre)
  {
    case 'C':
      if (rating >= 3)
      {
        printf("You will enjoy this comedy.\n");
      }
      else
      {
        printf("You may not enjoy this comedy.\n");
      }
      break;
    case 'D':
      if (rating <= 2)
      {
        printf("You may not enjoy this drama.\n");
      }
      else
      {
        printf("You will enjoy this drama.\n");
      }
      break;
    case 'A':
      if (rating >= 4)
      {
        printf("You will enjoy this action movie.\n");
      }
      else
      {
        printf("You may not enjoy this action movie.\n");
      }
      break;
  }
}

int main()
{
  rate_movie();
  return 0;
}