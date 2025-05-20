//FormAI DATASET v1.0 Category: Compression algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main() {
  char input[MAX_SIZE], output[MAX_SIZE], compressed[MAX_SIZE];
  int frequency[MAX_SIZE] = {0};
  int input_len, output_len, compressed_len, i, j, k = 0;

  printf("Enter the input string: ");
  fgets(input, MAX_SIZE, stdin);

  // Calculate the frequency of each character in the input string
  input_len = strlen(input) - 1; // Subtract 1 to exclude the newline character
  for (i = 0; i < input_len; i++) {
    frequency[input[i]]++;
  }

  // Copy the input string to the output string and set the output length
  strcpy(output, input);
  output_len = input_len;

  // Perform run-length encoding on the output string
  for (i = 0; i < output_len; i = j) {
    j = i + 1;
    while (output[j] == output[i] && j < output_len) {
      j++;
    }
    if (j - i >= 4) { // Use run-length encoding if the run length is 4 or greater
      compressed[k++] = output[i];
      compressed[k++] = output[i];
      compressed[k++] = (j - i) + '0';
      compressed_len += 3;
    } else { // Otherwise, use the original character
      compressed[k++] = output[i];
      compressed_len++;
    }
  }

  // Compare the sizes of the output string and the compressed string
  if (compressed_len < output_len) {
    printf("The compressed string is shorter than the original string!\n");
    printf("The compressed string is: %s\n", compressed);
  } else {
    printf("The compressed string is longer than the original string, so no compression is performed.\n");
    printf("The original string is: %s\n", output);
  }
  
  return 0;
}