//FormAI DATASET v1.0 Category: Image Editor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

int main(){
   char* filename;
   char* newfilename;
   int choice;
   int binary;
   FILE* file_ptr;
   FILE* newfile_ptr;
   unsigned char image[MAX_SIZE][MAX_SIZE][3];
   int filesize;
   int width;
   int height;
   int maxval;
   int x;
   int y;

   printf("Enter the image filename: ");
   scanf("%s", filename);

   file_ptr = fopen(filename, "r");

   if(file_ptr == NULL){
      printf("Error opening file.\n");
      return 1;
   }

   fscanf(file_ptr, "P3\n%d %d\n%d\n", &width, &height, &maxval);
   filesize = width * height;

   if(maxval > 255){
      printf("Error: only 8-bit images are supported.\n");
      return 1;
   }

   if(width > MAX_SIZE || height > MAX_SIZE){
      printf("Error: image dimensions are too large.\n");
      return 1;
   }

   for(x = 0; x < height; x++){
      for(y = 0; y < width; y++){
         fscanf(file_ptr, "%hhu %hhu %hhu", &image[y][x][0], &image[y][x][1], &image[y][x][2]);
      }
   }

   fclose(file_ptr);

   printf("Image loaded successfully!\n");

   do{
      printf("Select an option:\n");
      printf("1 - Convert to grayscale\n");
      printf("2 - Invert colors\n");
      printf("3 - Add noise\n");
      printf("4 - Save the image\n");
      printf("5 - Exit program\n");
      scanf("%d", &choice);

      switch(choice){
         case 1:
            for(x = 0; x < height; x++){
               for(y = 0; y < width; y++){
                  int avg = (image[y][x][0] + image[y][x][1] + image[y][x][2])/3;
                  image[y][x][0] = avg;
                  image[y][x][1] = avg;
                  image[y][x][2] = avg;
               }
            }
            printf("Image converted to grayscale.\n");
            break;
         case 2:
            for(x = 0; x < height; x++){
               for(y = 0; y < width; y++){
                  image[y][x][0] = maxval - image[y][x][0];
                  image[y][x][1] = maxval - image[y][x][1];
                  image[y][x][2] = maxval - image[y][x][2];
               }
            }
            printf("Colors inverted.\n");
            break;
         case 3:
            printf("Enter noise level (0-100): ");
            scanf("%d", &binary);
            for(x = 0; x < height; x++){
               for(y = 0; y < width; y++){
                  int rand_num = rand() % 100;
                  if(rand_num < binary){
                     int new_val = rand() % 256;
                     image[y][x][0] = new_val;
                     image[y][x][1] = new_val;
                     image[y][x][2] = new_val;
                  }
               }
            }
            printf("Noise added successfully.\n");
            break;
         case 4:
            newfilename = strdup(filename);
            strcat(newfilename, ".edit.ppm");
            newfile_ptr = fopen(newfilename, "w+");
            fprintf(newfile_ptr, "P3\n%d %d\n%d\n", width, height, maxval);
            for(x = 0; x < height; x++){
               for(y = 0; y < width; y++){
                  fprintf(newfile_ptr, "%hhu %hhu %hhu ", image[y][x][0], image[y][x][1], image[y][x][2]);
               }
               fprintf(newfile_ptr, "\n");
            }
            fclose(newfile_ptr);
            printf("Image saved as %s.\n", newfilename);
            break;
         case 5:
            printf("Goodbye!\n");
            break;
         default:
            printf("Invalid choice.\n");
            break;
      }
   } while(choice != 5);

   return 0;
}