//FormAI DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of users and their maximum username length
#define MAX_USERS 20
#define MAX_USERNAME_LEN 10

// Define the maximum number of files and their maximum filename length
#define MAX_FILES 50
#define MAX_FILENAME_LEN 20

// Declare the global arrays to store user and file information
char users[MAX_USERS][MAX_USERNAME_LEN];
char files[MAX_FILES][MAX_FILENAME_LEN];
int num_users = 0;
int num_files = 0;

// Function to add a new user to the system
void add_user() {
  char username[MAX_USERNAME_LEN];
  printf("Enter a new username: ");
  scanf("%s", username);

  if (num_users >= MAX_USERS) {
    printf("Error: Maximum number of users reached\n");
    return;
  }

  // Check if the username already exists in the system
  for (int i = 0; i < num_users; i++) {
    if (strcmp(users[i], username) == 0) {
      printf("Error: Username already exists\n");
      return;
    }
  }

  // Add the new user to the system
  strcpy(users[num_users], username);
  num_users++;
}

// Function to delete a user from the system
void delete_user() {
  char username[MAX_USERNAME_LEN];
  printf("Enter the username to delete: ");
  scanf("%s", username);

  int found_user = 0;
  for (int i = 0; i < num_users; i++) {
    if (strcmp(users[i], username) == 0) {
      found_user = 1;

      // Remove the user by shifting the remaining users back in the array
      for (int j = i; j < num_users - 1; j++) {
        strcpy(users[j], users[j+1]);
      }
      num_users--;

      // Remove any files owned by the deleted user
      for (int j = 0; j < num_files; j++) {
        if (strcmp(files[j], username) == 0) {
          // Remove the file by shifting the remaining files back in the array
          for (int k = j; k < num_files - 1; k++) {
            strcpy(files[k], files[k+1]);
          }
          num_files--;
          j--; // Decrement j to avoid skipping the next file after the current one is deleted
        }
      }

      printf("User deleted successfully\n");
      break;
    }
  }

  if (!found_user) {
    printf("Error: User not found\n");
  }
}

// Function to add a new file to the system
void add_file() {
  char filename[MAX_FILENAME_LEN];
  char username[MAX_USERNAME_LEN];

  printf("Enter the name of the file: ");
  scanf("%s", filename);
  printf("Enter the name of the owner: ");
  scanf("%s", username);

  // Check if the owner exists in the system
  int owner_found = 0;
  for (int i = 0; i < num_users; i++) {
    if (strcmp(users[i], username) == 0) {
      owner_found = 1;
      break;
    }
  }

  if (!owner_found) {
    printf("Error: User not found\n");
    return;
  }

  if (num_files >= MAX_FILES) {
    printf("Error: Maximum number of files reached\n");
    return;
  }

  // Add the new file to the system
  strcpy(files[num_files], filename);
  num_files++;
}

// Function to delete a file from the system
void delete_file() {
  char filename[MAX_FILENAME_LEN];
  printf("Enter the name of the file to delete: ");
  scanf("%s", filename);

  int found_file = 0;
  for (int i = 0; i < num_files; i++) {
    if (strcmp(files[i], filename) == 0) {
      found_file = 1;

      // Remove the file by shifting the remaining files back in the array
      for (int j = i; j < num_files - 1; j++) {
        strcpy(files[j], files[j+1]);
      }
      num_files--;

      printf("File deleted successfully\n");
      break;
    }
  }

  if (!found_file) {
    printf("Error: File not found\n");
  }
}

// Function to print the list of users and their files
void print_users_and_files() {
  for (int i = 0; i < num_users; i++) {
    printf("User %d: %s\n", i+1, users[i]);

    int files_found = 0;
    for (int j = 0; j < num_files; j++) {
      if (strcmp(files[j], users[i]) == 0) {
        printf("  - %s\n", files[j]);
        files_found = 1;
      }
    }

    if (!files_found) {
      printf("  - No files\n");
    }
  }
}

int main() {
  printf("Welcome to the Retro File System Administration Program!\n");

  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Add a new user\n");
    printf("2. Delete a user\n");
    printf("3. Add a new file\n");
    printf("4. Delete a file\n");
    printf("5. Print the list of users and their files\n");
    printf("6. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_user();
        break;
      case 2:
        delete_user();
        break;
      case 3:
        add_file();
        break;
      case 4:
        delete_file();
        break;
      case 5:
        print_users_and_files();
        break;
      case 6:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}