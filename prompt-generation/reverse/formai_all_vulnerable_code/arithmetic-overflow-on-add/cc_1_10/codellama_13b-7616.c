//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Custom compression algorithm
  void compress(char *input, char *output) {
    int i, j;
    int count = 1;
    char last_char = input[0];
    for (i = 1; i < strlen(input); i++) {
      if (input[i] == last_char) {
        count++;
      } else {
        output[j++] = last_char;
        output[j++] = count + '0';
        count = 1;
        last_char = input[i];
      }
    }
    output[j++] = last_char;
    output[j++] = count + '0';
    output[j] = '\0';
  }

  // Custom decompression algorithm
  void decompress(char *input, char *output) {
    int i, j;
    int count;
    char last_char = input[0];
    for (i = 1; i < strlen(input); i++) {
      if (input[i] >= '0' && input[i] <= '9') {
        count = input[i] - '0';
        for (j = 0; j < count; j++) {
          output[j] = last_char;
        }
        i++;
      } else {
        output[j++] = input[i];
        last_char = input[i];
      }
    }
    output[j] = '\0';
  }

  int main() {
    char input[] = "aabbccdd";
    char output[100];
    compress(input, output);
    printf("Compressed string: %s\n", output);
    decompress(output, input);
    printf("Decompressed string: %s\n", input);
    return 0;
  }