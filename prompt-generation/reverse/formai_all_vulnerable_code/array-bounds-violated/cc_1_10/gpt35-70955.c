//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// This program represents a statistical encryption algorithm for strings
// It works by taking a string and generating a key based on the frequencies of each character
// The key is then used to encrypt the original string

int main() {
  // Prompt the user for a string to encrypt
  char str[100];
  printf("Enter a string to encrypt: ");
  scanf("%99[^\n]", str);

  // Determine the length of the string
  int len = strlen(str);

  // Create an array to store the frequency of each character in the string
  int freq[256] = {0};
  for (int i = 0; i < len; i++) {
    freq[str[i]]++;
  }

  // Compute the probability of each character occurring in the string
  double prob[256] = {0.0};
  for (int i = 0; i < 256; i++) {
    prob[i] = (double) freq[i] / len;
  }

  // Compute the entropy of the string
  double entropy = 0.0;
  for (int i = 0; i < 256; i++) {
    if (prob[i] > 0) {
      entropy -= prob[i] * log2(prob[i]);
    }
  }

  // Round the entropy to the nearest integer
  int key = (int) round(entropy);

  // Encrypt the string using the key
  for (int i = 0; i < len; i++) {
    str[i] ^= key;
  }

  // Output the encrypted string and the key used to encrypt it
  printf("Encrypted string: %s\n", str);
  printf("Key: %d\n", key);

  return 0;
}