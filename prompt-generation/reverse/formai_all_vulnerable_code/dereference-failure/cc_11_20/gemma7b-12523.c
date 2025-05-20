//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  char *c_ptr = buffer;

  // Read file contents into the buffer
  FILE *fp = fopen("sample.txt", "r");
  if (fp) {
    fread(buffer, MAX_BUFFER_SIZE, 1, fp);
    fclose(fp);
  }

  // Extract metadata using multivariable style
  int i = 0;
  char **metadata = NULL;
  while (c_ptr[i] && c_ptr[i] != '#') {
    char key[MAX_BUFFER_SIZE] = "";
    char value[MAX_BUFFER_SIZE] = "";
    int j = 0;
    for (; c_ptr[i] && !isspace(c_ptr[i]) && c_ptr[i] != '#'; i++) {
      key[j] = c_ptr[i];
      j++;
    }

    i++;
    for (; c_ptr[i] && isspace(c_ptr[i]); i++) {}

    value[0] = '\0';
    j = 0;
    for (; c_ptr[i] && !isspace(c_ptr[i]) && c_ptr[i] != '#'; i++) {
      value[j] = c_ptr[i];
      j++;
    }

    metadata = realloc(metadata, (i + 1) * sizeof(char *));
    metadata[i] = strdup(key);
    metadata[i + 1] = strdup(value);
  }

  // Print extracted metadata
  for (i = 0; metadata[i]; i++) {
    printf("%s: %s\n", metadata[i], metadata[i + 1]);
  }

  // Free memory
  free(metadata);

  return 0;
}