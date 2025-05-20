//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
  // Open the input file
  FILE *in = fopen(input_file, "r");
  if (in == NULL) {
    printf("Error opening input file\n");
    return;
  }

  // Open the output file
  FILE *out = fopen(output_file, "w");
  if (out == NULL) {
    printf("Error opening output file\n");
    return;
  }

  // Read the input file and encrypt it
  int c;
  while ((c = fgetc(in)) != EOF) {
    // Encrypt the character
    c = (c + 13) % 256;

    // Write the encrypted character to the output file
    fputc(c, out);
  }

  // Close the input and output files
  fclose(in);
  fclose(out);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
  // Open the input file
  FILE *in = fopen(input_file, "r");
  if (in == NULL) {
    printf("Error opening input file\n");
    return;
  }

  // Open the output file
  FILE *out = fopen(output_file, "w");
  if (out == NULL) {
    printf("Error opening output file\n");
    return;
  }

  // Read the input file and decrypt it
  int c;
  while ((c = fgetc(in)) != EOF) {
    // Decrypt the character
    c = (c - 13) % 256;

    // Write the decrypted character to the output file
    fputc(c, out);
  }

  // Close the input and output files
  fclose(in);
  fclose(out);
}

int main(int argc, char **argv) {
  // Check if the correct number of arguments was passed
  if (argc != 4) {
    printf("Usage: %s <input file> <output file> <mode>\n", argv[0]);
    return 1;
  }

  // Get the input and output file names
  char *input_file = argv[1];
  char *output_file = argv[2];
  char *mode = argv[3];

  // Check if the mode is valid
  if (strcmp(mode, "encrypt") && strcmp(mode, "decrypt")) {
    printf("Invalid mode\n");
    return 1;
  }

  // Call the appropriate function
  if (!strcmp(mode, "encrypt")) {
    encrypt_file(input_file, output_file);
  } else {
    decrypt_file(input_file, output_file);
  }

  return 0;
}