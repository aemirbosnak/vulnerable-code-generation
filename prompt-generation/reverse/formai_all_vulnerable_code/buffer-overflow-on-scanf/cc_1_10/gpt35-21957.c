//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <string.h>
#define MAX_PASSWORD_LENGTH 50
#define MAX_SAVED_PASSWORDS 100

/* Function to get user input and save it to password array */
void setPassword(char password[][MAX_PASSWORD_LENGTH], int *numPasswords) {
  char input[MAX_PASSWORD_LENGTH];
  printf("Enter your new password: ");
  scanf("%s", input);

  /* Checking if password already exists */
  for (int i = 0; i < *numPasswords; i++) {
    if (strcmp(password[i], input) == 0) {
      printf("Password has already been saved\n");
      return;
    }
  }

  /* Saving password */
  strcpy(password[*numPasswords], input);
  printf("Password has been saved\n");

  /* Incrementing Number of Saved Passwords */
  (*numPasswords)++;
}

/* Function to display saved passwords */
void getPassword(char password[][MAX_PASSWORD_LENGTH], int numPasswords) {
  printf("Your saved passwords are:\n");
  for (int i = 0; i < numPasswords; i++) {
    printf("%d. %s\n", i + 1, password[i]);
  }
}

/* Function to delete a saved password */
void deletePassword(char password[][MAX_PASSWORD_LENGTH], int *numPasswords) {
  char input[MAX_PASSWORD_LENGTH];
  printf("Enter the password you want to delete: ");
  scanf("%s", input);

  /* Searching for password */
  for (int i = 0; i < *numPasswords; i++) {
    if (strcmp(password[i], input) == 0) {

      /* Deleting Password */
      for (int j = i; j < *numPasswords - 1; j++) {
        strcpy(password[j], password[j + 1]);
      }
      (*numPasswords)--;
      printf("Password has been deleted\n");
      return;
    }
  }
  printf("Password not found\n");
}

/* Main program */
int main() {
  char password[MAX_SAVED_PASSWORDS][MAX_PASSWORD_LENGTH];
  int numPasswords = 0;

  int choice;
  do {
    printf("\nPassword Manager\n");
    printf("1. Set Password\n");
    printf("2. Get Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Quit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        setPassword(password, &numPasswords);
        break;
      case 2:
        getPassword(password, numPasswords);
        break;
      case 3:
        deletePassword(password, &numPasswords);
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 4);

  return 0;
}