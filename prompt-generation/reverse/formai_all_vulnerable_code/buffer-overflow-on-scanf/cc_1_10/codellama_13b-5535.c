//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
/*
 * C Movie Rating System
 *
 * A program that allows users to rate movies based on their
 * satisfaction with the film. The program will keep track of the
 * average rating of each movie and the number of ratings for each
 * movie.
 */

#include <stdio.h>

// Structure to store information about a movie
struct movie {
  char title[50];
  float rating;
  int num_ratings;
};

// Function to read a movie from the user
void read_movie(struct movie *m) {
  printf("Enter the title of the movie: ");
  scanf("%s", m->title);
  printf("Enter your rating (out of 10): ");
  scanf("%f", &m->rating);
  m->num_ratings++;
}

// Function to display a movie
void display_movie(struct movie *m) {
  printf("Movie: %s\n", m->title);
  printf("Rating: %.1f\n", m->rating);
  printf("Number of Ratings: %d\n", m->num_ratings);
}

// Function to calculate the average rating of a movie
float avg_rating(struct movie *m) {
  return m->rating / m->num_ratings;
}

int main() {
  struct movie movies[10];
  int i, n;

  // Initialize the movies
  for (i = 0; i < 10; i++) {
    movies[i].title[0] = '\0';
    movies[i].rating = 0;
    movies[i].num_ratings = 0;
  }

  // Prompt the user to input the movies
  printf("Enter the movies you want to rate (enter 'q' to quit):\n");
  for (i = 0; i < 10; i++) {
    read_movie(&movies[i]);
  }

  // Display the movies and their ratings
  printf("Here are the movies you rated:\n");
  for (i = 0; i < 10; i++) {
    display_movie(&movies[i]);
  }

  // Calculate the average rating of each movie
  for (i = 0; i < 10; i++) {
    movies[i].rating = avg_rating(&movies[i]);
  }

  // Display the average rating of each movie
  printf("Here are the average ratings for each movie:\n");
  for (i = 0; i < 10; i++) {
    printf("Movie: %s\n", movies[i].title);
    printf("Average Rating: %.1f\n", movies[i].rating);
  }

  return 0;
}