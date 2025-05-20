//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char message[100];
  int key;
  
  // Get message from user
  printf("Enter message: ");
  scanf("%[^\n]", message);
  
  // Get key from user
  printf("Enter key: ");
  scanf("%d", &key);
  
  // Encrypt message
  char encrypted_message[100] = {0};
  int i, j;
  for (i = 0, j = 0; i < strlen(message); i++) {
    if (isalpha(message[i])) {
      if (isupper(message[i])) {
        encrypted_message[j] = ((message[i] + key) % 26) + 'A';
      } else {
        encrypted_message[j] = ((message[i] + key) % 26) + 'a';
      }
      j++;
    } else {
      encrypted_message[j] = message[i];
      j++;
    }
  }
  
  // Print encrypted message
  printf("Encrypted message: %s\n", encrypted_message);
  
  // Decrypt message
  char decrypted_message[100] = {0};
  for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
    if (isalpha(encrypted_message[i])) {
      if (isupper(encrypted_message[i])) {
        decrypted_message[j] = ((encrypted_message[i] - key - 'A' + 26) % 26) + 'A';
      } else {
        decrypted_message[j] = ((encrypted_message[i] - key - 'a' + 26) % 26) + 'a';
      }
      j++;
    } else {
      decrypted_message[j] = encrypted_message[i];
      j++;
    }
  }
  
  // Print decrypted message
  printf("Decrypted message: %s\n", decrypted_message);
  
  return 0;
}