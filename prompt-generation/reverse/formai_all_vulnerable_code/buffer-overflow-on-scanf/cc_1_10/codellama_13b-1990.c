//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: cheerful
/*
 * File Encryptor - Cheerful Edition
 *
 * This program will encrypt a file using a simple
 * substitution cipher.
 *
 * To use, simply run the program and enter the
 * name of the file you want to encrypt.
 *
 * The encrypted file will be created in the same
 * directory as the original file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_KEY_LEN 100
#define MAX_KEY_SIZE 1000

/*
 * Encrypts a file using a simple substitution cipher.
 *
 * Parameters:
 *  filename - the name of the file to encrypt
 *  key - the key to use for encryption
 */
void encrypt_file(char *filename, char *key) {
  FILE *fp_in, *fp_out;
  char c, c_encrypted;
  int i;

  // Open the file for reading and writing
  fp_in = fopen(filename, "r+");
  if (fp_in == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }
  fp_out = fopen(filename, "w");
  if (fp_out == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return;
  }

  // Read each character from the file and encrypt it
  while ((c = fgetc(fp_in)) != EOF) {
    c_encrypted = c + key[i % MAX_KEY_SIZE];
    fputc(c_encrypted, fp_out);
    i++;
  }

  // Close the files
  fclose(fp_in);
  fclose(fp_out);
}

int main() {
  char filename[MAX_FILE_NAME_LEN];
  char key[MAX_KEY_LEN];

  // Get the filename and key from the user
  printf("Enter the name of the file to encrypt: ");
  scanf("%s", filename);
  printf("Enter the encryption key: ");
  scanf("%s", key);

  // Encrypt the file
  encrypt_file(filename, key);

  return 0;
}