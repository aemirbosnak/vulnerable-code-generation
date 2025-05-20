//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 100

int main() {
  // Declare variables to store user input
  char name[MAX_NAME_LENGTH];
  int age;

  // Print a happy message
  printf("Welcome to the Happy Land! \n");

  // Ask the user for their name
  printf("What's your name? ");
  fgets(name, MAX_NAME_LENGTH, stdin);

  // Check if the name is too long
  if (strlen(name) > MAX_NAME_LENGTH) {
    printf("Oops, your name is too long! Let's try again. \n");
    return 1;
  }

  // Ask the user for their age
  printf("How old are you? ");
  scanf("%d", &age);

  // Check if the age is too high
  if (age > MAX_AGE) {
    printf("Hey, you're too old for this place! Better go back to your age group. \n");
    return 1;
  }

  // Print a happy message based on the user's age
  if (age < 20) {
    printf("Wow, you're so young and full of energy! Enjoy your time here! \n");
  } else if (age < 50) {
    printf("Awesome, you're in the prime of your life! Make the most of it! \n");
  } else {
    printf("Hey, you're getting up there! But that's okay, we love you anyway! \n");
  }

  // Print a happy message based on the user's name
  if (strcmp(name, "Happy") == 0) {
    printf("Hey, Happy! You're in the right place! \n");
  } else if (strcmp(name, "Jim") == 0) {
    printf("Hey, Jim! You're a cool dude! \n");
  } else {
    printf("Hey, %s! You're a unique snowflake! \n", name);
  }

  // Print a happy message to end the program
  printf("Thanks for stopping by! Have a fantastic day! \n");

  return 0;
}