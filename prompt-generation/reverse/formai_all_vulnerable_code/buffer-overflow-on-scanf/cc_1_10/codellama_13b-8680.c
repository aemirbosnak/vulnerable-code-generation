//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: artistic
// Compression Algorithm in C - Artistic Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compress a string using the following algorithm
// 1. Split the string into individual characters
// 2. Count the frequency of each character
// 3. Replace each character with its frequency
// 4. Concatenate the characters with their frequencies

int main() {
  char str[100];
  char* ptr;
  int count;
  int freq;

  printf("Enter a string: ");
  scanf("%s", str);

  // Split the string into individual characters
  ptr = str;
  while (*ptr != '\0') {
    count = 1;
    freq = 0;
    while (*(ptr + count) != '\0') {
      if (*ptr == *(ptr + count)) {
        freq++;
        count++;
      } else {
        break;
      }
    }
    if (freq > 0) {
      *ptr = freq + '0';
      ptr += count;
    } else {
      ptr++;
    }
  }

  // Concatenate the characters with their frequencies
  ptr = str;
  while (*ptr != '\0') {
    if (*ptr != '0') {
      printf("%c", *ptr);
    }
    ptr++;
  }
  printf("\n");

  return 0;
}