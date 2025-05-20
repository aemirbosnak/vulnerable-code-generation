//FormAI DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

void main()
{
   FILE *fptr1, *fptr2, *fptr3;
   char filename[100], byte1, byte2, byte3;
   int i, filesize;

   printf("Enter the source image filename: ");
   scanf("%s",filename);

   fptr1 = fopen(filename, "rb");
   if(fptr1 == NULL)
   {
      printf("Error: Could not open %s", filename);
      exit(1);
   }

   fptr2 = fopen("secret.txt", "rb");
   if(fptr2 == NULL)
   {
      printf("Error: Could not open secret.txt");
      fclose(fptr1);
      exit(1);
   }

   fptr3 = fopen("output.bmp", "wb");
   if(fptr3 == NULL)
   {
      printf("Error: Could not open output.bmp");
      fclose(fptr1);
      fclose(fptr2);
      exit(1);
   }

   // get file size
   fseek(fptr1, 0, SEEK_END);
   filesize = ftell(fptr1);
   fseek(fptr1, 0, SEEK_SET);

   // copy header to output file
   for(i=0; i<54; i++)
   {
      byte1 = getc(fptr1);
      putc(byte1, fptr3);
   }

   // copy secret message size to output file
   fseek(fptr2, 0, SEEK_END);
   filesize = ftell(fptr2);
   fseek(fptr2, 0, SEEK_SET);
   byte1 = filesize & 0xff;
   byte2 = (filesize >> 8) & 0xff;
   byte3 = (filesize >> 16) & 0xff;
   putc(byte1, fptr3);
   putc(byte2, fptr3);
   putc(byte3, fptr3);

   // copy secret message to output file
   for(i=0; i<filesize; i++)
   {
      byte1 = getc(fptr2);
      putc(byte1, fptr3);
   }

   // copy remaining bytes from source image to output file
   while((byte1 = getc(fptr1)) != EOF)
      putc(byte1, fptr3);

   printf("Operation completed successfully.");
   fclose(fptr1);
   fclose(fptr2);
   fclose(fptr3);
   return;
}