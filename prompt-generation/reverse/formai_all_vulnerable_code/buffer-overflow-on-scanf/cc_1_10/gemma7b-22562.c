//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Define the C Movie Rating System (CMRS)
  int cmrs_rating(int age, char gender, char genre);

  // Get the user's age, gender, and genre preferences
  int age;
  printf("Please enter your age: ");
  scanf("%d", &age);

  char gender;
  printf("Please select your gender (M/F): ");
  scanf(" %c", &gender);

  char genre;
  printf("Please select your preferred genre (A/C/F/S): ");
  scanf(" %c", &genre);

  // Calculate the CMRS rating
  int rating = cmrs_rating(age, gender, genre);

  // Display the rating
  printf("Your CMRS rating is: %d", rating);

  return 0;
}

int cmrs_rating(int age, char gender, char genre) {

  // Calculate the base rating
  int base_rating = 0;

  // Add points for age
  if (age >= 18) {
    base_rating++;
  }

  // Add points for gender
  if (gender == 'M') {
    base_rating++;
  }

  // Add points for genre
  switch (genre) {
    case 'A':
      base_rating++;
      break;
    case 'C':
      base_rating++;
      break;
    case 'F':
      base_rating++;
      break;
    case 'S':
      base_rating++;
      break;
  }

  // Adjust the base rating for special factors
  if (age < 18 && gender == 'F') {
    base_rating--;
  }

  // Return the final rating
  return base_rating;
}