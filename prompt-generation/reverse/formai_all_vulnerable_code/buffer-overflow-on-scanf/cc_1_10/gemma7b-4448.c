//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 1024

typedef struct Key {
  char key[MAX_KEY_LENGTH];
  int length;
} Key;

void generate_key(Key *key) {
  key->length = rand() % MAX_KEY_LENGTH + 1;
  for (int i = 0; i < key->length; i++) {
    key->key[i] = rand() % 256;
  }
}

void encrypt_file(Key key, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return;
  }

  char buffer[1024];
  int bytes_read;

  while ((bytes_read = fread(buffer, 1, 1024, file)) > 0) {
    for (int i = 0; i < bytes_read; i++) {
      buffer[i] ^= key.key[i % key.length];
    }
    fwrite(buffer, 1, bytes_read, file);
  }

  fclose(file);
}

int main() {
  Key key;
  generate_key(&key);

  char filename[1024];
  printf("Enter file name: ");
  scanf("%s", filename);

  encrypt_file(key, filename);

  printf("File encrypted.\n");

  return 0;
}