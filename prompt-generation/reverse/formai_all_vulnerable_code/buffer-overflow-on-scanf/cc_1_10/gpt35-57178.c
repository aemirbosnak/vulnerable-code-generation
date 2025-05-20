//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
// C Movie Rating System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold movie details
struct Movie {
  char title[50];
  char director[50];
  int year;
  float rating;
};

// Function to create new movie entry
void createMovie(struct Movie *newMovie) {
  printf("\nEnter movie title: ");
  scanf("%s", newMovie->title);
  
  printf("Enter director name: ");
  scanf("%s", newMovie->director);
  
  printf("Enter year of release: ");
  scanf("%d", &newMovie->year);
  
  printf("Enter rating (out of 10): ");
  scanf("%f", &newMovie->rating);
}

// Function to display movie details
void displayMovie(struct Movie *movie) {
  printf("\nTitle: %s", movie->title);
  printf("\nDirector: %s", movie->director);
  printf("\nYear of release: %d", movie->year);
  printf("\nRating: %.1f/10", movie->rating);
}

// Function to rate a movie
void rateMovie(struct Movie *movie) {
  float newRating;
  printf("\nEnter your rating (out of 10): ");
  scanf("%f", &newRating);
  
  // Calculate new average rating
  movie->rating = (movie->rating + newRating) / 2;
  printf("\nMovie rating updated!");
}

int main() {
  int option; // Menu option
  int numMovies = 0; // Number of movies in array
  struct Movie movieList[10]; // Array of movie structs
  
  do {
    // Display the menu
    printf("\n\n==== C Movie Rating System ====");
    printf("\n1. Add a new movie");
    printf("\n2. View list of movies");
    printf("\n3. Rate a movie");
    printf("\n0. Exit program");
    printf("\n\nEnter your choice (0-3): ");
    scanf("%d", &option);
    
    switch(option) {
      case 0: // Exit program
        printf("\nGoodbye!"); 
        break;
        
      case 1: // Add new movie to array
        if(numMovies < 10) {
          createMovie(&movieList[numMovies]);
          numMovies++;        
        } else {
          printf("\nArray is full!");          
        }
        break;
        
      case 2: // Display list of movies in array
        printf("\nList of movies:\n");
        for(int i = 0; i < numMovies; i++) {
          printf("\n%d. ", i+1);
          displayMovie(&movieList[i]);
        }
        break;
        
      case 3: // Rate a movie
        if(numMovies > 0) {
          int movieIndex;
          printf("\nEnter the index of the movie you want to rate (1-%d): ", numMovies);
          scanf("%d", &movieIndex);
          if(movieIndex > 0 && movieIndex <= numMovies) {
            rateMovie(&movieList[movieIndex-1]);
          } else {
            printf("\nInvalid index!");            
          }
        } else {
          printf("\nNo movies found!");          
        }
        break;
        
      default: // Invalid option
        printf("\nInvalid option!");
    }
    
  } while(option != 0);
  
  return 0;
}