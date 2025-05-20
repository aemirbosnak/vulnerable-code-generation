//FormAI DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 10000 // Maximum size of image

/* Function to get the size of the image */
int getImageSize(char *filename) {
  FILE *fp = fopen(filename, "rb"); // Open the file in binary mode
  if (fp == NULL) { 
    printf("Error: Unable to open the file\n"); 
    return -1; 
  }
  fseek(fp, 0L, SEEK_END); // Move the file indicator to the end
  int size = ftell(fp); // Get the size of the file in bytes
  fclose(fp); // Close the file
  return size;
}

/* Function to hide the message in the image */
void hideMessage(char *imageName, char *message) {
  FILE *fp = fopen(imageName, "rb+"); // Open the image in read-write mode
  if (fp == NULL) { 
    printf("Error: Unable to open the file\n"); 
    return; 
  }

  int imageSize = getImageSize(imageName); // Get the size of the image
  if (imageSize == -1) { // Return if there is an error with the image file
    return;
  }
  
  int i, j, k = 0; 
  char c, byte;
  
  for (i = 0; i < strlen(message) + 1; i++) { // Loop through each character in the message
    c = message[i]; // Get the ith character from the message
    
    for (j = 0; j < 8; j++) { // Loop through each bit in the character
      byte = fgetc(fp);
    
      if (feof(fp)) { // Return if the end of the file is reached
        printf("Error: Image is not large enough to hide the message\n");
        fclose(fp);
        return;
      }
      
      if (k < imageSize - 1) { // Check if there is still space in the image to hide the message
        byte = (byte & 0xFE) | ((c >> j) & 0x01); 
        fseek(fp, -1L, SEEK_CUR);
        fputc(byte, fp);
        k++;
      }
    }
  }
  
  fclose(fp); // Close the image
  printf("\nMessage hidden successfully in the image!\n");
}

/* Function to retrieve the message from the image */
void retrieveMessage(char *imageName) {
  FILE *fp = fopen(imageName, "rb"); // Open the image in read mode
  if (fp == NULL) { 
    printf("Error: Unable to open the file\n"); 
    return; 
  }

  int i, j, k = 0; 
  char byte, c = 0;
  
  for (i = 0; i < MAX_IMAGE_SIZE; i++) { // Loop through the bytes in the image
    byte = fgetc(fp);
    if (feof(fp)) { // Return if the end of the file is reached
      break;
    }
    for (j = 0; j < 8; j++) { // Loop through each bit in the byte
      c = c | ((byte >> j) & 0x01) << k;
      k++;
      if (k == 8) { // If a full character has been extracted
        k = 0;
        if (c == '\0') { // Check if the end of the message has been reached
          fclose(fp); // Close the image
          printf("\nMessage retrieved successfully from the image!\n");
          return;
        }
        printf("%c", c); // Print the extracted character
        c = 0;
      }
    }
  }
  fclose(fp); // Close the image
  printf("\nMessage not found in the image\n");
}

/* Main function */
int main() {
  char imageName[100], message[100];
  int choice;

  printf("\n----------- Image Steganography Program -----------\n");

  while (1) {
    printf("\nEnter your choice:\n1. Hide message\n2. Retrieve message\n3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter the name/path of the image file: ");
        scanf("%s", imageName);
        printf("\nEnter the message to be hidden: ");
        scanf(" %[^\n]s", message);
        hideMessage(imageName, message);
        break;
      case 2:
        printf("\nEnter the name/path of the image file: ");
        scanf("%s", imageName);
        retrieveMessage(imageName);
        break;
      case 3:
        exit(0);
      default:
        printf("\nInvalid choice!\n");
        break;
    }
  }

  return 0;
}