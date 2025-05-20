//FormAI DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IMAGE_SIZE 100

struct Image {
  int width;
  int height;
  int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
};

// function to print the image
void printImage(struct Image *image) {
  for (int row = 0; row < image->height; row++) {
    for (int col = 0; col < image->width; col++) {
      printf("%d ", image->pixels[row][col]);
    }
    printf("\n");
  }
}

// function to flip the image horizontally
void flipHorizontal(struct Image *image) {
  for (int row = 0; row < image->height; row++) {
    for (int col = 0; col < image->width / 2; col++) {
      int temp = image->pixels[row][col];
      image->pixels[row][col] = image->pixels[row][image->width - col - 1];
      image->pixels[row][image->width - col - 1] = temp;
    }
  }
}

// function to invert the image colors
void invertColors(struct Image *image) {
  for (int row = 0; row < image->height; row++) {
    for (int col = 0; col < image->width; col++) {
      image->pixels[row][col] = 255 - image->pixels[row][col];
    }
  }
}

int main() {
  struct Image image;
  bool done = false;
  char command[20];

  // read in the dimensions of the image
  scanf("%d %d", &image.width, &image.height);

  // read in the pixel values of the image
  for (int row = 0; row < image.height; row++) {
    for (int col = 0; col < image.width; col++) {
      scanf("%d", &image.pixels[row][col]);
    }
  }

  // loop until user enters 'exit' command
  while (!done) {
    scanf("%s", command);

    if (strcmp(command, "print") == 0) {
      printImage(&image);
    }
    else if (strcmp(command, "flip") == 0) {
      flipHorizontal(&image);
    }
    else if (strcmp(command, "invert") == 0) {
      invertColors(&image);
    }
    else if (strcmp(command, "exit") == 0) {
      done = true;
    }
    else {
      printf("Invalid command\n");
    }
  }

  return 0;
}