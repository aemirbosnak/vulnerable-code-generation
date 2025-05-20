//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check for valid arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open the input file
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    fprintf(stderr, "Error opening input file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Read the input data into a buffer
  char buffer[1024];
  size_t len = fread(buffer, sizeof(char), sizeof(buffer), input_file);
  if (ferror(input_file)) {
    fprintf(stderr, "Error reading input file: %s\n", argv[1]);
    fclose(input_file);
    return EXIT_FAILURE;
  }

  // Close the input file
  fclose(input_file);

  // Initialize the sanitizer
  struct sanitizer {
    unsigned char blacklist[256];
    unsigned char whitelist[256];
  } sanitizer = {0};

  // Configure the sanitizer
  for (char c = 0; c < 256; c++) {
    if (c >= 'a' && c <= 'z') {
      // Allow lowercase letters
      sanitizer.whitelist[c] = 1;
    } else if (c >= 'A' && c <= 'Z') {
      // Allow uppercase letters
      sanitizer.whitelist[c] = 1;
    } else if (c >= '0' && c <= '9') {
      // Allow digits
      sanitizer.whitelist[c] = 1;
    } else if (c == ' ' || c == '\n' || c == '\t') {
      // Allow whitespace characters
      sanitizer.whitelist[c] = 1;
    } else {
      // Blacklist all other characters
      sanitizer.blacklist[c] = 1;
    }
  }

  // Sanitize the input data
  for (size_t i = 0; i < len; i++) {
    if (sanitizer.blacklist[buffer[i]]) {
      // Blacklisted character found, replace with a space
      buffer[i] = ' ';
    }
  }

  // Print the sanitized data
  printf("%s", buffer);

  return EXIT_SUCCESS;
}