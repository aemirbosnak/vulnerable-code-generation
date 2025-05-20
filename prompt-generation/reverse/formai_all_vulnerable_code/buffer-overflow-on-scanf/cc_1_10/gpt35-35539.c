//FormAI DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <string.h>

struct Movie {
  char title[50];
  char genre[20];
  int year;
  int rating;
};

// Function to print the movie ratings
void printRatings(struct Movie movies[], int size) {
  printf("MOVIE RATINGS\n");
  printf("------------------------------\n");
  for (int i = 0; i < size; i++) {
    printf("%s: %d\n", movies[i].title, movies[i].rating);
  }
  printf("------------------------------\n\n");
}

// Function to update the rating of a movie
void updateRating(struct Movie movies[], int size, char title[]) {
  for (int i = 0; i < size; i++) {
    if (strcmp(movies[i].title, title) == 0) {
      printf("What is your rating for %s (out of 5)? ", title);
      scanf("%d", &movies[i].rating);
      printf("Thank you for your rating!\n\n");
      return;
    }
  }
  printf("Sorry, we could not find a movie with that title.\n\n");
}

int main() {
  struct Movie movies[5]; // max 5 movies at a time
  int size = 0;
  char input[10];

  printf("*** WELCOME TO THE MEDIEVAL MOVIE RATING SYSTEM ***\n\n");

  while (strcmp(input, "exit") != 0) {
    printf("What would you like to do?\n");
    printf("1. Add a Movie\n");
    printf("2. Print Ratings\n");
    printf("3. Update a Movie Rating\n");
    printf("Type 'exit' to quit.\n\n");
    printf("Input: ");
    scanf("%s", input);

    if (strcmp(input, "1") == 0) {
      // Adding a movie
      if (size == 5) {
        printf("\nSorry, we can only have a maximum of 5 movies at a time!\n\n");
        continue;
      }
      printf("\nEnter the Title of the Movie: ");
      scanf("%s", movies[size].title);
      printf("Enter the Genre of the Movie: ");
      scanf("%s", movies[size].genre);
      printf("Enter the Year of Release: ");
      scanf("%d", &movies[size].year);
      printf("Thank you for adding %s! What is your rating for %s (out of 5)? ", movies[size].title, movies[size].title);
      scanf("%d", &movies[size].rating);
      printf("\n");
      size++;
    } else if (strcmp(input, "2") == 0) {
      // Printing the movie ratings
      if (size == 0) {
        printf("\nThere are no movies yet!\n\n");
        continue;
      }
      printRatings(movies, size);
    } else if (strcmp(input, "3") == 0) {
      // Updating the rating of a movie
      if (size == 0) {
        printf("\nThere are no movies yet!\n\n");
        continue;
      }
      char title[50];
      printf("\nWhat is the title of the movie you want to update? ");
      scanf("%s", title);
      updateRating(movies, size, title);
    } else if (strcmp(input, "exit") != 0) {
      printf("\nInvalid Input! Please try again.\n\n");
    }
  }

  printf("*** THANK YOU FOR USING THE MEDIEVAL MOVIE RATING SYSTEM! ***\n\n");

  return 0;
}