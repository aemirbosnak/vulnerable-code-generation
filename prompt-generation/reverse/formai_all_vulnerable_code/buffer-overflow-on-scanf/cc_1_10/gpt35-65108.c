//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVIES 10

typedef struct {
  char title[50];
  char genre[20];
  float rating;
} Movie;

Movie database[MAX_MOVIES];
int num_movies;

void add_movie() {
  Movie new_movie;
  printf("Enter movie title: ");
  scanf("%s", new_movie.title);
  printf("Enter movie genre: ");
  scanf("%s", new_movie.genre);
  printf("Enter movie rating (out of 10): ");
  scanf("%f", &new_movie.rating);

  if (num_movies < MAX_MOVIES) {
    database[num_movies] = new_movie;
    num_movies++;
    printf("Movie added!\n");
  } else {
    printf("Database is full. Movie not added.\n");
  }
}

void print_database() {
  printf("\nTitle\t\tGenre\t\tRating\n");
  printf("----------------------------------------------\n");
  for (int i = 0; i < num_movies; i++) {
    printf("%s\t\t%s\t\t%.1f\n", database[i].title, database[i].genre, database[i].rating);
  }
  printf("\n");
}

int main() {
  num_movies = 0;
  
  while (1) {
    printf("Welcome to the C Movie Rating System!\n");
    printf("1. Add a movie\n");
    printf("2. View database\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_movie();
        break;
      case 2:
        print_database();
        break;
      case 3:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}