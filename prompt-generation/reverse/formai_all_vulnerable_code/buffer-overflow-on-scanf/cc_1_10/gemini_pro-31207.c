//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
#define G 0
#define PG 1
#define PG13 2
#define R 3
#define NC17 4

// Define the movie genres
#define ACTION 0
#define ADVENTURE 1
#define COMEDY 2
#define DRAMA 3
#define HORROR 4
#define ROMANCE 5
#define SCI_FI 6
#define THRILLER 7
#define WESTERN 8

// Define the movie struct
typedef struct movie {
  char title[50];
  int rating;
  int genre;
  float score;
} movie;

// Create a function to print the movie rating system
void print_rating_system() {
  printf("Movie Rating System:\n");
  printf("G: General Audiences\n");
  printf("PG: Parental Guidance Suggested\n");
  printf("PG13: Parents Strongly Cautioned\n");
  printf("R: Restricted\n");
  printf("NC17: No One 17 and Under Admitted\n");
}

// Create a function to print the movie genres
void print_genres() {
  printf("Movie Genres:\n");
  printf("0: Action\n");
  printf("1: Adventure\n");
  printf("2: Comedy\n");
  printf("3: Drama\n");
  printf("4: Horror\n");
  printf("5: Romance\n");
  printf("6: Sci-Fi\n");
  printf("7: Thriller\n");
  printf("8: Western\n");
}

// Create a function to get the movie rating
int get_rating() {
  int rating;

  printf("Enter the movie rating (0-4): ");
  scanf("%d", &rating);

  return rating;
}

// Create a function to get the movie genre
int get_genre() {
  int genre;

  printf("Enter the movie genre (0-8): ");
  scanf("%d", &genre);

  return genre;
}

// Create a function to get the movie score
float get_score() {
  float score;

  printf("Enter the movie score (0.0-10.0): ");
  scanf("%f", &score);

  return score;
}

// Create a function to create a movie
movie create_movie() {
  movie m;

  printf("Enter the movie title: ");
  scanf("%s", m.title);

  m.rating = get_rating();
  m.genre = get_genre();
  m.score = get_score();

  return m;
}

// Create a function to print a movie
void print_movie(movie m) {
  printf("Title: %s\n", m.title);
  printf("Rating: ");
  switch (m.rating) {
    case G:
      printf("G");
      break;
    case PG:
      printf("PG");
      break;
    case PG13:
      printf("PG13");
      break;
    case R:
      printf("R");
      break;
    case NC17:
      printf("NC17");
      break;
  }
  printf("\n");
  printf("Genre: ");
  switch (m.genre) {
    case ACTION:
      printf("Action");
      break;
    case ADVENTURE:
      printf("Adventure");
      break;
    case COMEDY:
      printf("Comedy");
      break;
    case DRAMA:
      printf("Drama");
      break;
    case HORROR:
      printf("Horror");
      break;
    case ROMANCE:
      printf("Romance");
      break;
    case SCI_FI:
      printf("Sci-Fi");
      break;
    case THRILLER:
      printf("Thriller");
      break;
    case WESTERN:
      printf("Western");
      break;
  }
  printf("\n");
  printf("Score: %.1f\n", m.score);
}

// Create a function to main
int main() {
  // Print the movie rating system
  print_rating_system();

  // Print the movie genres
  print_genres();

  // Create a movie
  movie m = create_movie();

  // Print the movie
  print_movie(m);

  return 0;
}