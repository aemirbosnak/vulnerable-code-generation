//FormAI DATASET v1.0 Category: Movie Rating System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
   int rating;
   printf("Welcome to the C Movie Rating System!\n");
   printf("Please rate the following movies:\n");

   // Movie 1
   printf("\nMovie 1: The Dark Knight\n");
   printf("Enter your rating from 0 to 10: ");
   scanf("%d", &rating);
   if(rating >= 0 && rating <= 10) {
      printf("Your rating for The Dark Knight is %d\n", rating);
   } else {
      printf("Invalid rating!\n");
   }

   // Movie 2
   printf("\nMovie 2: Pulp Fiction\n");
   printf("Enter your rating from 0 to 10: ");
   scanf("%d", &rating);
   if(rating >= 0 && rating <= 10) {
      printf("Your rating for Pulp Fiction is %d\n", rating);
   } else {
      printf("Invalid rating!\n");
   }

   // Movie 3
   printf("\nMovie 3: Forrest Gump\n");
   printf("Enter your rating from 0 to 10: ");
   scanf("%d", &rating);
   if(rating >= 0 && rating <= 10) {
      printf("Your rating for Forrest Gump is %d\n", rating);
   } else {
      printf("Invalid rating!\n");
   }

   // Movie 4
   printf("\nMovie 4: The Shawshank Redemption\n");
   printf("Enter your rating from 0 to 10: ");
   scanf("%d", &rating);
   if(rating >= 0 && rating <= 10) {
      printf("Your rating for The Shawshank Redemption is %d\n", rating);
   } else {
      printf("Invalid rating!\n");
   }

   printf("\nThank you for rating these movies!\n");

   return 0;
}