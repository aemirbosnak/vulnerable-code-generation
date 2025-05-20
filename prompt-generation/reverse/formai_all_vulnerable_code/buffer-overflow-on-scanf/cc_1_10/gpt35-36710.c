//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   printf("Surprise! Welcome to the C File Encryptor\n\n");

   char filename[30], encryptfilename[30];
   printf("Enter the name of the file you want to encrypt: ");
   scanf("%s", filename);
   printf("\n");

   // Open the input file
   FILE *file = fopen(filename, "rb");
   if (!file)
   {
      printf("Error opening input file %s", filename);
      return 1;
   }

   // Create the output file
   strcpy(encryptfilename, "encrypted_");
   strcat(encryptfilename, filename);
   FILE *encryptfile = fopen(encryptfilename, "wb");
   if (!encryptfile)
   {
      printf("Error creating encrypted file %s", encryptfilename);
      return 1;
   }
   printf("Created encrypted file %s\n", encryptfilename);

   // Generate a random key
   int key = rand() % 1000 + 1;
   printf("Key: %d\n", key);

   // Encrypt the file
   int byte;
   while ((byte = fgetc(file)) != EOF)
   {
      int newbyte = byte ^ key;
      fputc(newbyte, encryptfile);
   }

   printf("File has been encrypted!\n");

   fclose(file);
   fclose(encryptfile);

   return 0;
}