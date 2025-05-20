//FormAI DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Storage for encrypted password
char password[50];

// Function to encrypt the password
void encrypt(char *pw) {
  for (int i = 0; i < strlen(pw); i++) {
    // Shift characters by 3 places to the right
    password[i] = (*(pw + i) + 3);
  }
}

// Function to check if password is correct
int check_password(char *guess) {
  char decrypt[50];

  // Decrypt stored password
  for (int i = 0; i < strlen(password); i++) {
    // Shift characters by 3 places to the left
    decrypt[i] = (*(password + i) - 3);
  }

  // Compare decrypted password with guessed password
  if (strcmp(decrypt, guess) == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  printf("Welcome to Password Manager 5000!\n");

  // Get user's desired password
  char pw[50];
  printf("Please enter your desired password: ");
  scanf("%s", pw);

  // Encrypt and store password
  encrypt(pw);

  // Prompt user for password guess
  printf("Please enter your password: ");
  char guess[50];
  scanf("%s", guess);

  // Check if guess is correct
  if (check_password(guess)) {
    printf("Access granted!\n");
  } else {
    printf("Access denied.\n");
  }

  return 0;
}