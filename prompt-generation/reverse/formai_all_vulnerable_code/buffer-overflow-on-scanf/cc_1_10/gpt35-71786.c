//FormAI DATASET v1.0 Category: Encryption ; Style: excited
// Hey there! Get ready to see the excitement of encryption in C programming language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the encryption key
#define KEY_SIZE 15

// Function to encrypt the input string using the key
void encrypt(char *string, char *key) {
  int i, j, k = 0;
  int string_length = strlen(string);
  int key_length = strlen(key);

  // Loop through each character in the input string
  for (i = 0; i < string_length; i++) {
    // Get the ASCII value of the character
    int value = (int) string[i];

    // Apply the encryption algorithm to the character
    if (value >= 65 && value <= 90) {
      // If the character is uppercase
      value = ((value - 65) + (int) key[k]) % 26 + 65;
    } else if (value >= 97 && value <= 122) {
      // If the character is lowercase
      value = ((value - 97) + (int) key[k]) % 26 + 97;
    }

    // Set the encrypted character in the input string
    string[i] = (char) value;

    // Update the key position
    k++;
    if (k >= key_length) {
      k = 0;
    }
  }
}

// Main function to run the encryption
int main() {
  char string[100];
  char key[KEY_SIZE];

  printf("Welcome to the exciting world of C Encryption!\n");
  printf("Please enter a string to encrypt: ");
  scanf("%s", string);

  printf("Please enter a key (length %d): ", KEY_SIZE);
  scanf("%s", key);

  // Check if the key is of the expected length
  if (strlen(key) != KEY_SIZE) {
    printf("Error: Key length should be %d\n", KEY_SIZE);
    return -1;
  }

  // Encrypt the input string using the key
  encrypt(string, key);

  printf("The encrypted string is: %s\n", string);

  return 0;
}