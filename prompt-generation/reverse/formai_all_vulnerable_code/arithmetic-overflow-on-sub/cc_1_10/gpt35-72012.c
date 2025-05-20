//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>

// define struct for movie rating
struct MovieRating {
   char title[50], genre[20];
   int year, rating;
};

// function for sorting movie ratings based on year
void sortMoviesByYear(struct MovieRating arr[], int numMovies) {
   int i, j;
   struct MovieRating temp;
   
   for (i = 0; i < numMovies-1; i++) {
      for (j = 0; j < numMovies-i-1; j++) {
         if (arr[j].year > arr[j+1].year) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

// function for sorting movie ratings based on rating
void sortMoviesByRating(struct MovieRating arr[], int numMovies) {
   int i, j;
   struct MovieRating temp;
   
   for (i = 0; i < numMovies-1; i++) {
      for (j = 0; j < numMovies-i-1; j++) {
         if (arr[j].rating < arr[j+1].rating) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
         }
      }
   }
}

int main() {
   int numMovies, i;
   
   // get number of movies from user
   printf("Enter number of movies: ");
   scanf("%d", &numMovies);
   
   // declare array of movie ratings
   struct MovieRating movies[numMovies];
   
   // get details of each movie from user
   for (i = 0; i < numMovies; i++) {
      printf("\nDetails of movie %d:\n", i+1);
      printf("Title: ");
      scanf("%s", &movies[i].title);
      printf("Genre: ");
      scanf("%s", &movies[i].genre);
      printf("Year: ");
      scanf("%d", &movies[i].year);
      printf("Rating: ");
      scanf("%d", &movies[i].rating);
   }
   
   // sort movies based on user preference
   int choice;
   printf("\nHow do you want to sort the movies?\n");
   printf("1. By year\n2. By rating\nEnter choice: ");
   scanf("%d", &choice);
   
   if (choice == 1) {
      sortMoviesByYear(movies, numMovies);
   } else if (choice == 2) {
      sortMoviesByRating(movies, numMovies);
   } else {
      printf("Invalid choice!");
      return 0;
   }
   
   // display sorted movie ratings
   printf("\nSorted movie ratings:\n\n");
   for (i = 0; i < numMovies; i++) {
      printf("Title: %s\n", movies[i].title);
      printf("Genre: %s\n", movies[i].genre);
      printf("Year: %d\n", movies[i].year);
      printf("Rating: %d\n\n", movies[i].rating);
   }
   
   return 0;
}