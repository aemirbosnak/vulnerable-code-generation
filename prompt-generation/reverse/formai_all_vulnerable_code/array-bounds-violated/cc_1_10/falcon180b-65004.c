//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 16
#define MAX_LINE_LEN 1024

void encrypt(char* file_path, char* key) {
  FILE* file;
  char line[MAX_LINE_LEN];
  char encrypted_line[MAX_LINE_LEN];
  int len;

  file = fopen(file_path, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", file_path);
    exit(1);
  }

  while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
    len = strlen(line);
    if (line[len - 1] == '\n') {
      line[len - 1] = '\0';
    }

    for (int i = 0; i < len; i++) {
      encrypted_line[i] = line[i] ^ key[i % KEY_LEN];
    }

    encrypted_line[len] = '\n';
    encrypted_line[len + 1] = '\0';

    fwrite(encrypted_line, strlen(encrypted_line), 1, file);
  }

  fclose(file);
}

int main(int argc, char** argv) {
  if (argc!= 3) {
    printf("Usage: %s <file_path> <key>\n", argv[0]);
    exit(1);
  }

  char* file_path = argv[1];
  char* key = argv[2];

  encrypt(file_path, key);

  printf("File encrypted successfully!\n");

  return 0;
}