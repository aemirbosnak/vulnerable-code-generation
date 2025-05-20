//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets for password generation
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";
const char symbols[] = "!@#$%^&*()";

// Define the password length and character set as per user
void get_user_input(int *length, char **char_set) {
  printf("Welcome to the Enchanted Password Generator!\n");
  printf("Let's craft a spellbinding password together.\n\n");

  printf("First, tell me, how long shall your password be? (Min: 8, Max: 50): ");
  scanf("%d", length);

  // Validate length input
  while (*length < 8 || *length > 50) {
    printf("Oops! Password length must be between 8 and 50. Try again: ");
    scanf("%d", length);
  }

  printf("\nNow, choose the characters for your password:\n");
  printf("1. Lowercase letters (a, b, c...)\n");
  printf("2. Uppercase letters (A, B, C...)\n");
  printf("3. Digits (0, 1, 2...)\n");
  printf("4. Symbols (!, @, #...)\n");
  printf("5. All of the above\n");

  printf("Enter your choice (1-5): ");
  int choice;
  scanf("%d", &choice);

  // Generate character set based on user choice
  switch (choice) {
    case 1:
      *char_set = lowercase;
      break;
    case 2:
      *char_set = uppercase;
      break;
    case 3:
      *char_set = digits;
      break;
    case 4:
      *char_set = symbols;
      break;
    case 5:
      *char_set = strcat(lowercase, strcat(uppercase, strcat(digits, symbols)));
      break;
    default:
      printf("Invalid choice. Defaulting to all characters.\n");
      *char_set = strcat(lowercase, strcat(uppercase, strcat(digits, symbols)));
  }
}

// Generate a random password using the given character set
char *generate_password(int length, char *char_set) {
  // Initialize random number generator
  srand(time(0));

  char *password = malloc(length + 1); // +1 for null-terminator

  // Generate each character of the password randomly
  for (int i = 0; i < length; i++) {
    int index = rand() % strlen(char_set);
    password[i] = char_set[index];
  }

  password[length] = '\0'; // Null-terminate the password

  return password;
}

// Output the generated password
void display_password(char *password) {
  printf("\nYour enchanted password is: %s\n", password);
  printf("\nMay it protect your digital treasures!\n");
}

int main() {
  int length;
  char *char_set;

  get_user_input(&length, &char_set);
  char *password = generate_password(length, char_set);
  display_password(password);

  free(password);

  return 0;
}