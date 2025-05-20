//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

struct movie {
   char title[50];
   int rating;
};

int main() {
   struct movie movies[MAX_MOVIES];
   int num_movies = 0;

   while (1) {
      // Print options
      printf("\n--------------------------------------------------\n");
      printf("Welcome to the C Movie Rating System!\n");
      printf("Please select an option below:\n");
      printf("1. Add a movie\n");
      printf("2. Rate a movie\n");
      printf("3. List all movies\n");
      printf("4. Exit system\n\n");

      // Get user input
      int choice;
      printf("Enter choice (1-4): ");
      scanf("%d", &choice);

      switch (choice) {
         case 1: {
            // Add movie
            if (num_movies >= MAX_MOVIES) {
               printf("Error: Maximum number of movies exceeded\n");
               break;
            }

            struct movie new_movie;
            printf("Enter movie title: ");
            scanf("%s", new_movie.title);
            new_movie.rating = -1;

            movies[num_movies++] = new_movie;
            printf("Movie added successfully!\n");
            break;
         }

         case 2: {
            // Rate movie
            if (num_movies == 0) {
               printf("Error: No movies added yet\n");
               break;
            }

            char title[50];
            printf("Enter movie title: ");
            scanf("%s", title);

            int i;
            for (i = 0; i < num_movies; ++i) {
               if (strcmp(movies[i].title, title) == 0) {
                  break;
               }
            }

            if (i == num_movies) {
               printf("Error: Movie not found\n");
               break;
            }

            if (movies[i].rating != -1) {
               printf("Error: Movie already rated\n");
               break;
            }

            int rating;
            printf("Enter rating (1-5): ");
            scanf("%d", &rating);

            if (rating < 1 || rating > 5) {
               printf("Error: Invalid rating\n");
               break;
            }

            movies[i].rating = rating;
            printf("Rating added successfully!\n");
            break;
         }

         case 3: {
            // List movies
            if (num_movies == 0) {
               printf("No movies added yet\n");
               break;
            }

            printf("\n--------------------------------------------------\n");
            printf("Title\t\t\t\tRating\n");
            printf("--------------------------------------------------\n");

            int i;
            for (i = 0; i < num_movies; ++i) {
               printf("%s\t\t\t\t", movies[i].title);

               if (movies[i].rating == -1) {
                  printf("Not rated yet\n");
               } else {
                  int j;
                  for (j = 0; j < movies[i].rating; ++j) {
                     printf("*");
                  }
                  printf("\n");
               }
            }

            printf("--------------------------------------------------\n");
            break;
         }

         case 4: {
            // Exit system
            printf("Thank you for using the C Movie Rating System!\n");
            return 0;
         }

         default: {
            printf("Error: Invalid choice\n");
            break;
         }
      }
   }

   return 0;
}