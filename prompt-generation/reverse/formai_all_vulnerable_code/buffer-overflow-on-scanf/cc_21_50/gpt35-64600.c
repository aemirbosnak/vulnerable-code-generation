//FormAI DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>

// function to calculate the movie rating
int calculateRating(int age, int violence, int sex, int language) {
   int rating = 0;
   // check age category
   if(age >= 0 && age <= 5) {
      rating = 0;
   } else if (age >= 6 && age <= 8) {
      rating = 1;
   } else if (age >= 9 && age <= 11) {
      rating = 2;
   } else if (age >= 12 && age <= 14) {
      rating = 3;
   } else if (age >= 15 && age <= 17) {
      rating = 4;
   } else if (age >= 18) {
      rating = 5;
   }
   // check for violence
   if(violence > 0) {
      rating += 1;
   }
   // check for sex
   if(sex > 0) {
      rating += 1;
   }
   // check for language
   if(language > 0) {
      rating += 1;
   }
   return rating;
}

// main function
int main() {
   int age, violence, sex, language;
   int rating;
   printf("Enter the age of viewer (0 - 100): ");
   scanf("%d", &age);
   printf("Enter the level of violence in the movie (0 - 5): ");
   scanf("%d", &violence);
   printf("Enter the level of sex in the movie (0 - 5): ");
   scanf("%d", &sex);
   printf("Enter the level of language in the movie (0 - 5): ");
   scanf("%d", &language);
   
   rating = calculateRating(age, violence, sex, language);
   
   printf("The movie rating is: %d\n", rating);
   
   // display the reasons for the rating
   switch(rating) {
      case 0:
         printf("The movie is suitable for kids below 6 years.\n");
         break;
      case 1:
         printf("The movie is suitable for kids below 9 years.\n");
         break;
      case 2:
         printf("The movie is suitable for kids below 12 years.\n");
         break;
      case 3:
         printf("The movie is suitable for kids below 15 years.\n");
         break;
      case 4:
         printf("The movie is suitable for kids below 18 years.\n");
         break;
      case 5:
         printf("The movie is suitable for adults only.\n");
         break;
   }

   // suggest rating change based on viewer age
   if (age < 6 && rating > 0) {
      printf("Suggested rating for kids below 6 years: %d\n", rating-1);
   } else if (age >= 6 && age < 9 && (rating != 1 && rating != 0)) {
      printf("Suggested rating for kids below 9 years: %d\n", rating-1);
   } else if (age >= 9 && age < 12 && (rating != 2 && rating != 1 && rating != 0)) {
      printf("Suggested rating for kids below 12 years: %d\n", rating-1);
   } else if (age >= 12 && age < 15 && (rating != 3 && rating != 2 && rating != 1 && rating != 0)) {
      printf("Suggested rating for kids below 15 years: %d\n", rating-1);
   } else if (age >= 15 && age < 18 && (rating != 4 && rating != 3 && rating != 2 && rating != 1 && rating != 0)) {
      printf("Suggested rating for kids below 18 years: %d\n", rating-1);
   } else if (age >= 18 && rating < 5) {
      printf("Suggested rating for adults: %d\n", rating+1);
   }
   return 0;
}