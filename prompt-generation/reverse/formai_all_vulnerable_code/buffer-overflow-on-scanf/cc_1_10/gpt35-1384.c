//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global varibles */
int count = 0; // counter to keep track of number of movies rated
float ratings[50]; // array to store ratings
char names[50][50]; // 2D array to store movie names

/* Function to add a movie */
void addMovie() {
  char name[50];
  printf("\nEnter the name of the movie: ");
  scanf("%s", name);
  strcpy(names[count], name);

  float rating;
  printf("Enter the rating of the movie (out of 10): ");
  scanf("%f", &rating);
  ratings[count] = rating;

  printf("\nThank you for rating the movie!\n\n");
  count++; // increment the counter
}

/* Function to display all the movies */
void displayMovies() {
  if (count == 0) { // If there are no ratings, tell the user
    printf("\nSorry, no ratings to display at the moment.\n\n");
    return;
  }

  printf("\nMovie Ratings:\n\n");

  for (int i = 0; i < count; i++) { // loop through all the ratings and print them
    printf("%d. %s - %.1f\n", i+1, names[i], ratings[i]);
  }

  printf("\n");
}

/* Function to find the highest rated movie */
void highestRatedMovie() {
  if (count == 0) { // If there are no ratings, tell the user
    printf("\nSorry, no ratings to display at the moment.\n\n");
    return;
  }

  int highest_index = 0;

  for (int i = 1; i < count; i++) { // loop through all the ratings and find the highest
    if (ratings[i] > ratings[highest_index]) {
      highest_index = i;
    }
  }

  printf("\nThe highest rated movie is \"%s\" with a rating of %.1f\n\n", names[highest_index], ratings[highest_index]);
}

/* Main function */
int main() {
  printf("Welcome to the C Movie Rating System!\n\n");

  int choice;
  while (1) { // infinite loop, until the user exits
    printf("Please select an option:\n");
    printf("1. Add a movie and rate it\n");
    printf("2. Display all the movies rated so far\n");
    printf("3. Find the highest rated movie\n");
    printf("4. Exit\n\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      addMovie();
      break;
    case 2:
      displayMovies();
      break;
    case 3:
      highestRatedMovie();
      break;
    case 4:
      printf("\nThank you for using the C Movie Rating System!\n\n");
      exit(0); // Exit the program
    default:
      printf("\nInvalid choice, please try again.\n\n");
      break;
    }
  }

  return 0;
}