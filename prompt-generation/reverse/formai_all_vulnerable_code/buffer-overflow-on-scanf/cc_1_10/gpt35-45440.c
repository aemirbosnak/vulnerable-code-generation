//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 50
#define MAX_LENGTH 20

char passwords[MAX_PASSWORDS][MAX_LENGTH];

void printMenu() {
  printf("\n==================================\n");
  printf("Password Management Menu:\n");
  printf("1. Add new password\n");
  printf("2. View all passwords\n");
  printf("3. Search password\n");
  printf("4. Exit\n");
  printf("Enter your choice (1-4): ");
}

void addPassword() {
  printf("Enter new password: ");
  char newPass[MAX_LENGTH];
  scanf("%s", newPass);
  if (strlen(newPass) > MAX_LENGTH) {
    printf("Password is too long!\n");
    return;
  }
  int i;
  for (i = 0; i < MAX_PASSWORDS; i++) {
    if (strcmp(passwords[i], "") == 0) {
      strcpy(passwords[i], newPass);
      printf("Password added successfully!\n");
      return;
    }
  }
  printf("Unable to add password: password storage is full!\n");
}

void viewPasswords() {
  printf("Stored passwords:\n");
  int i;
  for (i = 0; i < MAX_PASSWORDS; i++) {
    if (strcmp(passwords[i], "") != 0) {
      printf("%s\n", passwords[i]);
    }
  }
}

void searchPassword() {
  printf("Enter password to search: ");
  char searchPass[MAX_LENGTH];
  scanf("%s", searchPass);
  int i;
  for (i = 0; i < MAX_PASSWORDS; i++) {
    if (strcmp(passwords[i], searchPass) == 0) {
      printf("Password found!\n");
      return;
    }
  }
  printf("Password not found.\n");
}

int main() {
  int choice = 0;
  while (choice != 4) {
    printMenu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addPassword();
        break;
      case 2:
        viewPasswords();
        break;
      case 3:
        searchPassword();
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }
  return 0;
}