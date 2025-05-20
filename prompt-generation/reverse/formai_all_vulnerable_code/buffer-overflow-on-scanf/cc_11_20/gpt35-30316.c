//FormAI DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>

int main() {
  int rating = 0;
  char movie_title[50];

  printf("Welcome to our unique movie rating system!\n\n");
  printf("Please enter the title of the movie you would like to rate: ");
  scanf("%s", &movie_title);

  printf("\nGreat! Now please rate %s on a scale of 1-10: ", movie_title);
  scanf("%d", &rating);

  // Make sure the rating is within the acceptable range
  if (rating < 1 || rating > 10) {
    printf("\nInvalid rating. Please enter a number between 1 and 10.\n");
    return 1;
  }

  printf("\nThank you for rating %s!\n", movie_title);

  // Output a unique message depending on the rating
  switch (rating) {
    case 1:
      printf("You didn't like %s very much, did you?\n", movie_title);
      break;
    case 2:
      printf("Looks like %s wasn't your cup of tea.\n", movie_title);
      break;
    case 3:
      printf("Hmm, %s didn't really do it for you, did it?\n", movie_title);
      break;
    case 4:
      printf("That's too bad. You were hoping for more from %s.\n", movie_title);
      break;
    case 5:
      printf("Well, %s was just okay for you.\n", movie_title);
      break;
    case 6:
      printf("You seemed to enjoy %s, didn't you?\n", movie_title);
      break;
    case 7:
      printf("You really liked %s, didn't you?\n", movie_title);
      break;
    case 8:
      printf("Wow, %s really impressed you!\n", movie_title);
      break;
    case 9:
      printf("Amazing! %s is one of the best movies you've ever seen!\n", movie_title);
      break;
    case 10:
      printf("You're blown away by %s! It's a masterpiece!\n", movie_title);
      break;
    default:
      printf("Oops! Something went wrong.\n");
  }

  return 0;
}