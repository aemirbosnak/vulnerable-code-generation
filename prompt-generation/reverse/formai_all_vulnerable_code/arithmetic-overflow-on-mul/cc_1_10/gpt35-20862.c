//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the Funniest C Performance-Critical Component Example Program!\n");
  printf("Let's see if we can't make this critical component a little more fun.\n");
  printf("First, we'll need to generate some random numbers...\n");

  int num1 = 42;
  int num2 = 69;
  int num3 = 420;

  printf("Generated some random numbers: %d %d %d\n", num1, num2, num3);

  printf("Now let's do some performance-critical stuff!\n");

  for (int i = 0; i < 1000000; i++) {
    int result = num1 * num2 - num3;
    num1 = num2;
    num2 = num3;
    num3 = result;
  }

  printf("Wow, we just did a million calculations in record time!\n");
  printf("But we're not done yet, let's add some user interaction...\n");

  char name[20];
  printf("What's your name? ");
  scanf("%s", name);

  printf("Hello, %s! Would you like to see some more calculations? (y/n) ", name);

  char choice;
  scanf(" %c", &choice);

  if (choice == 'y') {
    printf("Alright, let's do another million calculations!\n");

    for (int i = 0; i < 1000000; i++) {
      int result = num1 * num2 - num3;
      num1 = num2;
      num2 = num3;
      num3 = result;
    }

    printf("Phew! That was intense. But we made it through together, %s.\n", name);
  } else if (choice == 'n') {
    printf("No problem, %s. It was still great working with you today!\n", name);
  } else {
    printf("Sorry, %s. I didn't understand your input. But thanks for trying!\n", name);
  }

  return 0;
}