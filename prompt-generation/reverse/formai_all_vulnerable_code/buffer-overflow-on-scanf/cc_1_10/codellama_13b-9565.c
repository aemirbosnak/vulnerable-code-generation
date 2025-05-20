//Code Llama-13B DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

// Declare a structure to store movie details
struct movie {
  char title[50];
  int rating;
};

// Function to display a menu
void displayMenu() {
  printf("Welcome to the movie rating system!\n");
  printf("1. Add a new movie\n");
  printf("2. Display all movies\n");
  printf("3. Rate a movie\n");
  printf("4. Exit\n");
}

// Function to add a new movie
void addMovie() {
  struct movie m;
  printf("Enter the title of the movie: ");
  scanf("%s", m.title);
  printf("Enter the rating: ");
  scanf("%d", &m.rating);
  printf("Movie added successfully!\n");
}

// Function to display all movies
void displayMovies() {
  struct movie m;
  printf("Here are the movies:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s (%d/10)\n", m.title, m.rating);
  }
}

// Function to rate a movie
void rateMovie() {
  struct movie m;
  printf("Enter the title of the movie: ");
  scanf("%s", m.title);
  printf("Enter the new rating: ");
  scanf("%d", &m.rating);
  printf("Movie rated successfully!\n");
}

int main() {
  // Initialize an array of movies
  struct movie movies[5];

  // Display the menu
  displayMenu();

  // Get user input
  int choice;
  scanf("%d", &choice);

  // Perform the selected action
  switch (choice) {
    case 1:
      addMovie();
      break;
    case 2:
      displayMovies();
      break;
    case 3:
      rateMovie();
      break;
    case 4:
      return 0;
  }

  // Repeat the process
  printf("Would you like to perform another action? (y/n) ");
  char repeat;
  scanf(" %c", &repeat);
  if (repeat == 'y') {
    main();
  }

  return 0;
}