//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum and maximum password lengths
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

// Define the character classes that the password must contain
#define NUM_CHAR_CLASSES 4
char char_classes[NUM_CHAR_CLASSES] = {'a', 'A', '0', '!'};

// Define the weight for each character class
#define CHAR_CLASS_WEIGHT 1

// Define the total weight for the password
#define TOTAL_WEIGHT (NUM_CHAR_CLASSES * CHAR_CLASS_WEIGHT)

// Function to check if the password is valid
int is_password_valid(const char *password) {
  // Check if the password is long enough
  if (strlen(password) < MIN_PASSWORD_LENGTH) {
    return 0;
  }

  // Check if the password is not too long
  if (strlen(password) > MAX_PASSWORD_LENGTH) {
    return 0;
  }

  // Check if the password contains at least one character from each character class
  int char_class_count[NUM_CHAR_CLASSES];
  memset(char_class_count, 0, sizeof(char_class_count));
  for (int i = 0; i < strlen(password); i++) {
    for (int j = 0; j < NUM_CHAR_CLASSES; j++) {
      if (password[i] == char_classes[j]) {
        char_class_count[j]++;
        break;
      }
    }
  }
  for (int i = 0; i < NUM_CHAR_CLASSES; i++) {
    if (char_class_count[i] == 0) {
      return 0;
    }
  }

  // Calculate the total weight of the password
  int total_weight = 0;
  for (int i = 0; i < NUM_CHAR_CLASSES; i++) {
    total_weight += char_class_count[i] * CHAR_CLASS_WEIGHT;
  }

  // Check if the total weight of the password is high enough
  if (total_weight < TOTAL_WEIGHT) {
    return 0;
  }

  // Return 1 if the password is valid
  return 1;
}

// Main function
int main(int argc, char **argv) {
  // Get the password from the user
  char password[MAX_PASSWORD_LENGTH + 1];
  printf("Enter your password: ");
  scanf("%s", password);

  // Check if the password is valid
  if (is_password_valid(password)) {
    printf("Your password is valid\n");
  } else {
    printf("Your password is not valid\n");
  }

  return 0;
}