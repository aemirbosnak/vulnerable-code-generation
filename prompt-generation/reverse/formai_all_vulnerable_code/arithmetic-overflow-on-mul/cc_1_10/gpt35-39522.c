//FormAI DATASET v1.0 Category: Image Editor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define constant values
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Declare function prototypes
void print_menu();
void draw_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void invert_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void flip_image_horizontal(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void blur_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height);

int main() {
  int image[MAX_HEIGHT][MAX_WIDTH];
  int width, height;
  int choice;

  // Ask for image dimensions
  printf("Enter image dimensions (width height): ");
  scanf("%d %d", &width, &height);

  // Ask for image data
  printf("Enter image data:\n");
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      scanf("%d", &image[i][j]);
    }
  }

  // Display menu and ask for choice
  do {
    print_menu();
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        draw_image(image, width, height);
        break;
      case 2:
        invert_image(image, width, height);
        break;
      case 3:
        flip_image_horizontal(image, width, height);
        break;
      case 4:
        blur_image(image, width, height);
        break;
      case 5:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice! Try again.\n");
    }
  } while (choice != 5);

  return 0;
}

void print_menu() {
  printf("Image Editor\n");
  printf("1. Draw image\n");
  printf("2. Invert image\n");
  printf("3. Flip image horizontally\n");
  printf("4. Blur image\n");
  printf("5. Exit\n");
}

void draw_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
  printf("Image:\n");
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d ", image[i][j]);
    }
    printf("\n");
  }
}

void invert_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j] = 255 - image[i][j]; // Invert color by subtracting from 255
    }
  }
  printf("Image inverted!\n");
}

void flip_image_horizontal(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width/2; j++) {
      int temp = image[i][j];
      image[i][j] = image[i][width-1-j];
      image[i][width-1-j] = temp;
    }
  }
  printf("Image flipped horizontally!\n");
}

void blur_image(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
  int kernel[3][3] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}}; // Define blur kernel
  int kernel_sum = 16;
  int temp[MAX_HEIGHT][MAX_WIDTH]; // Temporary image
  // Convolve the image with the blur kernel
  for (int i = 1; i < height-1; i++) {
    for (int j = 1; j < width-1; j++) {
      int sum = 0;
      for (int i2 = -1; i2 <= 1; i2++) {
        for (int j2 = -1; j2 <= 1; j2++) {
          sum += image[i+i2][j+j2] * kernel[i2+1][j2+2];
        }
      }
      temp[i][j] = sum / kernel_sum;
    }
  }
  // Copy the temporary image back to the original image
  for (int i = 1; i < height-1; i++) {
    for (int j = 1; j < width-1; j++) {
      image[i][j] = temp[i][j];
    }
  }
  printf("Image blurred!\n");
}