//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include<stdio.h>

//defining the structure for each movie
struct movie {
   char title[50];
   char director[50];
   float rating;
};

//function to display menu
void displayMenu() {
   printf("\n\t***** Movie Rating System *****");
   printf("\n\t1. Add movie");
   printf("\n\t2. Display all movies");
   printf("\n\t3. Update a movie rating");
   printf("\n\t4. Exit");
   printf("\n\tEnter your choice (1-4): ");
}

//function to add a movie
int addMovie(struct movie movies[], int count) {
   printf("\nEnter movie title: ");
   scanf("%s", movies[count].title);
   printf("Enter director name: ");
   scanf("%s", movies[count].director);
   printf("Enter rating (out of 10): ");
   scanf("%f", &movies[count].rating);
   return ++count;
}

//function to display all the movies and their details
void displayMovies(struct movie movies[], int count) {
   printf("\n\t***** List of the Movies *****\n");
   printf("\n\tTITLE\t\tDIRECTOR\tRATING\n");
   for(int i = 0; i < count; i++) {
      printf("\n\t%s\t%s\t%.1f/10", movies[i].title, movies[i].director, movies[i].rating);
   }
}

//function to update the rating of a movie
void updateRating(struct movie movies[], int count) {
   char search[50];
   printf("\nEnter the title of the movie whose rating is to be updated: ");
   scanf("%s", search);
   for(int i = 0; i < count; i++) {
      if(strcmp(search, movies[i].title) == 0) {
         printf("Enter the new rating for %s: ", movies[i].title);
         scanf("%f", &movies[i].rating);
         printf("\nRating updated successfully!\n");
         return;
      }
   }
   printf("\nMovie not found. Try again!\n");
}

int main() {
   struct movie movies[100];
   int choice, count = 0;

   displayMenu();
   scanf("%d", &choice);

   while(choice != 4) {
      switch(choice) {
         case 1:
            if(count == 100) {
               printf("\nMovie database full! Can't add more movies.\n");
            } else {
               count = addMovie(movies, count);
               printf("\nMovie added successfully!\n");
            }
            break;
         case 2:
            if(count == 0) {
               printf("\nNo movies in the database! Add some movies first.\n");
            } else {
               displayMovies(movies, count);
            }
            break;
         case 3:
            if(count == 0) {
               printf("\nNo movies in the database! Add some movies first.\n");
            } else {
               updateRating(movies, count);
            }
            break;
         default:
            printf("\nInvalid choice. Try again.\n");
      }
      displayMenu();
      scanf("%d", &choice);
   }

   printf("\n***** Thank you for using Movie Rating System! *****\n");
   return 0;
}