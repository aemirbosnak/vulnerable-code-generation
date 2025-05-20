//FormAI DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char* compress(char* input);

int main() {
  char input[MAX_LENGTH];
  printf("Enter the string to compress: ");
  fgets(input, MAX_LENGTH, stdin);

  char* compressed = compress(input);
  printf("Compressed string: %s\n", compressed);

  free(compressed);
  
  return 0;
}

// Custom compression algorithm
char* compress(char* input) {
  int counts[256] = {0}; // count of each ASCII character

  // Counting the frequency of each character
  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];
    counts[(int)c]++;
  }

  // Calculating the length of the compressed string
  int length = 0;
  for (int i = 0; i < 256; i++) {
    if (counts[i] > 0) {
      length += 2; // count and character
    }
  }

  char* compressed = (char*)malloc(length+1); // +1 for null terminator
  int index = 0;

  // Writing the compressed string
  for (int i = 0; i < 256; i++) {
    if (counts[i] > 0) {
      compressed[index] = counts[i] + '0';
      index++;
      compressed[index] = (char)i;
      index++;
    }
  }

  compressed[length] = '\0';
  return compressed;
}