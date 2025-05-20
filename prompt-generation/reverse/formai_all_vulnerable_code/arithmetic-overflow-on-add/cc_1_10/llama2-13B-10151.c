//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: surprised
// Surprised Compression Algorithm

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

// Function to compress the input string
void compress(char* input) {
  int i, j, k;
  char c;
  int freq[26];
  int len = strlen(input);

  // Initialize frequency array
  for (i = 0; i < 26; i++) {
    freq[i] = 0;
  }

  // Count the frequency of each character
  for (i = 0; i < len; i++) {
    c = input[i];
    freq[c - 'a']++;
  }

  // Sort the frequency array in descending order
  for (i = 0; i < 26; i++) {
    for (j = i + 1; j < 26; j++) {
      if (freq[i] > freq[j]) {
        int temp = freq[i];
        freq[i] = freq[j];
        freq[j] = temp;
      }
    }
  }

  // Compress the input string
  char* output = (char*)malloc(len * 2);
  j = 0;
  for (i = 0; i < len; i++) {
    c = input[i];
    if (freq[c - 'a'] > 0) {
      output[j++] = c;
      freq[c - 'a']--;
    }
  }

  // Special case for the letter 'e'
  if (freq['e' - 'a'] > 0) {
    output[j++] = 'e';
    freq['e' - 'a']--;
  }

  // Special case for the letter 'a'
  if (freq['a' - 'a'] > 0) {
    output[j++] = 'a';
    freq['a' - 'a']--;
  }

  // Print the compressed string
  printf("Compressed string: %s\n", output);

  // Free the memory
  free(output);
}

int main() {
  char input[] = "The quick brown fox jumps over the lazy dog";
  compress(input);
  return 0;
}