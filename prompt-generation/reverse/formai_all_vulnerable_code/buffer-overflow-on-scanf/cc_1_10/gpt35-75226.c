//FormAI DATASET v1.0 Category: modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the encryption function with two inputs: the message and the encryption key
void encrypt(char message[], int key) {
  // Determine the length of the message
  int message_length = strlen(message);
  // Create a new array to store the encrypted message
  char encrypted_message[message_length];
  // Loop through each character in the message
  for (int i = 0; i < message_length; i++) {
    // Convert the character to an integer
    int character = (int) message[i];
    // Add the encryption key to the integer and take the modulo 256
    int encrypted_character = (character + key) % 256;
    // Convert the encrypted character back to a character and add it to the encrypted message
    encrypted_message[i] = (char) encrypted_character;
  }
  // Print the encrypted message
  printf("Encrypted message: %s\n", encrypted_message);
}

// Define the decryption function with two inputs: the encrypted message and the decryption key
void decrypt(char encrypted_message[], int key) {
  // Determine the length of the encrypted message
  int message_length = strlen(encrypted_message);
  // Create a new array to store the decrypted message
  char decrypted_message[message_length];
  // Loop through each character in the encrypted message
  for (int i = 0; i < message_length; i++) {
    // Convert the character to an integer
    int character = (int) encrypted_message[i];
    // Subtract the encryption key from the integer and take the modulo 256
    int decrypted_character = (character - key) % 256;
    // Convert the decrypted character back to a character and add it to the decrypted message
    decrypted_message[i] = (char) decrypted_character;
  }
  // Print the decrypted message
  printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
  // Get the message to encrypt from the user
  char message[100];
  printf("Enter the message to encrypt: ");
  fgets(message, 100, stdin);
  // Get the encryption key from the user
  int key;
  printf("Enter the encryption key: ");
  scanf("%d", &key);
  // Encrypt the message using the encryption key
  encrypt(message, key);
  // Decrypt the encrypted message using the same encryption key
  decrypt("ÉÏÒñòøüÓúËçüê£ÕºïÎïÑ£¤¾ó", key);
  // Return 0 to signify success
  return 0;
}