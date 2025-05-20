//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 100

int main() {
  // Ask the user for their name and age
  printf("Hello! What's your name? ");
  char name[MAX_NAME_LENGTH];
  scanf("%s", name);
  int age;
  printf("And how old are you? ");
  scanf("%d", &age);

  // Check for errors
  if (scanf("%s", name) != 1 || scanf("%d", &age) != 1) {
    printf("Oh no! It looks like you didn't enter your name or age correctly. Please try again.\n");
    return 1;
  }

  // Handle age validation
  if (age < 18) {
    printf("You're too young to be using this program! Better luck next time.\n");
    return 2;
  } else if (age > MAX_AGE) {
    printf("You're too old to be using this program! Better luck next time.\n");
    return 3;
  }

  // Handle name validation
  if (strlen(name) > MAX_NAME_LENGTH) {
    printf("Your name is too long! Please try again with a shorter name.\n");
    return 4;
  }

  // Handle invalid input
  if (age == 0 || age == -1) {
    printf("Invalid age! Please enter a positive integer.\n");
    return 5;
  }

  // Everything is good! Print a success message
  printf("Hello, %s! You are %d years old.\n", name, age);

  return 0;
}