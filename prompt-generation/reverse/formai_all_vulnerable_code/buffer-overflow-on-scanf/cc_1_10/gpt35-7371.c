//FormAI DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 50 // Maximum number of passwords the program can store
#define MAX_LENGTH 20 // Maximum length of each password

void add_password(char passwords[][MAX_LENGTH + 1], int *num_passwords);
void view_passwords(char passwords[][MAX_LENGTH + 1], int num_passwords);
void remove_password(char passwords[][MAX_LENGTH + 1], int *num_passwords);
void save_passwords(char passwords[][MAX_LENGTH + 1], int num_passwords);
void load_passwords(char passwords[][MAX_LENGTH + 1], int *num_passwords);

int main() {
  char passwords[MAX_PASSWORDS][MAX_LENGTH + 1]; // Array of passwords
  int num_passwords = 0; // Number of passwords currently stored

  load_passwords(passwords, &num_passwords); // Load passwords from file
  
  int choice = 0;

  do {
    printf("\nWelcome to the Password Manager!\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Remove a password\n");
    printf("4. Save passwords to file\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_password(passwords, &num_passwords);
        break;
      case 2:
        view_passwords(passwords, num_passwords);
        break;
      case 3:
        remove_password(passwords, &num_passwords);
        break;
      case 4:
        save_passwords(passwords, num_passwords);
        break;
      case 5:
        printf("Exiting Password Manager...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (choice != 5);

  return 0;
}

// Add a new password to the array
void add_password(char passwords[][MAX_LENGTH + 1], int *num_passwords) {
  if (*num_passwords == MAX_PASSWORDS) {
    printf("Password Manager is full. Cannot add more passwords.\n");
    return;
  }

  char password[MAX_LENGTH + 1];
  printf("Enter password (max length %d): ", MAX_LENGTH);
  scanf("%s", password);

  strncpy(passwords[*num_passwords], password, MAX_LENGTH);
  printf("Password added successfully.\n");

  (*num_passwords)++;
}

// View all passwords in the array
void view_passwords(char passwords[][MAX_LENGTH + 1], int num_passwords) {
  if (num_passwords == 0) {
    printf("No passwords to display.\n");
    return;
  }

  printf("Stored Passwords:\n");
  for (int i = 0; i < num_passwords; i++) {
    printf("%d. %s\n", i+1, passwords[i]);
  }
}

// Remove a password from the array
void remove_password(char passwords[][MAX_LENGTH + 1], int *num_passwords) {
  if (*num_passwords == 0) {
    printf("No passwords to remove.\n");
    return;
  }

  int index = 0;
  printf("Enter index of password to remove: ");
  scanf("%d", &index);

  if (index < 1 || index > *num_passwords) {
    printf("Invalid index. Please try again.\n");
    return;
  }

  // Shift all passwords after the removed password one position to the left
  for (int i = index-1; i < *num_passwords - 1; i++) {
    strncpy(passwords[i], passwords[i+1], MAX_LENGTH);
  }

  (*num_passwords)--;
  printf("Password removed successfully.\n");
}

// Save all passwords in the array to a file
void save_passwords(char passwords[][MAX_LENGTH + 1], int num_passwords) {
  if (num_passwords == 0) {
    printf("No passwords to save.\n");
    return;
  }

  FILE *file = fopen("passwords.txt", "w");
  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  for (int i = 0; i < num_passwords; i++) {
    fprintf(file, "%s\n", passwords[i]);
  }

  fclose(file);
  printf("Passwords saved to file successfully.\n");
}

// Load all passwords from a file into the array
void load_passwords(char passwords[][MAX_LENGTH + 1], int *num_passwords) {
  FILE *file = fopen("passwords.txt", "r");
  if (file == NULL) {
    printf("No saved passwords found.\n");
    return;
  }

  char password[MAX_LENGTH + 1];
  while (fscanf(file, "%s", password) == 1 && *num_passwords < MAX_PASSWORDS) {
    strncpy(passwords[*num_passwords], password, MAX_LENGTH);
    (*num_passwords)++;
  }

  fclose(file);
}