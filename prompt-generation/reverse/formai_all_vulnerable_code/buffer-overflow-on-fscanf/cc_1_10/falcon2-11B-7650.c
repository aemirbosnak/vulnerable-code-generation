//Falcon2-11B DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

int main(void) {
   FILE *file;
   char line[100];
   char *lines[100];
   int numLines = 0;
   int i;

   file = fopen("hello.txt", "r");
   if (file == NULL) {
      fprintf(stderr, "Error opening file\n");
      exit(1);
   }

   while (fscanf(file, "%s", line)!= EOF) {
      lines[numLines++] = line;
   }
   fclose(file);

   if (numLines == 0) {
      fprintf(stderr, "No lines in file\n");
      exit(1);
   }

   numLines = numLines / 2;

   file = fopen("hello.txt", "w");
   if (file == NULL) {
      fprintf(stderr, "Error opening file\n");
      exit(1);
   }

   for (i = 0; i < numLines; i++) {
      fseek(file, 0, SEEK_SET);
      fputs(lines[numLines - i - 1], file);
   }
   fclose(file);

   file = fopen("hello.txt", "r");
   if (file == NULL) {
      fprintf(stderr, "Error opening file\n");
      exit(1);
   }

   while (fscanf(file, "%s", line)!= EOF) {
      printf("%s\n", line);
   }
   fclose(file);

   return 0;
}