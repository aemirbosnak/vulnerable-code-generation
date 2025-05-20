//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Global variables
int errCount = 0;
const char* errMessages[5] = {"Oops!", "Whoops!", "Oy vey!", "Oh no!", "Uh oh!"};

void validateName(char* name) {
  // Check if the name is too long
  if (strlen(name) > MAX_NAME_LENGTH) {
    errCount++;
    printf("Error: Name too long! (%d)\n", errCount);
    return;
  }

  // Check if the name contains invalid characters
  if (strpbrk(name, "?*") != NULL) {
    errCount++;
    printf("Error: Name contains invalid characters! (%d)\n", errCount);
    return;
  }

  // Check if the name is already in use
  if (strcmp(name, "Alice") == 0 || strcmp(name, "Bob") == 0 || strcmp(name, "Charlie") == 0) {
    errCount++;
    printf("Error: Name already in use! (%d)\n", errCount);
    return;
  }
}

void validateAge(int age) {
  // Check if the age is too low
  if (age < 18) {
    errCount++;
    printf("Error: You must be at least 18 years old! (%d)\n", errCount);
    return;
  }

  // Check if the age is too high
  if (age > MAX_AGE) {
    errCount++;
    printf("Error: You are too old! (%d)\n", errCount);
    return;
  }
}

int main() {
  char name[MAX_NAME_LENGTH];
  int age;

  // Ask the user for their name and age
  printf("What is your name? ");
  fgets(name, MAX_NAME_LENGTH, stdin);
  printf("How old are you? ");
  scanf("%d", &age);

  // Validate the name and age
  validateName(name);
  validateAge(age);

  // If there are no errors, print a success message
  if (errCount == 0) {
    printf("Success! You have provided valid information.\n");
  }

  return errCount;
}