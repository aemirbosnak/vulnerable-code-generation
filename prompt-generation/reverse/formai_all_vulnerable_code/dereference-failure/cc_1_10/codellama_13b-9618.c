//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: interoperable
// C file encrypter example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define encryption key
#define KEY "my_secret_key"

// function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
  // open input file
  FILE *in_file = fopen(input_file, "rb");
  if (!in_file) {
    printf("Error: could not open input file %s\n", input_file);
    return;
  }

  // open output file
  FILE *out_file = fopen(output_file, "wb");
  if (!out_file) {
    printf("Error: could not open output file %s\n", output_file);
    fclose(in_file);
    return;
  }

  // read data from input file
  char buffer[BUFSIZ];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, BUFSIZ, in_file)) > 0) {
    // encrypt data using XOR encryption
    for (size_t i = 0; i < bytes_read; i++) {
      buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // write encrypted data to output file
    fwrite(buffer, 1, bytes_read, out_file);
  }

  // close files
  fclose(in_file);
  fclose(out_file);
}

// function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
  // open input file
  FILE *in_file = fopen(input_file, "rb");
  if (!in_file) {
    printf("Error: could not open input file %s\n", input_file);
    return;
  }

  // open output file
  FILE *out_file = fopen(output_file, "wb");
  if (!out_file) {
    printf("Error: could not open output file %s\n", output_file);
    fclose(in_file);
    return;
  }

  // read data from input file
  char buffer[BUFSIZ];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, BUFSIZ, in_file)) > 0) {
    // decrypt data using XOR encryption
    for (size_t i = 0; i < bytes_read; i++) {
      buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // write decrypted data to output file
    fwrite(buffer, 1, bytes_read, out_file);
  }

  // close files
  fclose(in_file);
  fclose(out_file);
}

// main function
int main(int argc, char **argv) {
  // check command-line arguments
  if (argc != 4) {
    printf("Usage: %s <encrypt|decrypt> <input file> <output file>\n", argv[0]);
    return 1;
  }

  // determine operation
  char *operation = argv[1];
  if (strcmp(operation, "encrypt") == 0) {
    // encrypt file
    encrypt_file(argv[2], argv[3]);
  } else if (strcmp(operation, "decrypt") == 0) {
    // decrypt file
    decrypt_file(argv[2], argv[3]);
  } else {
    printf("Invalid operation: %s\n", operation);
    return 1;
  }

  return 0;
}