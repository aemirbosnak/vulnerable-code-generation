//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printMenu();
void addMovie();
void rateMovie();
void viewRatings();
int findMovie(char* movieName);

// Global variables
char* movies[10];
int ratings[10][5];
int numMovies = 0;
int numRatings = 0;

int main() {
  printf("Welcome to the Unique C Movie Rating System!\n");
  printMenu();

  int choice = 0;
  scanf("%d", &choice);
  while (choice != 4) {
    switch(choice) {
      case 1:
        addMovie();
        break;

      case 2:
        rateMovie();
        break;

      case 3:
        viewRatings();
        break;

      default:
        printf("Invalid choice! Please try again.\n");
        break;
    }

    printMenu();
    scanf("%d", &choice);
  }

  printf("Thank you for using the Unique C Movie Rating System!\n");

  return 0;
}

// Function to print the menu options
void printMenu() {
  printf("\n1. Add a movie\n");
  printf("2. Rate a movie\n");
  printf("3. View ratings\n");
  printf("4. Exit\n");
  printf("Enter your choice: ");
}

// Function to add a movie to the system
void addMovie() {
  if (numMovies == 10) {
    printf("Sorry, you have reached the limit of movies!\n");
  } else {
    printf("Enter the name of the movie: ");
    char* name = malloc(50 * sizeof(char));
    scanf("%s", name);
    movies[numMovies] = name;
    numMovies++;
  }
}

// Function to rate a movie
void rateMovie() {
  if (numMovies == 0) {
    printf("Sorry, there are no movies to rate!\n");
  } else {
    printf("Enter the name of the movie: ");
    char* name = malloc(50 * sizeof(char));
    scanf("%s", name);

    int index = findMovie(name);
    if (index == -1) {
      printf("Sorry, that movie is not in the system!\n");
    } else {
      printf("Enter a rating (1-5): ");
      int rating;
      scanf("%d", &rating);

      if (rating < 1 || rating > 5) {
        printf("Invalid rating! Please enter a number between 1 and 5.\n");
      } else {
        ratings[index][rating-1]++;
        numRatings++;
      }
    }

    free(name);
  }
}

// Function to view the ratings of a movie
void viewRatings() {
  if (numMovies == 0) {
    printf("Sorry, there are no movies to view ratings!\n");
  } else {
    printf("Enter the name of the movie: ");
    char* name = malloc(50 * sizeof(char));
    scanf("%s", name);

    int index = findMovie(name);
    if (index == -1) {
      printf("Sorry, that movie is not in the system!\n");
    } else {
      printf("Ratings for %s:\n", name);
      for (int i = 0; i < 5; i++) {
        printf("%d star ratings: %d\n", i+1, ratings[index][i]);
      }
    }

    free(name);
  }
}

// Function to find the index of a movie in the movies array
int findMovie(char* movieName) {
  for (int i = 0; i < numMovies; i++) {
    if (strcmp(movies[i], movieName) == 0) {
      return i;
    }
  }
  return -1;
}