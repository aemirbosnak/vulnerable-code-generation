//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BOOK_LENGTH 10000

int isFileExists(char *filename) {
   FILE *file;
   int status = 0;

   file = fopen(filename, "r");

   if (file != NULL) {
      status = 1;
      fclose(file);
   }

   return status;
}

void readBook(char *filename) {
   FILE *file;
   char book[MAX_BOOK_LENGTH];

   file = fopen(filename, "r");

   if (file == NULL) {
      printf("Error: Could not open file.\n");
      return;
   }

   fscanf(file, "%[^\n]", book);
   fclose(file);

   printf("BOOK CONTENTS:\n%s\n", book);

   return;
}

int main() {
   char filename[MAX_FILENAME_LENGTH];
   int bookExists = 0;

   printf("Welcome to Paranoia Ebook Reader!\n\n");

   while (1) {
      printf("Enter the name of the Ebook file to open: ");
      scanf("%s", filename);

      if (!isFileExists(filename)) {
          printf("Error: The file \"%s\" does not exist.\n", filename);
          break;
      } 

      printf("\nPARANOID ALERT: Before you read the book, please confirm that this book is not infected by any malware or virus.\n");
      printf("Type 1 to continue or Type 0 to quit: ");
      int confirmation;
      scanf("%d", &confirmation);

      if (confirmation == 0) {
          printf("\nYou are paranoid but wise. Exiting the program. Goodbye!\n");
          break;
      } else if (confirmation == 1) {
          printf("\nPARANOID ALERT: You are about to read the Ebook content. This could contain harmful content. Proceed with extreme caution.\n");
          readBook(filename);
          printf("\nThank you for using Paranoia Ebook Reader!\n");
          break;
      } else {
          printf("\nInvalid input. Try again.\n");
      }
   }

   return 0;
}