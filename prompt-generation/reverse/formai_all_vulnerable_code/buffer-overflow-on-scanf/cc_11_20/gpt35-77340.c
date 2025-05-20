//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) {
  // Welcome message
  printf("Hello and welcome to the Happy System Administration Program!\n");

  // Check for correct number of arguments
  if (argc != 2) {
    printf("Error: Please provide a single argument.\n");
    return 1;
  }
  
  // Check if user is happy
  bool happy = false;
  char answer;
  printf("Are you happy today? (Y/N) ");
  scanf(" %c", &answer);
  if (answer == 'Y' || answer == 'y') {
    happy = true;
    printf("Yay! I'm happy to hear that!\n");
  } else if (answer == 'N' || answer == 'n') {
    printf("Oh no! I'm sorry to hear that. Let's try to make your day a little better!\n");
  } else {
    printf("Invalid input. Please try again.\n");
    return 1;
  }
  
  // Determine action based on argument
  char *command = argv[1];
  if (strcmp(command, "smile") == 0) {
    printf(":) ");
    if (happy) {
      printf("It's always a good day for a smile!\n");
    } else {
      printf("Hopefully this puts a smile on your face!\n");
    }
  } else if (strcmp(command, "lighten") == 0) {
    printf("How do you lighten a mood in UNIX? rm -rf /bin/laden\n");
  } else if (strcmp(command, "sing") == 0) {
    printf("La la la la la la!\n");
    if (happy) {
      printf("Sing with me! :)\n");
    } else {
      printf("Maybe singing can help cheer you up! :D\n");
    }
  } else {
    printf("Invalid command. Please try again.\n");
    return 1;
  }

  printf("Thanks for using the Happy System Administration Program! Have a great day!\n");
  return 0;
}