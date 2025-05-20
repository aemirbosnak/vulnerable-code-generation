//FormAI DATASET v1.0 Category: Movie Rating System ; Style: immersive
#include <stdio.h>

// Movie struct definition
struct Movie {
  char title[50];
  char director[50];
  int year;
  float rating;
};

// Function to add a movie to the database
void add_movie(struct Movie database[], int *count) {
  printf("\nAdding a new movie...\n");
  printf("Title: ");
  scanf("%s", database[*count].title);
  printf("Director: ");
  scanf("%s", database[*count].director);
  printf("Year: ");
  scanf("%d", &database[*count].year);
  printf("Rating: ");
  scanf("%f", &database[*count].rating);
  *count += 1;
  printf("\nMovie added successfully.\n");
}

// Function to display the movies in the database
void display_movies(struct Movie database[], int count) {
  printf("\nMovies in the database:\n");
  printf("Title\t\tDirector\tYear\tRating\n");
  for (int i = 0; i < count; i++) {
    printf("%s\t%s\t\t%d\t%.1f\n", database[i].title, database[i].director, database[i].year, database[i].rating);
  }
}

// Function to search for a movie in the database
void search_movie(struct Movie database[], int count) {
  char title[50];
  printf("\nEnter the title of the movie you want to search: ");
  scanf("%s", title);
  for (int i = 0; i < count; i++) {
    if (strcmp(database[i].title, title) == 0) {
      printf("\nMovie found:\n");
      printf("Title\t\tDirector\tYear\tRating\n");
      printf("%s\t%s\t\t%d\t%.1f\n", database[i].title, database[i].director, database[i].year, database[i].rating);
      return;
    }
  }
  printf("\nMovie not found.\n");
}

int main() {
  // Welcome message
  printf("Welcome to the C Movie Rating System!\n\n");

  // Database of movies
  struct Movie database[50];
  int count = 0;

  // Menu loop
  int choice;
  do {
    printf("\nMenu:\n");
    printf("1. Add a movie to the database\n");
    printf("2. Display all movies in the database\n");
    printf("3. Search for a movie in the database\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_movie(database, &count);
        break;
      case 2:
        display_movies(database, count);
        break;
      case 3:
        search_movie(database, count);
        break;
      case 4:
        printf("\nThank you for using the C Movie Rating System!\n");
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while (choice != 4);

  return 0;
}