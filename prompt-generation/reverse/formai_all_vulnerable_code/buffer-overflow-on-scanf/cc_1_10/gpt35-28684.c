//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char* fname);
void decryptFile(char* fname);
void XORcrypt(FILE *f, const char *key);

int main(int argc, char* argv[]) {
   // Get input file name from user
   char fname[100];
   printf("Enter the file name: ");
   scanf("%s", fname);

   // Call the encryption function
   encryptFile(fname);
   printf("Encryption successful!\n");

   // Call the decryption function
   decryptFile(fname);
   printf("Decryption successful!\n");

   return 0;
}

void encryptFile(char* fname) {
   // Open file for reading
   FILE *f = fopen(fname, "rb");
   if (f == NULL) {
      printf("Error opening file!\n");
      return;
   }

   // Open a new file for writing
   char newfname[100];
   sprintf(newfname, "encrypted_%s", fname);
   FILE *ef = fopen(newfname, "wb");
   if (f == NULL) {
      printf("Error opening file!\n");
      return;
   }

   // Get encryption key from user
   char key[256];
   printf("Enter encryption key: ");
   scanf("%s", key);

   // Encrypt file
   XORcrypt(f, key); 
   fwrite(key, strlen(key) + 1, 1, ef); 
   fclose(f);
   fclose(ef);
}

void decryptFile(char* fname) {
   // Open file for reading
   FILE *f = fopen(fname, "rb");
   if (f == NULL) {
      printf("Error opening file!\n");
      return;
   }

   // Get encryption key from user
   char key[256];
   printf("Enter encryption key: ");
   scanf("%s", key);

   // Decrypt file
   XORcrypt(f, key); 

   // Open a new file for writing
   char newfname[100];
   sprintf(newfname, "decrypted_%s", fname);
   FILE *df = fopen(newfname, "wb");
   if (f == NULL) {
      printf("Error opening file!\n");
      return;
   }

   // Write decrypted data to file
   char buffer[1024];
   int bytes_read;
   while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), f)) > 0) {
      fwrite(buffer, sizeof(char), bytes_read, df);
   }

   fclose(f);
   fclose(df);
}

void XORcrypt(FILE *f, const char *key) {
   // XOR each byte in file with corresponding byte in key
   int keylen = strlen(key);
   char c;
   int i = 0;
   while (fread(& c, sizeof(char), 1, f) > 0) {
      c ^= key[i % keylen];
      fseek(f, -1, SEEK_CUR);
      fwrite(& c, sizeof(char), 1, f);
      i++;
   }
}