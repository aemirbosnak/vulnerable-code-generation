//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char title[50];
  int year;
  char genre[20];
  int rating;
} Movie;

void print_movie(Movie *movie) {
  printf("%s (%d)\n", movie->title, movie->year);
  printf("  Genre: %s\n", movie->genre);
  printf("  Rating: %d\n", movie->rating);
  printf("\n");
}

void sort_movies(Movie *movies, int num_movies) {
  for (int i = 0; i < num_movies - 1; i++) {
    for (int j = i + 1; j < num_movies; j++) {
      if (strcmp(movies[i].title, movies[j].title) > 0) {
        Movie temp = movies[i];
        movies[i] = movies[j];
        movies[j] = temp;
      }
    }
  }
}

int main() {
  Movie movies[] = {
    {"Casablanca", 1942, "Drama", 5},
    {"The Godfather", 1972, "Crime", 5},
    {"The Dark Knight", 2008, "Action", 5},
    {"12 Angry Men", 1957, "Drama", 5},
    {"Schindler's List", 1993, "Drama", 5},
    {"The Matrix", 1999, "Sci-Fi", 5},
    {"The Lord of the Rings: The Return of the King", 2003, "Fantasy", 5},
    {"Star Wars: Episode V - The Empire Strikes Back", 1980, "Sci-Fi", 5},
    {"The Shawshank Redemption", 1994, "Drama", 5},
    {"The Godfather Part II", 1974, "Crime", 5}
  };

  int num_movies = sizeof(movies) / sizeof(Movie);

  printf("Welcome to the C Movie Rating System!\n");
  printf("====================================\n\n");

  while (1) {
    printf("What would you like to do?\n");
    printf("  1. List all movies\n");
    printf("  2. Search for a movie\n");
    printf("  3. Add a movie\n");
    printf("  4. Quit\n");
    printf("> ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Listing all movies:\n\n");
        for (int i = 0; i < num_movies; i++) {
          print_movie(&movies[i]);
        }
        break;
      case 2:
        printf("Enter the title of the movie you want to search for: ");
        char title[50];
        scanf(" %s", title);

        int found = 0;
        for (int i = 0; i < num_movies; i++) {
          if (strcmp(movies[i].title, title) == 0) {
            print_movie(&movies[i]);
            found = 1;
            break;
          }
        }

        if (!found) {
          printf("Movie not found.\n");
        }
        break;
      case 3:
        printf("Enter the title of the movie you want to add: ");
        char title2[50];
        scanf(" %s", title2);

        printf("Enter the year the movie was released: ");
        int year;
        scanf("%d", &year);

        printf("Enter the genre of the movie: ");
        char genre[20];
        scanf(" %s", genre);

        printf("Enter the rating of the movie (1-5): ");
        int rating;
        scanf("%d", &rating);

        Movie new_movie = {title2, year, genre, rating};

        movies[num_movies++] = new_movie;

        sort_movies(movies, num_movies);

        printf("Movie added.\n");
        break;
      case 4:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}