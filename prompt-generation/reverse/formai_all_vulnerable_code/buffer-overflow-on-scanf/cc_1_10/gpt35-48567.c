//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50

typedef enum {
  RATING_G,
  RATING_PG,
  RATING_PG13,
  RATING_R,
  RATING_NC17
} Rating;

typedef struct {
  char title[MAX_TITLE_LENGTH];
  Rating rating;
} Movie;

Movie movieList[MAX_MOVIES];
int numMovies = 0;

void addMovie(char *title, Rating rating) {
  if (numMovies == MAX_MOVIES) {
    printf("Cannot add movie - maximum capacity reached.\n");
    return;
  }
  
  Movie newMovie;
  strcpy(newMovie.title, title);
  newMovie.rating = rating;
  
  movieList[numMovies++] = newMovie;
}

void listMovies() {
  printf("%-30s %-10s\n", "Movie Title", "Rating");
  printf("--------------------------------------------\n");
  
  for (int i = 0; i < numMovies; i++) {
    Movie movie = movieList[i];
    char ratingString[10];
    
    switch (movie.rating) {
      case RATING_G:
        strcpy(ratingString, "G");
        break;
        
      case RATING_PG:
        strcpy(ratingString, "PG");
        break;
        
      case RATING_PG13:
        strcpy(ratingString, "PG-13");
        break;
        
      case RATING_R:
        strcpy(ratingString, "R");
        break;
        
      case RATING_NC17:
        strcpy(ratingString, "NC-17");
        break;
    }
    
    printf("%-30s %-10s\n", movie.title, ratingString);
  }
}

int main() {
  int choice;
  char title[MAX_TITLE_LENGTH];
  Rating rating;
  
  do {
    printf("\nC Movie Rating System\n");
    printf("--------------------------------------------\n");
    printf("1. Add a movie to the list\n");
    printf("2. List all movies in the list\n");
    printf("3. Quit\n");
    printf("Enter choice (1-3): ");
    
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("Enter movie title: ");
        scanf("%s", title);
        printf("Enter movie rating (1-5):\n");
        printf("1. G\n");
        printf("2. PG\n");
        printf("3. PG-13\n");
        printf("4. R\n");
        printf("5. NC-17\n");
        printf("Enter choice (1-5): ");
        
        int ratingChoice;
        scanf("%d", &ratingChoice);
        
        switch (ratingChoice) {
          case 1:
            rating = RATING_G;
            break;
            
          case 2:
            rating = RATING_PG;
            break;
            
          case 3:
            rating = RATING_PG13;
            break;
            
          case 4:
            rating = RATING_R;
            break;
            
          case 5:
            rating = RATING_NC17;
            break;
            
          default:
            printf("Invalid rating choice.\n");
            continue;
        }
        
        addMovie(title, rating);
        break;
        
      case 2:
        listMovies();
        break;
        
      case 3:
        printf("Quitting program.\n");
        break;
        
      default:
        printf("Invalid choice.\n");
        break;
    }
  } while (choice != 3);
  
  return 0;
}