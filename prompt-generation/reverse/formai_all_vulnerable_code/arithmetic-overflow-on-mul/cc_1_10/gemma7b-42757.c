//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char movie_name[20];
  int rating;
  float popcorn_cost;

  printf("Welcome to the Cine-Magna Rating System!\n");
  printf("Please enter the name of the movie you want to rate:");
  scanf("%s", movie_name);

  printf("Please rate the movie on a scale of 1-5:");
  scanf("%d", &rating);

  printf("Please enter the cost of a bucket of popcorn:");
  scanf("%f", &popcorn_cost);

  // Calculate the total cost of the movie experience
  float total_cost = popcorn_cost + (rating * 2);

  // Display the movie rating and total cost
  printf("Movie name: %s\n", movie_name);
  printf("Rating: %d\n", rating);
  printf("Popcorn cost: $%.2f\n", popcorn_cost);
  printf("Total cost: $%.2f\n", total_cost);

  // Create a unique movie rating system rating based on the movie name
  switch (rating)
  {
    case 1:
      printf("You should have seen 'Citizen Kane' instead.\n");
      break;
    case 2:
      printf("This movie is better than 'The Room'. Don't you forget that.\n");
      break;
    case 3:
      printf("A decent film, but not as great as 'The Lord of the Flies'.\n");
      break;
    case 4:
      printf("You're a lucky person. See 'Casablanca' ASAP.\n");
      break;
    case 5:
      printf("This movie is a masterpiece. Go see it in the theater.\n");
      break;
  }

  return 0;
}