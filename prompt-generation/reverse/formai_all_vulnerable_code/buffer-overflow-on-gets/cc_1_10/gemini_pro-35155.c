//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string to uppercase
void toUpper(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    }
  }
}

// Function to convert a string to lowercase
void toLower(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    }
  }
}

// Function to find the length of a string
int strLen(char *str) {
  int len;
  for (len = 0; str[len] != '\0'; len++) {}
  return len;
}

// Function to compare two strings
int strCmp(char *str1, char *str2) {
  int i;
  for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      return 1;
    }
  }
  if (str1[i] != '\0' || str2[i] != '\0') {
    return 1;
  }
  return 0;
}

// Function to reverse a string
void strRev(char *str) {
  int i, j;
  for (i = 0, j = strLen(str) - 1; i < j; i++, j--) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

// Function to encrypt a string using the Caesar cipher
void caesarEnc(char *str, int key) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = (((str[i] - 'A') + key) % 26) + 'A';
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = (((str[i] - 'a') + key) % 26) + 'a';
    }
  }
}

// Function to decrypt a string using the Caesar cipher
void caesarDec(char *str, int key) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = (((str[i] - 'A') - key) % 26) + 'A';
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = (((str[i] - 'a') - key) % 26) + 'a';
    }
  }
}

// Function to encrypt a string using the XOR cipher
void xorEnc(char *str, char *key) {
  int i, j;
  for (i = 0, j = 0; str[i] != '\0'; i++, j++) {
    if (key[j] == '\0') {
      j = 0;
    }
    str[i] ^= key[j];
  }
}

// Function to decrypt a string using the XOR cipher
void xorDec(char *str, char *key) {
  xorEnc(str, key);
}

int main() {
  // Get the input string
  char str[100];
  printf("Enter the string to encrypt: ");
  gets(str);

  // Convert the string to uppercase
  toUpper(str);

  // Encrypt the string using the Caesar cipher with a key of 3
  caesarEnc(str, 3);

  // Print the encrypted string
  printf("Encrypted string: %s\n", str);

  // Decrypt the string using the Caesar cipher with a key of 3
  caesarDec(str, 3);

  // Print the decrypted string
  printf("Decrypted string: %s\n", str);

  // Encrypt the string using the XOR cipher with a key of "KEY"
  xorEnc(str, "KEY");

  // Print the encrypted string
  printf("Encrypted string: %s\n", str);

  // Decrypt the string using the XOR cipher with a key of "KEY"
  xorDec(str, "KEY");

  // Print the decrypted string
  printf("Decrypted string: %s\n", str);

  return 0;
}