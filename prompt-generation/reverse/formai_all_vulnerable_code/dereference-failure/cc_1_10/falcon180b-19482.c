//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc!= 3) {
    printf("Usage: %s <file> <output>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  char *buffer = malloc(MAX_SIZE);
  if (buffer == NULL) {
    printf("Memory allocation error\n");
    return 1;
  }

  char *output = malloc(MAX_SIZE);
  if (output == NULL) {
    printf("Memory allocation error\n");
    return 1;
  }

  int size = 0;
  int checksum = 0;
  while ((size = fread(buffer, 1, MAX_SIZE, fp)) > 0) {
    for (int i = 0; i < size; i++) {
      checksum += buffer[i];
    }
  }

  sprintf(output, "Checksum: %d\n", checksum);

  fclose(fp);
  FILE *op = fopen(argv[2], "wb");
  if (op == NULL) {
    printf("Error opening output file %s\n", argv[2]);
    return 1;
  }

  fwrite(output, strlen(output), 1, op);
  fclose(op);

  free(buffer);
  free(output);

  return 0;
}