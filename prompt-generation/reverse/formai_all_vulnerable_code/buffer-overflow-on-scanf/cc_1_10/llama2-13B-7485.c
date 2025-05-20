//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to print a brave knight's battle cry
void shout_bravely(int level) {
  if (level == 1) {
    printf("Booya!");
  } else if (level == 2) {
    printf("Boo-yah!");
  } else if (level == 3) {
    printf("BOO-YAH-YAH!");
  } else {
    printf("Boo-yah-yah-yah!");
  }
}

// Function to calculate the factorial of a given number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int level, choice;

  // Ask the user to choose a level of bravery
  printf("Choose a level of bravery (1-3): ");
  scanf("%d", &level);

  // Ask the user to choose an operation (1=factorial, 2=shout, 3=quit)
  printf("Choose an operation (1=factorial, 2=shout, 3=quit): ");
  scanf("%d", &choice);

  // Perform the chosen operation
  switch (choice) {
    case 1:
      printf("The factorial of 5 is %d\n", factorial(5));
      break;
    case 2:
      shout_bravely(level);
      break;
    case 3:
      printf("Brave knight has quit the battlefield\n");
      break;
    default:
      printf("Invalid operation choice\n");
      break;
  }

  return 0;
}