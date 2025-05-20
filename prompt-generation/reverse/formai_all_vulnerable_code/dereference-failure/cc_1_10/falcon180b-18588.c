//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

void encrypt(char *file_name, char *key) {
  FILE *input_file, *output_file;
  char ch, key_index = 0;
  input_file = fopen(file_name, "rb");
  if (input_file == NULL) {
    printf("Error opening input file.\n");
    exit(1);
  }
  output_file = fopen("encrypted_file.txt", "wb");
  if (output_file == NULL) {
    printf("Error creating output file.\n");
    exit(1);
  }
  while ((ch = fgetc(input_file))!= EOF) {
    ch = ch ^ key[key_index];
    key_index = (key_index + 1) % KEY_LENGTH;
    fputc(ch, output_file);
  }
  fclose(input_file);
  fclose(output_file);
}

void decrypt(char *file_name, char *key) {
  FILE *input_file, *output_file;
  char ch, key_index = 0;
  input_file = fopen(file_name, "rb");
  if (input_file == NULL) {
    printf("Error opening input file.\n");
    exit(1);
  }
  output_file = fopen("decrypted_file.txt", "wb");
  if (output_file == NULL) {
    printf("Error creating output file.\n");
    exit(1);
  }
  while ((ch = fgetc(input_file))!= EOF) {
    ch = ch ^ key[key_index];
    key_index = (key_index + 1) % KEY_LENGTH;
    fputc(ch, output_file);
  }
  fclose(input_file);
  fclose(output_file);
}

int main() {
  char file_name[100], key[KEY_LENGTH];
  printf("Enter file name: ");
  scanf("%s", file_name);
  printf("Enter encryption/decryption key: ");
  scanf("%s", key);
  int choice;
  printf("Enter 1 for encryption, 2 for decryption: ");
  scanf("%d", &choice);
  if (choice == 1) {
    encrypt(file_name, key);
    printf("File encrypted successfully.\n");
  } else if (choice == 2) {
    decrypt(file_name, key);
    printf("File decrypted successfully.\n");
  } else {
    printf("Invalid choice.\n");
  }
  return 0;
}