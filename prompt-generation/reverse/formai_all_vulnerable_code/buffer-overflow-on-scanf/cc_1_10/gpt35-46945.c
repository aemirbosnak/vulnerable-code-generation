//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 42;
  int y = 84;

  // Bitwise XOR operation
  int z = x ^ y;

  printf("What's the value of z? Enter your answer: ");
  int answer;
  scanf("%d", &answer);

  if (answer != z) {
    printf("Wrong answer! You failed to solve the puzzle!\n");
    exit(0);
  }

  printf("Congratulations! You have passed the first level of the puzzle!\n");
  printf("Now let's move on to the next level.\n\n");

  int a = x << 2;
  int b = y >> 2;

  int c = a & b;

  printf("What's the value of c? Enter your answer: ");
  scanf("%d", &answer);

  if (answer != c) {
    printf("Wrong answer! You failed to solve the puzzle!\n");
    exit(0);
  }

  printf("Congratulations! You have passed the second level of the puzzle!\n");
  printf("Let's see if you can solve the final level.\n\n");

  int d = ~x;
  int e = ~y;

  int f = d | e;

  printf("What's the value of f? Enter your answer: ");
  scanf("%d", &answer);

  if (answer != f) {
    printf("Wrong answer! You failed to solve the puzzle!\n");
    exit(0);
  }

  printf("Congratulations! You have solved all the puzzles!\n");
  printf("You are a true champion of bitwise operations!\n");

  return 0;
}