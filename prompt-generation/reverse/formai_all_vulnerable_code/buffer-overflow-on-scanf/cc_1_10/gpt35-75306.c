//FormAI DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
   //Declare variables
   int rating, totalRatings = 0, count = 0;
   float avgRating;

   //Start program
   printf("===============================\n");
   printf("Welcome to the C Movie Rating System\n");
   printf("===============================\n");

   //Ask for user input
   printf("How many ratings would you like to enter?\n");
   scanf("%d", &totalRatings);

   //Check that totalRatings is >0
   if (totalRatings <= 0) {
      printf("Invalid input. Please enter a positive number.\n");
      exit(0);
   }

   //Loop to add all movie ratings
   printf("Please enter movie ratings (1-10):\n");
   for (int i = 0; i < totalRatings; i++) {
      scanf("%d", &rating);

      //Check that rating is between 1 and 10
      if (rating < 1 || rating > 10) {
         printf("Invalid input. Please enter a number between 1 and 10.\n");
         i--;
         continue;
      }

      //Add rating to total and increment count
      count++;
      avgRating += (float)rating;
   }

   //Calculate average rating
   avgRating /= count;

   printf("\n===============================\n");
   printf("C Movie Rating System Results\n");
   printf("===============================\n");

   printf("Number of Ratings: %d\n", totalRatings);
   printf("Average Rating: %.2f\n", avgRating);

   //Print rating level based on average rating
   if (avgRating >= 9.0) {
      printf("Rating Level: Outstanding!\n");
   } else if (avgRating >= 8.0) {
      printf("Rating Level: Great!\n");
   } else if (avgRating >= 7.0) {
      printf("Rating Level: Good!\n");
   } else if (avgRating >= 6.0) {
      printf("Rating Level: Fair!\n");
   } else if (avgRating >= 5.0) {
      printf("Rating Level: Poor!\n");
   } else {
      printf("Rating Level: Terrible!\n");
   }

   //End program
   printf("\nThank you for using the C Movie Rating System!\n");
   printf("===============================\n");

   return 0;
}