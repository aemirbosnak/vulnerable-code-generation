//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Surprise! This encryption is not so modern!
// But it's a start, right?

// Function to encrypt a string using the Caesar cipher
char* encrypt_caesar(char* plaintext, int key) {
  // Allocate memory for the ciphertext
  char* ciphertext = malloc(strlen(plaintext) + 1);
  
  // Encrypt each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    // Get the ASCII value of the current character
    int ascii = plaintext[i];
    
    // Check if the character is a letter
    if (ascii >= 'A' && ascii <= 'Z') {
      // Shift the character by the key amount
      ascii += key;
      
      // Wrap around if the character goes past 'Z'
      if (ascii > 'Z') ascii -= 26;
    } else if (ascii >= 'a' && ascii <= 'z') {
      // Shift the character by the key amount
      ascii += key;
      
      // Wrap around if the character goes past 'z'
      if (ascii > 'z') ascii -= 26;
    }
    
    // Store the encrypted character in the ciphertext
    ciphertext[i] = ascii;
  }
  
  // Terminate the ciphertext with a null character
  ciphertext[strlen(plaintext)] = '\0';
  
  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string using the Caesar cipher
char* decrypt_caesar(char* ciphertext, int key) {
  // Allocate memory for the plaintext
  char* plaintext = malloc(strlen(ciphertext) + 1);
  
  // Decrypt each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    // Get the ASCII value of the current character
    int ascii = ciphertext[i];
    
    // Check if the character is a letter
    if (ascii >= 'A' && ascii <= 'Z') {
      // Shift the character by the key amount
      ascii -= key;
      
      // Wrap around if the character goes past 'A'
      if (ascii < 'A') ascii += 26;
    } else if (ascii >= 'a' && ascii <= 'z') {
      // Shift the character by the key amount
      ascii -= key;
      
      // Wrap around if the character goes past 'a'
      if (ascii < 'a') ascii += 26;
    }
    
    // Store the decrypted character in the plaintext
    plaintext[i] = ascii;
  }
  
  // Terminate the plaintext with a null character
  plaintext[strlen(ciphertext)] = '\0';
  
  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  char* plaintext = malloc(100);
  printf("Enter the plaintext: ");
  scanf("%s", plaintext);
  
  // Get the encryption key from the user
  int key;
  printf("Enter the encryption key: ");
  scanf("%d", &key);
  
  // Encrypt the plaintext using the Caesar cipher
  char* ciphertext = encrypt_caesar(plaintext, key);
  
  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);
  
  // Decrypt the ciphertext using the Caesar cipher
  char* decrypted_plaintext = decrypt_caesar(ciphertext, key);
  
  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", decrypted_plaintext);
  
  // Free the allocated memory
  free(plaintext);
  free(ciphertext);
  free(decrypted_plaintext);
  
  return 0;
}