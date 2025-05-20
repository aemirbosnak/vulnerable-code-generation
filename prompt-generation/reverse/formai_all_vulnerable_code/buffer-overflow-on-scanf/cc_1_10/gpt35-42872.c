//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to the hilariously simple C Basic Image Processing program!\n");

  // Load image
  char imageFile[50];
  printf("Please enter the image file path: ");
  scanf("%s", imageFile);
  printf("Loading image from file: %s\n", imageFile);

  // Display image dimensions
  int imageWidth = 128;
  int imageHeight = 128;
  printf("Image dimensions: %d x %d\n", imageWidth, imageHeight);

  // Flip image horizontally or vertically
  char flipDirection;
  printf("Do you want to flip the image horizontally (H) or vertically (V)? ");
  scanf(" %c", &flipDirection);
  if (flipDirection == 'H') {
    printf("Flipping image horizontally...\n");
  } else if (flipDirection == 'V') {
    printf("Flipping image vertically...\n");
  } else {
    printf("Invalid input, defaulting to no flipping.\n");
  }

  // Adjust brightness
  int brightness;
  printf("Enter brightness adjustment value (-255 to 255): ");
  scanf("%d", &brightness);
  printf("Adjusting brightness by %d...\n", brightness);

  // Adjust contrast
  float contrast;
  printf("Enter contrast adjustment value (0.1 to 10.0): ");
  scanf("%f", &contrast);
  printf("Adjusting contrast by %.1f...\n", contrast);

  // Save image
  char saveFile[50];
  printf("Please enter the file path to save the processed image: ");
  scanf("%s", saveFile);
  printf("Saving processed image to file: %s\n", saveFile);

  // Display funny message
  printf("Congratulations, you have successfully processed an image!\n");
  printf("As a reward, here is a joke:\n");
  printf("Why did the tomato turn red? Because it saw the salad dressing!\n");

  return 0;
}