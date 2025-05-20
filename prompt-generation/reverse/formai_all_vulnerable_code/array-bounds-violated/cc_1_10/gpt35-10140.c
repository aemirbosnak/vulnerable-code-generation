//FormAI DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

/* This program implements a unique compression algorithm that replaces every sequence of 3 or more consecutive identical characters with a single character repeated 3 times. */

void compress_string(char *input_str) {
  int len = strlen(input_str);
  int count;
  char compressed_str[MAX_SIZE];
  int j = 0;

  for (int i = 0; i < len; i += count) {
    count = 1;
    while (i + count < len && input_str[i] == input_str[i + count]) {
      count++;
    }

    if (count >= 3) {
      compressed_str[j++] = input_str[i];
      compressed_str[j++] = input_str[i];
      compressed_str[j++] = input_str[i];
    }
    else {
      for (int k = i; k < i + count; k++) {
        compressed_str[j++] = input_str[k];
      }
    }
  }
  compressed_str[j] = '\0';

  strcpy(input_str, compressed_str);
}

int main() {
  char input_str[MAX_SIZE];

  printf("Enter a string: ");
  fgets(input_str, MAX_SIZE, stdin);

  int len = strlen(input_str);
  if (input_str[len - 1] == '\n') {
    input_str[len - 1] = '\0';
  }

  compress_string(input_str);

  printf("Compressed string: %s\n", input_str);

  return 0;
}