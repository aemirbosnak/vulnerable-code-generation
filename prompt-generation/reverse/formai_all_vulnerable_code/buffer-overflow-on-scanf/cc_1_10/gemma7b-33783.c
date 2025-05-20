//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int rating = 0;
  char genre = ' ';
  char actor = ' ';

  printf("Enter the movie rating (1-10): ");
  scanf("%d", &rating);

  printf("Enter the movie genre (comedy, drama, thriller): ");
  scanf(" %c", &genre);

  printf("Enter the actor's name: ");
  scanf(" %c", &actor);

  switch (genre) {
    case 'c':
      if (rating >= 7) {
        printf("Recommended! You might enjoy this movie.\n");
      } else {
        printf("Meh. This movie is okay, but it could be better.\n");
      }
      break;
    case 'd':
      if (rating >= 8) {
        printf("Highly recommended! You'll love this movie.\n");
      } else {
        printf("Not bad, but it could be better. Maybe try something else.\n");
      }
      break;
    case 't':
      if (rating >= 9) {
        printf("Must-see! You have to watch this movie.\n");
      } else {
        printf("Avoid at all costs! This movie is terrible.\n");
      }
      break;
  }

  switch (actor) {
    case 'a':
      printf("Brad Pitt: A legend.\n");
      break;
    case 'c':
      printf("Chris Hemsworth: A great actor.\n");
      break;
    case 'r':
      printf("Robert Downey Jr.: An icon.\n");
      break;
  }

  return 0;
}