//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the rating system
#define G "G"
#define PG "PG"
#define PG13 "PG-13"
#define R "R"
#define NC17 "NC-17"

// Define the movie ratings
#define ROMEO_AND_JULIET G

// Get the user's age
int getAge() {
  int age;
  printf("How old are you? ");
  scanf("%d", &age);
  return age;
}

// Get the movie's rating
char* getRating(int age) {
  if (age < 13) {
    return G;
  } else if (age < 17) {
    return PG13;
  } else {
    return R;
  }
}

// Print the movie's rating
void printRating(char* rating) {
  printf("The movie is rated %s.\n", rating);
}

// Main function
int main() {
  // Get the user's age
  int age = getAge();
  
  // Get the movie's rating
  char* rating = getRating(age);
  
  // Print the movie's rating
  printRating(rating);
  
  return 0;
}