//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LEN 50

typedef struct Movie {
  char title[MAX_TITLE_LEN];
  int rating;
} Movie;

// Function to compare two movies by rating, in descending order
int compare_movies(const void* a, const void* b) {
  const Movie* movie1 = (const Movie*)a;
  const Movie* movie2 = (const Movie*)b;

  return movie2->rating - movie1->rating;
}

// Function to print a movie's information
void print_movie(const Movie* movie) {
  printf("%s: %d\n", movie->title, movie->rating);
}

// Function to get a movie's rating from the user
int get_movie_rating() {
  int rating;

  do {
    printf("Enter a rating (1-5): ");
    scanf("%d", &rating);
  } while (rating < 1 || rating > 5);

  return rating;
}

// Function to get a movie's title from the user
void get_movie_title(char* title) {
  printf("Enter the movie's title: ");
  scanf(" %[^\n]", title);
}

// Function to add a movie to the database
void add_movie(Movie* movies, int* num_movies) {
  if (*num_movies >= MAX_MOVIES) {
    printf("Error: The database is full.\n");
    return;
  }

  char title[MAX_TITLE_LEN];
  int rating;

  get_movie_title(title);
  rating = get_movie_rating();

  strcpy(movies[*num_movies].title, title);
  movies[*num_movies].rating = rating;

  (*num_movies)++;
}

// Function to print the movies in the database
void print_movies(const Movie* movies, int num_movies) {
  printf("Movies in the database:\n");

  for (int i = 0; i < num_movies; i++) {
    print_movie(&movies[i]);
  }
}

// Function to search for a movie by title
int search_movie(const Movie* movies, int num_movies, const char* title) {
  for (int i = 0; i < num_movies; i++) {
    if (strcmp(movies[i].title, title) == 0) {
      return i;
    }
  }

  return -1;
}

// Function to delete a movie from the database
void delete_movie(Movie* movies, int* num_movies, int index) {
  if (index < 0 || index >= *num_movies) {
    printf("Error: Invalid index.\n");
    return;
  }

  for (int i = index; i < *num_movies - 1; i++) {
    movies[i] = movies[i + 1];
  }

  (*num_movies)--;
}

// Main function
int main() {
  // Create an array to store the movies
  Movie movies[MAX_MOVIES];

  // Initialize the number of movies to 0
  int num_movies = 0;

  // Get the user's input
  int choice;
  char title[MAX_TITLE_LEN];

  do {
    printf("\nMovie Rating System\n");
    printf("1. Add a movie\n");
    printf("2. Print all movies\n");
    printf("3. Search for a movie by title\n");
    printf("4. Delete a movie\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_movie(movies, &num_movies);
        break;

      case 2:
        print_movies(movies, num_movies);
        break;

      case 3:
        printf("Enter the title of the movie you want to search for: ");
        scanf(" %[^\n]", title);

        int index = search_movie(movies, num_movies, title);
        if (index == -1) {
          printf("Movie not found.\n");
        } else {
          print_movie(&movies[index]);
        }
        break;

      case 4:
        printf("Enter the title of the movie you want to delete: ");
        scanf(" %[^\n]", title);

        index = search_movie(movies, num_movies, title);
        if (index == -1) {
          printf("Movie not found.\n");
        } else {
          delete_movie(movies, &num_movies, index);
          printf("Movie deleted successfully.\n");
        }
        break;

      case 5:
        printf("Quitting the program.\n");
        break;

      default:
        printf("Invalid choice.\n");
        break;
    }
  } while (choice != 5);

  return 0;
}