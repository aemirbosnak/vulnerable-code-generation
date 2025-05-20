//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some error messages
#define OOPS "Whoops! It looks like we have a problem here."
#define OOM "Out of memory! Better luck next time."
#define INVALID "Invalid input. Let's try again, shall we?"

int main() {
  // Variables to hold our inputs
  int age;
  char name[50];
  float height;

  // Ask the user for their age
  printf("Hey there! What's your age? ");
  scanf("%d", &age);

  // Check if the user entered a valid age
  if (age < 0 || age > 100) {
    printf(INVALID "Age must be between 0 and 100. Try again!");
    return 1;
  }

  // Ask the user for their name
  printf("What's your name? ");
  fgets(name, 50, stdin);

  // Check if the user entered a valid name
  if (strlen(name) < 1 || strlen(name) > 50) {
    printf(INVALID "Name must be at least 1 character long and no longer than 50 characters. Try again!");
    return 1;
  }

  // Ask the user for their height
  printf("How tall are you? ");
  scanf("%f", &height);

  // Check if the user entered a valid height
  if (height < 0 || height > 300) {
    printf(INVALID "Height must be between 0 and 300. Try again!");
    return 1;
  }

  // If we made it this far without any errors, print a success message
  printf("You're all set! Your age is %d, name is %s, and height is %f.", age, name, height);

  // If we encountered an error, print an error message and exit
  if (age < 0 || age > 100 || strlen(name) < 1 || strlen(name) > 50 || height < 0 || height > 300) {
    printf(OOPS "Something went wrong. Sorry about that!");
    return 2;
  }

  return 0;
}