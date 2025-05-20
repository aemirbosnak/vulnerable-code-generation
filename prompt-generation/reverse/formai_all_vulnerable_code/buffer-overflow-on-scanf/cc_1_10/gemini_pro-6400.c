//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Our super-secret encryption key!
const char KEY[] = "dON't TeLl aNyOnE!";

// A custom function to encrypt a single character
char encryptChar(char c, int key) {
  // Convert the character to an integer
  int charInt = (int) c;

  // Encrypt the character using the key
  charInt += key;

  // Convert the encrypted integer back to a character
  char encryptedChar = (char) charInt;

  // Return the encrypted character
  return encryptedChar;
}

// A custom function to decrypt a single character
char decryptChar(char c, int key) {
  // Convert the character to an integer
  int charInt = (int) c;

  // Decrypt the character using the key
  charInt -= key;

  // Convert the decrypted integer back to a character
  char decryptedChar = (char) charInt;

  // Return the decrypted character
  return decryptedChar;
}

// A custom function to encrypt a string
char *encryptString(char *str, int key) {
  // Allocate memory for the encrypted string
  char *encryptedStr = (char *) malloc(strlen(str) + 1);

  // Encrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    encryptedStr[i] = encryptChar(str[i], key);
  }

  // Add the null terminator to the end of the encrypted string
  encryptedStr[strlen(str)] = '\0';

  // Return the encrypted string
  return encryptedStr;
}

// A custom function to decrypt a string
char *decryptString(char *str, int key) {
  // Allocate memory for the decrypted string
  char *decryptedStr = (char *) malloc(strlen(str) + 1);

  // Decrypt each character in the string
  for (int i = 0; i < strlen(str); i++) {
    decryptedStr[i] = decryptChar(str[i], key);
  }

  // Add the null terminator to the end of the decrypted string
  decryptedStr[strlen(str)] = '\0';

  // Return the decrypted string
  return decryptedStr;
}

// Our main function
int main() {
  // Get the message from the user
  char message[100];
  printf("Enter your secret message: ");
  scanf("%s", message);

  // Convert the message to lowercase
  for (int i = 0; i < strlen(message); i++) {
    message[i] = tolower(message[i]);
  }

  // Encrypt the message using our super-secret key
  char *encryptedMessage = encryptString(message, strlen(KEY));

  // Print the encrypted message
  printf("Encrypted message: %s\n", encryptedMessage);

  // Decrypt the message using our super-secret key
  char *decryptedMessage = decryptString(encryptedMessage, strlen(KEY));

  // Print the decrypted message
  printf("Decrypted message: %s\n", decryptedMessage);

  // Free the memory allocated for the encrypted and decrypted strings
  free(encryptedMessage);
  free(decryptedMessage);

  return 0;
}