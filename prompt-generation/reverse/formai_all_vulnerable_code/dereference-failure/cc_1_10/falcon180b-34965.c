//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_INPUT_LENGTH 4096

void generate_key(char *key, int length) {
  for (int i = 0; i < length; i++) {
    key[i] = rand() % 256;
  }
}

void encrypt(char *input, char *key, char *output) {
  int input_length = strlen(input);
  int key_length = strlen(key);

  if (input_length > MAX_INPUT_LENGTH || key_length > MAX_KEY_LENGTH) {
    printf("Error: Input or key is too long\n");
    exit(1);
  }

  char *input_copy = malloc(input_length + 1);
  strcpy(input_copy, input);

  char *key_copy = malloc(key_length + 1);
  strcpy(key_copy, key);

  int key_index = 0;
  for (int i = 0; i < input_length; i++) {
    output[i] = input_copy[i] ^ key_copy[key_index];
    key_index = (key_index + 1) % key_length;
  }
  output[input_length] = '\0';
}

void decrypt(char *input, char *key, char *output) {
  encrypt(input, key, output);
}

int main() {
  char input[MAX_INPUT_LENGTH + 1] = "Hello, world! ";
  char key[MAX_KEY_LENGTH + 1] = "secret";
  char output[MAX_INPUT_LENGTH + 1] = "";

  printf("Input: %s\n", input);
  printf("Key: %s\n", key);

  encrypt(input, key, output);
  printf("Encrypted: %s\n", output);

  decrypt(output, key, input);
  printf("Decrypted: %s\n", input);

  return 0;
}