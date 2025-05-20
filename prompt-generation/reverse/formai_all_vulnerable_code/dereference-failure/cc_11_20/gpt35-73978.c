//FormAI DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Mailing List Manager! I'm so excited to help you manage your list. Let's get started!\n");

  // Creating array to track emails
  char *emails[100];
  int num_emails = 0;

  // Creating user input buffer
  char input[50];

  // Main loop
  while(1) {
    printf("Please select an option:\n");
    printf("1. Add email\n");
    printf("2. Remove email\n");
    printf("3. Print all emails\n");
    printf("4. Exit\n");
    printf(">> ");
    fgets(input, 50, stdin);

    if (strcmp(input, "1\n") == 0) {
      // Add email case
      printf("Enter email address: ");
      fgets(input, 50, stdin);

      // Removing newline character from input
      strtok(input, "\n");

      // Checking if email is already in the list
      int in_list = 0;
      for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i], input) == 0) {
          printf("This email is already in the list!\n");
          in_list = 1;
          break;
        }
      }

      if (!in_list) {
        // Adding email to list
        emails[num_emails] = malloc(strlen(input)+1);
        strcpy(emails[num_emails], input);
        num_emails++;
        printf("Email added successfully!\n");
      }
    } else if (strcmp(input, "2\n") == 0) {
      // Remove email case
      printf("Enter email address: ");
      fgets(input, 50, stdin);

      // Removing newline character from input
      strtok(input, "\n");

      // Checking if email is in the list
      int in_list = 0;
      for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i], input) == 0) {
          // Moving all elements after i back one element
          for (int j = i; j < num_emails-1; j++) {
            emails[j] = emails[j+1];
          }
          num_emails--;
          printf("Email removed successfully!\n");
          in_list = 1;
          break;
        }
      }

      if (!in_list) {
        printf("This email is not in the list!\n");
      }
    } else if (strcmp(input, "3\n") == 0) {
      // Print all emails case
      printf("Current Mailing List:\n");
      for (int i = 0; i < num_emails; i++) {
        printf("%s\n", emails[i]);
      }
    } else if (strcmp(input, "4\n") == 0) {
      // Exit case
      printf("Thank you for using the Mailing List Manager. Goodbye!\n");
      break;
    } else {
      printf("Invalid option. Please enter a number 1-4.\n");
    }
  }

  // Freeing email arrays
  for (int i = 0; i < num_emails; i++) {
    free(emails[i]);
  }

  return 0;
}