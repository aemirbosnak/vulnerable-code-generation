//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

int main() {
  // Declare variables
  int age;
  char name[MAX_NAME_LENGTH];
  int numTimes;

  // Get the user's name and age
  printf("What is your name? ");
  fgets(name, MAX_NAME_LENGTH, stdin);
  age = get_age();

  // Check for invalid input
  if (age < 0 || age > MAX_AGE) {
    printf("Invalid age! Please enter a positive integer less than or equal to %d.\n", MAX_AGE);
    return 1;
  }

  // Generate a random number between 1 and 10
  numTimes = (int)(rand() % 10 + 1);

  // Print the result
  printf("You have been alive for %d years!\n", age);

  // Handle errors
  if (numTimes < 0) {
    printf("Whoa, that's not possible! You've been alive for negative years?! 😱\n");
  } else if (numTimes == 0) {
    printf("Hmm, that's not right. You've been alive for zero years?! 🤔\n");
  } else {
    printf("Wow, you've been alive for %d years! 🎉\n", numTimes);
  }

  return 0;
}

// Get the user's age
int get_age() {
  // Prompt the user for their age
  printf("Enter your age: ");

  // Read the user's input
  int age;
  scanf("%d", &age);

  // Check for invalid input
  if (age < 0 || age > MAX_AGE) {
    printf("Invalid age! Please enter a positive integer less than or equal to %d.\n", MAX_AGE);
    return -1;
  }

  return age;
}