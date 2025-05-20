//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
   char path[100], secret[100];
   FILE *originalImg, *embedImg, *secretMsg;
   unsigned char byte[1];
   int i, j, imgSize, secretSize, k = 0, bit = 1;
    
   printf("Enter path of the image you want to embed: ");
   scanf("%s", path);
    
   // Open original image in read mode
   originalImg = fopen(path, "rb");
   if(originalImg == NULL) {
      printf("Error: Could not open original image.\n");
      exit(1);
   }

   // Open the file containing the secret message
   secretMsg = fopen("secret.txt", "r");
   if(secretMsg == NULL) {
      printf("Error: Could not open secret message.\n");
      exit(1);
   }

   // Determine image size
   fseek(originalImg, 0, SEEK_END);
   imgSize = ftell(originalImg);
   fseek(originalImg, 0, SEEK_SET);

   // Create a new image file
   embedImg = fopen("embedImg.bmp", "wb");
   if(embedImg == NULL) {
      printf("Error: Could not create new image.\n");
      exit(1);
   }

   // Copy image header to new image file
   for(i=0; i<54; i++) {
      byte[0] = fgetc(originalImg);
      fputc(byte[0], embedImg);
   }

   // Calculate size of secret message
   while(fgetc(secretMsg) != EOF) {
      secretSize++;
   }
   rewind(secretMsg);

   // Embed secret message into new image file
   for(i=54; i<imgSize; i++) {
      byte[0] = fgetc(originalImg);
      if(k < secretSize) {
         secret[k] = fgetc(secretMsg);
         for(j=0; j<8; j++) {
            if(secret[k] & (1 << j)) {
               byte[0] |= bit;  // Set the last bit to 1
            } else {
               byte[0] &= ~bit; // Set the last bit to 0
            }
            bit <<= 1;
            if(bit == 256) {
               bit = 1;
               k++;
               if(k == secretSize) break;
               secret[k] = fgetc(secretMsg);
            }
         }
      }
      fputc(byte[0], embedImg);
      if(k == secretSize) {
         while(!feof(originalImg)) {
            byte[0] = fgetc(originalImg);
            fputc(byte[0], embedImg);
         }
         break;
      }
   }
   fclose(originalImg);
   fclose(embedImg);
   fclose(secretMsg);
   printf("Secret message embedded successfully!\n");
   return 0;
}