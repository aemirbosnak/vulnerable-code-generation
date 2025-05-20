//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a secure random password
char* generatePassword(int length) {
  char* password = (char*) malloc((length + 1) * sizeof(char));
  const char lowerLetters[] = "abcdefghijklmnopqrstuvwxyz";
  const char upperLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char numbers[] = "0123456789";
  const char symbols[] = "!@#$%^&*()_-+={}[]\\|:;\"'<>,.?/";

  // Generate a random seed based on time
  srand(time(NULL));

  // Loop through the length of the password
  for(int i = 0; i < length; i++) {
    int category = rand() % 4; // Generate a random number between 0 and 3
    if(category == 0) { // Lowercase letters
      int index = rand() % strlen(lowerLetters);
      password[i] = lowerLetters[index];
    } else if(category == 1) { // Uppercase letters
      int index = rand() % strlen(upperLetters);
      password[i] = upperLetters[index];
    } else if(category == 2) { // Numbers
      int index = rand() % strlen(numbers);
      password[i] = numbers[index];
    } else if(category == 3) { // Symbols
      int index = rand() % strlen(symbols);
      password[i] = symbols[index];
    }
  }
  password[length] = '\0'; // Add null character to the end of the password
  return password;
}

int main() {
  printf("Welcome to the Secure Password Generator!\n");
  printf("Enter the length of your desired password: ");
  int length;
  scanf("%d", &length);
  // Make sure length is at least 8 characters
  if(length < 8) {
    printf("Error: Password must be at least 8 characters long.\n");
    return 1;
  }
  char* password = generatePassword(length);
  printf("Your secure password is: %s\n", password);
  free(password); // Free memory allocated for password
  return 0;
}