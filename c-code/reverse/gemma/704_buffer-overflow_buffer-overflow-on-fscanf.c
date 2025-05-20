#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int classifyImage(char *image_path) {
  FILE *fp = fopen(image_path, "r");
  if (fp == NULL) {
    return -1;
  }

  char label[1024];
  fscanf(fp, "%s", label);

  fclose(fp);

  return strcmp(label, "apple") == 0 ? 0 : -1;
}

int main() {
  char image_path[] = "image.jpg";
  int classification_result = classifyImage(image_path);

  if (classification_result == 0) {
    printf("Image classified as apple.\n");
  } else {
    printf("Error classifying image.\n");
  }

  return 0;
}
