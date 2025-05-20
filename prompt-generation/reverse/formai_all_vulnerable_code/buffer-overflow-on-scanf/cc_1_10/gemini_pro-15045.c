//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using LZW algorithm
char *compress(char *input) {
  // Initialize the dictionary with the first 256 characters
  char dictionary[256];
  for (int i = 0; i < 256; i++) {
    dictionary[i] = i;
  }

  // Initialize the compressed string
  char *compressed = malloc(strlen(input) + 1);
  compressed[0] = '\0';

  // Initialize the current dictionary index
  int dict_index = 256;

  // Iterate over the input string
  for (int i = 0; i < strlen(input); i++) {
    // Check if the current character is in the dictionary
    int code = -1;
    for (int j = 0; j < dict_index; j++) {
      if (dictionary[j] == input[i]) {
        code = j;
        break;
      }
    }

    // If the current character is not in the dictionary, add it to the dictionary and compress it using the code of the previous character
    if (code == -1) {
      dictionary[dict_index++] = input[i];
      strcat(compressed, " ");
      char temp[10];
      sprintf(temp, "%d", dictionary[code]);
      strcat(compressed, temp);
    }
    // If the current character is in the dictionary, compress it using the code
    else {
      char temp[10];
      sprintf(temp, "%d", code);
      strcat(compressed, " ");
      strcat(compressed, temp);
    }
  }

  // Return the compressed string
  return compressed;
}

// Function to decompress a string using LZW algorithm
char *decompress(char *input) {
  // Initialize the dictionary with the first 256 characters
  char dictionary[256];
  for (int i = 0; i < 256; i++) {
    dictionary[i] = i;
  }

  // Initialize the decompressed string
  char *decompressed = malloc(strlen(input) + 1);
  decompressed[0] = '\0';

  // Initialize the current dictionary index
  int dict_index = 256;

  // Split the input string into tokens
  char *tokens[1000];
  int num_tokens = 0;
  char *token = strtok(input, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Iterate over the tokens
  for (int i = 0; i < num_tokens; i++) {
    // Convert the token to an integer
    int code = atoi(tokens[i]);

    // If the code is in the dictionary, append the corresponding character to the decompressed string
    if (code < dict_index) {
      char c = dictionary[code];
      strncat(decompressed, &c, 1);

      // Add the previous character and the current character to the dictionary
      dictionary[dict_index++] = dictionary[code] + c;
    }
    // If the code is not in the dictionary, append the previous character to the decompressed string
    else {
      char c = dictionary[code - 1];
      strncat(decompressed, &c, 1);

      // Add the previous character and the current character to the dictionary
      dictionary[dict_index++] = c + c;
    }
  }

  // Return the decompressed string
  return decompressed;
}

int main() {
  // Get the input string from the user
  printf("Enter the string to be compressed: ");
  char input[1000];
  scanf("%s", input);

  // Compress the string
  char *compressed = compress(input);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the string
  char *decompressed = decompress(compressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  return 0;
}