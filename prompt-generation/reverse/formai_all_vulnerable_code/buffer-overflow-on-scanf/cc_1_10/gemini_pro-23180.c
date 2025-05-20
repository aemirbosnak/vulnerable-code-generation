//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
void welcome() {
  printf("Welcome to the Super Secret File Encryptor!\n");
  printf("Let's keep your files safe and sound!\n\n");
}

// Get input and output file names
char *get_file_names() {
  char *input_file_name = malloc(100);
  char *output_file_name = malloc(100);

  printf("Enter the name of the file you want to encrypt: ");
  scanf("%s", input_file_name);
  printf("Enter the name of the encrypted file: ");
  scanf("%s", output_file_name);

  return input_file_name, output_file_name;
}

// Read the input file
char *read_file(char *file_name) {
  FILE *file = fopen(file_name, "rb");
  if (file == NULL) {
    printf("Error opening file: %s\n", file_name);
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  char *file_contents = malloc(file_size + 1);
  fread(file_contents, file_size, 1, file);
  fclose(file);

  return file_contents;
}

// Encrypt the file contents
char *encrypt_file(char *file_contents, int key) {
  int length = strlen(file_contents);
  char *encrypted_file_contents = malloc(length + 1);

  for (int i = 0; i < length; i++) {
    encrypted_file_contents[i] = file_contents[i] ^ key;
  }

  return encrypted_file_contents;
}

// Write the encrypted file
void write_file(char *file_name, char *file_contents) {
  FILE *file = fopen(file_name, "wb");
  if (file == NULL) {
    printf("Error opening file: %s\n", file_name);
    exit(1);
  }

  fwrite(file_contents, strlen(file_contents), 1, file);
  fclose(file);
}

// Success message
void success() {
  printf("\nFile encrypted successfully!\n");
  printf("Your file is now safe from prying eyes.\n");
}

int main() {
  welcome();
  char *file_names = get_file_names();
  char *file_contents = read_file(file_names[0]);
  char *encrypted_file_contents = encrypt_file(file_contents, 123);
  write_file(file_names[1], encrypted_file_contents);
  success();
  return 0;
}