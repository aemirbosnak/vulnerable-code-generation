//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
  char input[MAX_SIZE];
  char output[MAX_SIZE];
  int i, j;

  printf("Enter the message to be encoded: ");
  scanf("%s", input);

  printf("Enter the image file name: ");
  scanf("%s", output);

  FILE *fp = fopen(output, "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  char *image = malloc(MAX_SIZE * sizeof(char));
  if (image == NULL) {
    printf("Error allocating memory!\n");
    return 1;
  }

  fread(image, sizeof(char), MAX_SIZE, fp);
  fclose(fp);

  for (i = 0, j = 0; input[i] != '\0'; i++, j++) {
    image[j] ^= input[i];
  }

  fp = fopen(output, "w");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  fwrite(image, sizeof(char), MAX_SIZE, fp);
  fclose(fp);

  free(image);

  printf("Steganography successful!\n");

  return 0;
}