//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: immersive
// Movie Rating System
#include <stdio.h>
#include <stdlib.h>

// Structures
typedef struct {
  char name[50];
  int rating;
} Movie;

// Functions
void displayMenu();
void addMovie(Movie* movies, int* numMovies);
void displayMovies(Movie* movies, int numMovies);
void rateMovie(Movie* movies, int* numMovies);
void sortMovies(Movie* movies, int numMovies);
void displayTopRated(Movie* movies, int numMovies);

int main() {
  Movie movies[50];
  int numMovies = 0;
  int choice;

  displayMenu();
  while (choice != 5) {
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addMovie(movies, &numMovies);
        break;
      case 2:
        displayMovies(movies, numMovies);
        break;
      case 3:
        rateMovie(movies, &numMovies);
        break;
      case 4:
        sortMovies(movies, numMovies);
        break;
      case 5:
        displayTopRated(movies, numMovies);
        break;
      default:
        printf("Invalid choice\n");
    }
    displayMenu();
  }
  return 0;
}

void displayMenu() {
  printf("-------------------------------\n");
  printf("  Movie Rating System\n");
  printf("-------------------------------\n");
  printf("1. Add movie\n");
  printf("2. Display movies\n");
  printf("3. Rate movie\n");
  printf("4. Sort movies\n");
  printf("5. Display top-rated movies\n");
  printf("6. Exit\n");
  printf("-------------------------------\n");
}

void addMovie(Movie* movies, int* numMovies) {
  printf("Enter movie name: ");
  scanf("%s", movies[*numMovies].name);
  movies[*numMovies].rating = 0;
  (*numMovies)++;
}

void displayMovies(Movie* movies, int numMovies) {
  for (int i = 0; i < numMovies; i++) {
    printf("%s - %d\n", movies[i].name, movies[i].rating);
  }
}

void rateMovie(Movie* movies, int* numMovies) {
  printf("Enter movie name: ");
  char movieName[50];
  scanf("%s", movieName);
  int movieIndex = -1;
  for (int i = 0; i < *numMovies; i++) {
    if (strcmp(movies[i].name, movieName) == 0) {
      movieIndex = i;
      break;
    }
  }
  if (movieIndex != -1) {
    printf("Enter rating (1-5): ");
    int rating;
    scanf("%d", &rating);
    movies[movieIndex].rating = rating;
  } else {
    printf("Movie not found\n");
  }
}

void sortMovies(Movie* movies, int numMovies) {
  for (int i = 0; i < numMovies - 1; i++) {
    for (int j = i + 1; j < numMovies; j++) {
      if (movies[i].rating < movies[j].rating) {
        Movie temp = movies[i];
        movies[i] = movies[j];
        movies[j] = temp;
      }
    }
  }
}

void displayTopRated(Movie* movies, int numMovies) {
  printf("Top-rated movies:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s - %d\n", movies[i].name, movies[i].rating);
  }
}