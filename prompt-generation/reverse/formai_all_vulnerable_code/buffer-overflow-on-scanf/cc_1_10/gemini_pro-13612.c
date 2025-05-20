//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret key, an array of bytes
unsigned char key[] = { 0x42, 0x23, 0x19, 0x0F, 0x07, 0x03, 0x01, 0x00 };

// Encrypt the input file using XOR encryption
void encrypt_file(char* input_file, char* output_file) {
  // Open the input file for reading
  FILE* input = fopen(input_file, "rb");
  if (input == NULL) {
    printf("Error opening input file %s\n", input_file);
    return;
  }

  // Open the output file for writing
  FILE* output = fopen(output_file, "wb");
  if (output == NULL) {
    printf("Error opening output file %s\n", output_file);
    return;
  }

  // Read the input file byte by byte
  unsigned char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
    // Encrypt the buffer using XOR encryption
    for (size_t i = 0; i < bytes_read; i++) {
      buffer[i] ^= key[i % sizeof(key)];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, 1, bytes_read, output);
  }

  // Close the files
  fclose(input);
  fclose(output);
}

// Decrypt the input file using XOR encryption
void decrypt_file(char* input_file, char* output_file) {
  // Open the input file for reading
  FILE* input = fopen(input_file, "rb");
  if (input == NULL) {
    printf("Error opening input file %s\n", input_file);
    return;
  }

  // Open the output file for writing
  FILE* output = fopen(output_file, "wb");
  if (output == NULL) {
    printf("Error opening output file %s\n", output_file);
    return;
  }

  // Read the input file byte by byte
  unsigned char buffer[1024];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
    // Decrypt the buffer using XOR encryption
    for (size_t i = 0; i < bytes_read; i++) {
      buffer[i] ^= key[i % sizeof(key)];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, 1, bytes_read, output);
  }

  // Close the files
  fclose(input);
  fclose(output);
}

int main() {
  // Get the input and output file names from the user
  char input_file[100];
  printf("Enter the name of the file to be encrypted: ");
  scanf("%s", input_file);

  char output_file[100];
  printf("Enter the name of the encrypted file: ");
  scanf("%s", output_file);

  // Encrypt the input file
  encrypt_file(input_file, output_file);

  // Print a success message
  printf("File encrypted successfully!\n");

  // Get the input and output file names for decryption
  char input_file2[100];
  printf("Enter the name of the file to be decrypted: ");
  scanf("%s", input_file2);

  char output_file2[100];
  printf("Enter the name of the decrypted file: ");
  scanf("%s", output_file2);

  // Decrypt the input file
  decrypt_file(input_file2, output_file2);

  // Print a success message
  printf("File decrypted successfully!\n");

  return 0;
}