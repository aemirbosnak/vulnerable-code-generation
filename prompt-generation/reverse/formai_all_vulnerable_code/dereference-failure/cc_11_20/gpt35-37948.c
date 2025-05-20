//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
/* Ada's Antivirus Scanner in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000  // Maximum file size that can be scanned

int main(int argc, char *argv[]) {
   char *filename;
   FILE *fp;
   char buffer[MAX_FILE_SIZE];
   int i, file_size;
   int virus_detected = 0;

   if (argc != 2) {
      printf("Usage: %s <filename>\n", argv[0]);
      return 1;
   }

   filename = argv[1];

   fp = fopen(filename, "rb");
   if (fp == NULL) {
      printf("Error: File not found\n");
      return 1;
   }

   fseek(fp, 0, SEEK_END);
   file_size = ftell(fp);
   fseek(fp, 0, SEEK_SET);

   if (file_size > MAX_FILE_SIZE) {
      printf("Error: File too large\n");
      return 1;
   }

   fread(buffer, file_size, 1, fp);
   fclose(fp);

   for (i = 0; i < file_size - 3; i++) {
      if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && buffer[i+3] == 'u' && buffer[i+4] == 's') {
         printf("Virus detected at position %d\n", i);
         virus_detected = 1;
      }
   }

   if (!virus_detected) {
      printf("File is clean\n");
   }

   return 0;
}