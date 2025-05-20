//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  system("clear");
  printf("Welcome to the Immersive C Movie Rating System!\n");
  printf("Please enter the name of the movie you want to rate:");
  char movie_name[256];
  scanf("%s", movie_name);

  printf("Please rate the movie on a scale of 1 to 5:");
  int rating;
  scanf("%d", &rating);

  switch (rating) {
    case 1:
      printf("I hate this movie. It's a waste of time.\n");
      break;
    case 2:
      printf("I don't like this movie, but I'll watch it again.\n");
      break;
    case 3:
      printf("This movie is okay. It's watchable.\n");
      break;
    case 4:
      printf("I like this movie. It's a good watch.\n");
      break;
    case 5:
      printf("I love this movie. It's a masterpiece.\n");
      break;
    default:
      printf("Invalid rating. Please try again.\n");
  }

  printf("Thank you for rating %s. Here are some recommendations:", movie_name);

  // Generate recommendations based on the movie rating
  switch (rating) {
    case 1:
      printf("You might also enjoy: The Room, Birdemic, Citizen Kane.\n");
      break;
    case 2:
      printf("You might also enjoy: The Matrix Reloaded, Harry Potter and the Sorcerer's Stone, The Dark Knight Rises.\n");
      break;
    case 3:
      printf("You might also enjoy: The Shawshank Redemption, Forrest Gump, The Lord of the Flies.\n");
      break;
    case 4:
      printf("You might also enjoy: The Godfather Part II, The Wizard of Oz, The Shawshank Redemption.\n");
      break;
    case 5:
      printf("You might also enjoy: The Godfather Part II, The Godfather, The Dark Knight.\n");
      break;
  }

  system("pause");
  return 0;
}