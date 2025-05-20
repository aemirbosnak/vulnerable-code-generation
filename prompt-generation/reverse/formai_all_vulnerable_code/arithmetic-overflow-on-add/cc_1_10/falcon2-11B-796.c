//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
   char imgName[100], imgContent[10000];
   int imgWidth, imgHeight, imgSize, i, j;
   FILE *imgFile;

   printf("Enter image name: ");
   fgets(imgName, 100, stdin);
   imgName[strcspn(imgName, "\n")] = '\0';

   imgFile = fopen(imgName, "r");
   if (imgFile == NULL) {
      printf("Error opening image file.\n");
      exit(EXIT_FAILURE);
   }

   imgWidth = 0;
   imgHeight = 0;
   imgSize = 0;

   while (!feof(imgFile)) {
      char line[100];
      fgets(line, 100, imgFile);
      if (line[0] == '\n')
         continue;
      if (strstr(line, "Image width="))
         sscanf(line, "Image width=%d", &imgWidth);
      if (strstr(line, "Image height="))
         sscanf(line, "Image height=%d", &imgHeight);
      if (strstr(line, "Image size="))
         sscanf(line, "Image size=%d", &imgSize);
      if (strstr(line, "Image type="))
         sscanf(line, "Image type=%c", &imgContent[i]);
      if (strstr(line, "Image data="))
         sscanf(line, "Image data=%d", &imgContent[j]);
      i++;
      j++;
   }

   fclose(imgFile);

   printf("Image width: %d\n", imgWidth);
   printf("Image height: %d\n", imgHeight);
   printf("Image size: %d\n", imgSize);
   printf("Image type: %c\n", imgContent[0]);
   printf("Image data: %d\n", imgContent[1]);

   return 0;
}