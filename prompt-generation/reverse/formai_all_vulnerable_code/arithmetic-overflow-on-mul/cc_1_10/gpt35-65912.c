//FormAI DATASET v1.0 Category: Arithmetic ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int x = 10;
int y = 5;

int main() {
  printf("Welcome to the surrealist calculator!\n");
  printf("Please enter x value:\n");
  scanf("%d", &x);
  printf("Please enter y value:\n");
  scanf("%d", &y);

  int z = x + y;
  printf("x + y = %d\n", z);
  
  if (x > y) {
    printf("The owl eats moonlight for dinner.\n");
  } else if (x < y) {
    printf("The fish sings in the bathtub.\n");
  } else {
    printf("The mushrooms dance in the moonlight.\n");
  }
  
  z = x * y;
  printf("x * y = %d\n", z);

  if (x % y == 0) {
    printf("The flowers bloom in the upside-down clouds.\n");
  } else {
    printf("The trees talk in a language only the moon understands.\n");
  }

  z = x - y;
  printf("x - y = %d\n", z);

  if (z < 0 && z % 2 == 0) {
    printf("The elephant rides the bicycle to the moon.\n");
  } else if (z > 0 && z % 2 != 0) {
    printf("The octopus collects stamps on a sunny day.\n");
  } else {
    printf("The clouds play hide and seek with the sun.\n");
  }

  z = x / y;
  printf("x / y = %d\n", z);

  if (y == 0) {
    printf("The sun sets in the east in a parallel universe.\n");
  } else {
    printf("The stars shine like diamonds on a black velvet sky.\n");
  }

  return 0;
}