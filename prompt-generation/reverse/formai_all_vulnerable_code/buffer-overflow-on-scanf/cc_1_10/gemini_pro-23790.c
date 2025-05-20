//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets used for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char special[] = "!@#$%^&*()_+";

// Generate a random number within a range
int random_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a random character from a character set
char random_char(char *charset) {
  return charset[random_range(0, strlen(charset) - 1)];
}

// Generate a password of a given length
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Initialize the password to all zeros
  memset(password, 0, length + 1);

  // Generate a random character for each position in the password
  for (int i = 0; i < length; i++) {
    // Determine the character set to use for this position
    int charset_index = random_range(0, 3);
    char *charset;
    switch (charset_index) {
      case 0:
        charset = lowercase;
        break;
      case 1:
        charset = uppercase;
        break;
      case 2:
        charset = digits;
        break;
      case 3:
        charset = special;
        break;
    }

    // Generate a random character from the selected character set
    char c = random_char(charset);

    // Append the character to the password
    password[i] = c;
  }

  // Return the password
  return password;
}

// Get the length of a password from the user
int get_password_length() {
  // Prompt the user for the password length
  printf("Enter the desired password length (must be between 8 and 32): ");

  // Read the user input
  int length;
  scanf("%d", &length);

  // Validate the user input
  while (length < 8 || length > 32) {
    printf("Invalid password length. Please enter a length between 8 and 32: ");
    scanf("%d", &length);
  }

  // Return the password length
  return length;
}

// Get the number of passwords to generate from the user
int get_num_passwords() {
  // Prompt the user for the number of passwords to generate
  printf("Enter the number of passwords to generate: ");

  // Read the user input
  int num_passwords;
  scanf("%d", &num_passwords);

  // Validate the user input
  while (num_passwords <= 0) {
    printf("Invalid number of passwords. Please enter a positive number: ");
    scanf("%d", &num_passwords);
  }

  // Return the number of passwords
  return num_passwords;
}

// Print the generated passwords to the console
void print_passwords(char **passwords, int num_passwords) {
  // Print a header
  printf("\nGenerated Passwords:\n");

  // Print each password on a separate line
  for (int i = 0; i < num_passwords; i++) {
    printf("%s\n", passwords[i]);
  }

  // Free the allocated memory for the passwords
  for (int i = 0; i < num_passwords; i++) {
    free(passwords[i]);
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the password length from the user
  int length = get_password_length();

  // Get the number of passwords to generate from the user
  int num_passwords = get_num_passwords();

  // Generate the passwords
  char **passwords = malloc(num_passwords * sizeof(char *));
  for (int i = 0; i < num_passwords; i++) {
    passwords[i] = generate_password(length);
  }

  // Print the passwords to the console
  print_passwords(passwords, num_passwords);

  return 0;
}