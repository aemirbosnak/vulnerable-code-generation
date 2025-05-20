//FormAI DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>

int main() {
  printf("Welcome to the Puzzling Image Editor\n");
  printf("Please enter the name of the image file you wish to edit: ");
  char file_name[50];
  scanf("%s", file_name);
  
  FILE* image = fopen(file_name, "r");

  if (image == NULL) {
    printf("Error opening file. Please try again.\n");
    return 1;
  }

  printf("File opened successfully.\n");
  printf("Please enter the desired image edit option:\n");
  printf("1. Invert colors\n");
  printf("2. Flip horizontally\n");
  printf("3. Add noise\n");
  printf("4. Blur\n");

  int edit_option;
  scanf("%d", &edit_option);

  switch (edit_option) {
    case 1:
      printf("Inverting colors...\n");
      // code for inverting colors
      break;
    case 2:
      printf("Flipping image horizontally...\n");
      // code for flipping image horizontally
      break;
    case 3:
      printf("Adding noise to image...\n");
      // code for adding noise to image
      break;
    case 4:
      printf("Blurring image...\n");
      // code for blurring image
      break;
    default:
      printf("Invalid option. Please choose a valid option.\n");
      return 1;
  }

  printf("Image successfully edited. Do you want to save the changes? (Y/N)\n");

  char save_option;
  scanf(" %c", &save_option);

  if (save_option == 'Y' || save_option == 'y') {
    printf("Saving changes...\n");
    // code for saving changes to file
  } else if (save_option == 'N' || save_option == 'n') {
    printf("Changes not saved.\n");
  } else {
    printf("Invalid option. Changes not saved.\n");
  }

  fclose(image);

  printf("Thank you for using the Puzzling Image Editor.\n");
  return 0;
}