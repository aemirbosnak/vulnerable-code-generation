//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

// Define movie struct
struct movie {
  char title[50];
  int year;
  char genre[50];
  float rating;
};

// Function to add a movie to the system
struct movie addMovie() {
  struct movie m;
  printf("Enter the movie title: ");
  scanf("%[^\n]s", m.title);
  printf("Enter the release year: ");
  scanf("%d", &m.year);
  printf("Enter the genre: ");
  scanf("%s", m.genre);
  printf("Enter the movie rating (0.0 - 10.0): ");
  scanf("%f", &m.rating);
  return m;
}

// Function to print a movie's details
void displayMovie(struct movie m) {
  printf("\nTitle: %s\n", m.title);
  printf("Release year: %d\n", m.year);
  printf("Genre: %s\n", m.genre);
  printf("Rating: %.1f\n", m.rating);
}

// Driver program
int main() {
  int choice, i, n, minRating;
  printf("--- Welcome to the Unique C Movie Rating System! ---\n\n");

  // Get the number of movies
  printf("Enter the number of movies: ");
  scanf("%d", &n);

  // Create an array of movies
  struct movie movies[n];

  // Add movies to the array
  for(i = 0; i < n; i++) {
    printf("\nEnter the details of Movie %d:\n", i+1);
    movies[i] = addMovie();
  }

  // Display the movies in the array
  printf("\nThe details of the movies are:\n\n");
  for(i = 0; i < n; i++) {
    displayMovie(movies[i]);
  }

  // Get the minimum rating for filtering
  printf("\nEnter the minimum rating for filtering (0.0 - 10.0): ");
  scanf("%d", &minRating);

  // Filter the movies based on the minimum rating
  printf("\nThe movies with a rating of %d or higher are:\n\n", minRating);
  for(i = 0; i < n; i++) {
    if(movies[i].rating >= minRating) {
      displayMovie(movies[i]);
    }
  }

  printf("\nThank you for using the Unique C Movie Rating System!");

  return 0;
}