//GEMINI-pro DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 100

// Declare the global variables
char password[MAX_PASSWORD_LENGTH];
int password_length;

// Declare the function prototypes
void generate_password();
void save_password();
void load_password();
void display_password();

int main() {
  // Display a welcome message
  printf("Welcome to the Password Manager!\n");

  // Get the user's choice
  int choice;
  printf("What would you like to do?\n");
  printf("1. Generate a password\n");
  printf("2. Save a password\n");
  printf("3. Load a password\n");
  printf("4. Display a password\n");
  scanf("%d", &choice);

  // Call the appropriate function based on the user's choice
  switch (choice) {
    case 1:
      generate_password();
      break;
    case 2:
      save_password();
      break;
    case 3:
      load_password();
      break;
    case 4:
      display_password();
      break;
    default:
      printf("Invalid choice\n");
  }

  // Display a goodbye message
  printf("Thank you for using the Password Manager!\n");

  return 0;
}

void generate_password() {
  // Get the length of the password from the user
  printf("Enter the length of the password: ");
  scanf("%d", &password_length);

  // Generate a random password
  srand(time(NULL));
  for (int i = 0; i < password_length; i++) {
    int random_character = rand() % (126 - 33) + 33;
    password[i] = random_character;
  }

  // Display the generated password
  printf("Your generated password is: %s\n", password);
}

void save_password() {
  // Get the password from the user
  printf("Enter the password: ");
  scanf("%s", password);

  // Save the password to a file
  FILE *file = fopen("password.txt", "w");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }
  fprintf(file, "%s", password);
  fclose(file);

  // Display a success message
  printf("Password saved successfully\n");
}

void load_password() {
  // Get the password from the file
  FILE *file = fopen("password.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }
  fscanf(file, "%s", password);
  fclose(file);

  // Display the loaded password
  printf("Loaded password: %s\n", password);
}

void display_password() {
  // Display the password
  printf("Password: %s\n", password);
}