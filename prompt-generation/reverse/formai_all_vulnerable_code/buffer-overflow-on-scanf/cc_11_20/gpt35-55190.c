//FormAI DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
   int rating;
   printf("Welcome to the Curious C Movie Rating System!\n \n");
   printf("Please rate the following movies from 1 to 10:\n");

   // Movie 1
   printf("Movie 1: The Curious Case of Benjamin Button\n");
   scanf("%d", &rating);
   if(rating >= 9) {
      printf("Wow! You really enjoyed The Curious Case of Benjamin Button! Would you like to watch it again?\n");
   } else if(rating >= 6) {
      printf("You thought The Curious Case of Benjamin Button was pretty good!\n");
   } else {
      printf("It seems like you didn't enjoy The Curious Case of Benjamin Button very much.\n");
   }

   // Movie 2
   printf("\nMovie 2: Inception\n");
   scanf("%d", &rating);
   if(rating >= 9) {
      printf("You loved Inception! Would you like to watch it again?\n");
   } else if(rating >= 6) {
      printf("You enjoyed Inception, but there was room for improvement.\n");
   } else {
      printf("It seems like Inception wasn't your cup of tea.\n");
   }

   // Movie 3
   printf("\nMovie 3: The Curious Incident of the Dog in the Night-Time\n");
   scanf("%d", &rating);
   if(rating >= 9) {
      printf("Wow! You really loved The Curious Incident of the Dog in the Night-Time. Would you recommend it to others?\n");
   } else if(rating >= 6) {
      printf("You thought The Curious Incident of the Dog in the Night-Time was pretty good!\n");
   } else {
      printf("It seems like The Curious Incident of the Dog in the Night-Time wasn't your cup of tea.\n");
   }

   // Movie 4
   printf("\nMovie 4: The Curious Case of Forrest Gump\n");
   scanf("%d", &rating);
   if(rating >= 9) {
      printf("It looks like you really enjoyed The Curious Case of Forrest Gump. Would you like to watch it again?\n");
   } else if(rating >= 6) {
      printf("You thought The Curious Case of Forrest Gump was pretty good, but there was room for improvement.\n");
   } else {
      printf("It seems like The Curious Case of Forrest Gump wasn't for you.\n");
   }

   // Movie 5
   printf("\nMovie 5: The Curious Tale of Rapunzel\n");
   scanf("%d", &rating);
   if(rating >= 9) {
      printf("You loved The Curious Tale of Rapunzel! Would you recommend it to others?\n");
   } else if(rating >= 6) {
      printf("You enjoyed The Curious Tale of Rapunzel, but there was room for improvement.\n");
   } else {
      printf("It seems like The Curious Tale of Rapunzel didn't quite meet your expectations.\n");
   }

   printf("\nThanks for using the Curious C Movie Rating System! We hope to see you soon for another round of movie ratings!\n");

   return 0;
}