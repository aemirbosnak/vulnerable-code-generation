//FormAI DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
  char title[50];
  char genre[20];
  int rating;
};

int main() {
  // initializing movies
  struct Movie batman = {"Batman", "Action", 4};
  struct Movie joker = {"Joker", "Drama", 5};
  struct Movie star_wars = {"Star Wars", "Sci-Fi", 3};

  // declaring variables to calculate average
  int total_rating = batman.rating + joker.rating + star_wars.rating;
  int count = 3;
  float average_rating = (float)total_rating / (float)count;

  // displaying movies and ratings
  printf("Movie Ratings\n-------------\n");
  printf("%s: %d/5\n", batman.title, batman.rating);
  printf("%s: %d/5\n", joker.title, joker.rating);
  printf("%s: %d/5\n", star_wars.title, star_wars.rating);
  printf("-------------\n");

  // displaying average rating
  printf("Average Rating: %.2f/5\n", average_rating);

  // prompt user to add a movie and rating
  printf("Do you want to add a movie and rating? (y/n): ");
  char choice = getchar();

  if (choice == 'y') {
    // creating new movie and getting user input for title, genre, and rating
    struct Movie new_movie;
    printf("Enter movie title: ");
    fgets(new_movie.title, 50, stdin);
    printf("Enter movie genre: ");
    fgets(new_movie.genre, 20, stdin);
    printf("Enter movie rating out of 5: ");
    scanf("%d", &new_movie.rating);

    // adding new movie to array of movies
    struct Movie movies[4] = {batman, joker, star_wars, new_movie};

    // updating count and total rating
    count++;
    total_rating += new_movie.rating;

    // updating average rating
    average_rating = (float)total_rating / (float)count;

    // displaying updated movie ratings and average rating
    printf("\nUpdated Movie Ratings\n-------------\n");
    for (int i = 0; i < count; i++) {
      printf("%s: %d/5\n", movies[i].title, movies[i].rating);
    }
    printf("-------------\n");
    printf("Average Rating: %.2f/5", average_rating);
  }

  return 0;
}