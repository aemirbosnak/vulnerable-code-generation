//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// Function to display options menu and get user choice
int getChoice() {
   int choice;
   printf("\n--Menu--\n");
   printf("1. Grayscale\n");
   printf("2. Invert\n");
   printf("3. Blur\n");
   printf("4. Rotate 90 degrees\n");
   printf("5. Flip Horizontally\n");
   printf("6. Flip Vertically\n");
   printf("7. Exit\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);
   return choice;
}

int main() {
   FILE *inFile, *outFile;
   char inName[50], outName[50];
   unsigned char *imageData, *newData, *tempData;
   int width, height;
   int choice;
   bool running = true;

   printf("Enter input image file name: ");
   scanf("%s", inName);

   // Check if input file exists
   if ((inFile = fopen(inName, "rb")) == NULL) {
      printf("Error: File not found.\n");
      exit(1);
   }

   // Read header data
   fscanf(inFile, "P6\n%d %d\n255\n", &width, &height);

   // Allocate memory for imageData array
   imageData = (unsigned char *)malloc(3 * width * height);
   fread(imageData, sizeof(unsigned char), 3 * width * height, inFile);

   // Close input file
   fclose(inFile);

   while (running) {
      // Display options menu and get user choice
      choice = getChoice();

      switch (choice) {
         case 1: // Grayscale
            newData = (unsigned char *)malloc(width * height);
            for (int i = 0; i < width * height * 3; i += 3) {
               newData[i/3] = (imageData[i] + imageData[i+1] + imageData[i+2]) / 3;
            }
            tempData = imageData;
            imageData = newData;
            newData = tempData;
            free(newData);
            break;

         case 2: // Invert
            newData = (unsigned char *)malloc(3 * width * height);
            for (int i = 0; i < width * height * 3; i++) {
               newData[i] = 255 - imageData[i];
            }
            tempData = imageData;
            imageData = newData;
            newData = tempData;
            free(newData);
            break;

         case 3: // Blur
            newData = (unsigned char *)malloc(3 * width * height);
            for (int i = 0; i < width; i++) {
               for (int j = 0; j < height; j++) {
                  int red = 0, green = 0, blue = 0;
                  int count = 0;
                  for (int ii = -1; ii <= 1; ii++) {
                     for (int jj = -1; jj <= 1; jj++) {
                        if ((i + ii >= 0) && (i + ii < width) && (j + jj >= 0) && (j + jj < height)) {
                           red += imageData[((j+jj)*width+(i+ii))*3];
                           green += imageData[((j+jj)*width+(i+ii))*3+1];
                           blue += imageData[((j+jj)*width+(i+ii))*3+2];
                           count++;
                        }
                     }
                  }
                  newData[(j*width+i)*3] = red/count;
                  newData[(j*width+i)*3+1] = green/count;
                  newData[(j*width+i)*3+2] = blue/count;
               }
            }
            tempData = imageData;
            imageData = newData;
            newData = tempData;
            free(newData);
            break;

         case 4: // Rotate 90 degrees
            newData = (unsigned char *)malloc(3 * width * height);
            for (int i = 0; i < height; i++) {
               for (int j = 0; j < width; j++) {
                  newData[(j*height+i)*3] = imageData[((height-i-1)*width+j)*3];
                  newData[(j*height+i)*3+1] = imageData[((height-i-1)*width+j)*3+1];
                  newData[(j*height+i)*3+2] = imageData[((height-i-1)*width+j)*3+2];
               }
            }
            tempData = imageData;
            imageData = newData;
            newData = tempData;
            free(newData);
            // Swap width and height
            int temp = width;
            width = height;
            height = temp;
            break;

         case 5: // Flip horizontally
            newData = (unsigned char *)malloc(3 * width * height);
            for (int i = 0; i < height; i++) {
               for (int j = 0; j < width; j++) {
                  newData[(i*width+(width-j-1))*3] = imageData[(i*width+j)*3];
                  newData[(i*width+(width-j-1))*3+1] = imageData[(i*width+j)*3+1];
                  newData[(i*width+(width-j-1))*3+2] = imageData[(i*width+j)*3+2];
               }
            }
            tempData = imageData;
            imageData = newData;
            newData = tempData;
            free(newData);
            break;

         case 6: // Flip vertically
            newData = (unsigned char *)malloc(3 * width * height);
            for (int i = 0; i < height; i++) {
               for (int j = 0; j < width; j++) {
                  newData[((height-i-1)*width+j)*3] = imageData[(i*width+j)*3];
                  newData[((height-i-1)*width+j)*3+1] = imageData[(i*width+j)*3+1];
                  newData[((height-i-1)*width+j)*3+2] = imageData[(i*width+j)*3+2];
               }
            }
            tempData = imageData;
            imageData = newData;
            newData = tempData;
            free(newData);
            break;

         case 7: // Exit
            running = false;
            break;

         default: // Invalid choice
            printf("\nInvalid choice. Please try again.\n");
            break;
      }

      if (running) {
         // Make output file name
         sprintf(outName, "output_%d.ppm", choice);

         // Open output file
         outFile = fopen(outName, "wb");

         // Write header data
         fprintf(outFile, "P6\n%d %d\n255\n", width, height);

         // Write image data
         fwrite(imageData, sizeof(unsigned char), 3 * width * height, outFile);

         // Close output file
         fclose(outFile);

         // Wait one second before continuing
         sleep(1);
      }
   }

   // Free memory for imageData array
   free(imageData);

   return 0;
}