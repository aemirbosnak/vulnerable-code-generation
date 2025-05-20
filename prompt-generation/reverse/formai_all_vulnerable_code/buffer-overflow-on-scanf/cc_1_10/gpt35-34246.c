//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  printf("Welcome to the Resume Parser 3000! Let's get started.\n");
  printf("WARNING: This program may cause uncontrollable laughter.\n\n");

  char resume[1000];
  printf("Please enter your resume: ");
  fgets(resume, 1000, stdin);

  char* name = strtok(resume, " ");
  printf("Name: %s\n", name);

  char* contact = strtok(NULL, " ");
  printf("Contact Info: %s\n", contact);

  char* education = strtok(NULL, " ");
  printf("Education: %s\n", education);

  char* skills = strtok(NULL, " ");
  printf("Skills: %s\n", skills);

  char* experience = strtok(NULL, " ");
  printf("Experience: %s\n", experience);

  printf("\nCongratulations, your resume has been parsed! But wait, there's more...\n");

  printf("Would you like some more laughs? (y/n): ");
  char input;
  scanf("%c", &input);

  if (input == 'y' || input == 'Y') {
    printf("\nKnock, knock.\n");
    printf("Who's there?\n");
    printf("An interrupting programmer.\n");
    printf("Interrup-\n");
    printf("ERROR: PROGRAM CRASHED\n");
  } 
  else if (input == 'n' || input == 'N') {
    printf("\nAlright then, thanks for using Resume Parser 3000. Goodbye!\n");
  } 
  else {
    printf("\nInvalid input. Goodbye!\n");
  }

  return 0;
}