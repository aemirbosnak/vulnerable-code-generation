//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
  int x, y, z;
  char magic_password[10];
  float result;

  // generate a random magic password
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    magic_password[i] = 'A' + (rand() % 26);
  }

  // prompt the user for inputs
  printf("Enter two numbers: ");
  scanf("%d%d", &x, &y);

  // perform some arbitrary arithmetic operations
  z = x * y + MAGIC_NUMBER;
  result = (float)z / (y + 10);

  // check if the result is within a certain range
  if (result < 2.5 || result > 4.5) {
    printf("Oops, that's not correct! Try again.\n");
    return 1;
  }

  // display the result
  printf("The result of %d x %d is %f\n", x, y, result);

  // ask the user for their name
  printf("What's your name? ");
  fgets(magic_password, 10, stdin);

  // check if the name is valid
  if (strcmp(magic_password, "Ken") != 0 && strcmp(magic_password, "Roberts") != 0) {
    printf("Sorry, only Ken and Roberts are allowed to use this program.\n");
    return 2;
  }

  // display the final result
  printf("Well done, %s! You got it right.\n", magic_password);

  return 0;
}