#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 4096

void handle_file(char *filename) {
   FILE *file = fopen(filename, "rb");
   char buffer[MAX_BUF];
   size_t len;

   if (!file) {
      printf("Error opening file: %s\n", filename);
      return;
   }

   printf("Uploading: %s\n", filename);

   while ((len = fread(buffer, 1, MAX_BUF, file)) > 0) {
      printf("%s", buffer);
      fwrite(buffer, 1, len, stdout);
   }

   fclose(file);
}

int main(int argc, char **argv) {
   char input[MAX_BUF];
   char *filename;

   printf("File upload handler\n");
   printf("Enter filename: ");
   scanf("%s", input); // OVERFLOW HAPPENS HERE

   filename = malloc(strlen(input) + 1);
   strcpy(filename, input);

   handle_file(filename);

   free(filename);
   return 0;
}
