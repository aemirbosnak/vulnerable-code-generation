//FormAI DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of characters 
#define MAX_CHARACTERS 100

int main() {

   char filename[MAX_CHARACTERS];

   // Prompt user to enter file name 
   printf("Enter the file name: ");
   scanf("%s", filename);

   // Open the file and check if it exists
   FILE *file_ptr = fopen(filename, "r");
   if (file_ptr == NULL) {
      printf("File '%s' not found.\n", filename);
      return 1; // Exit program if file is not found
   }

   // If the file exists, read and print each line
   printf("Reading from '%s'...\n", filename);
   char line[MAX_CHARACTERS];
   while (fgets(line, MAX_CHARACTERS, file_ptr) != NULL) {
      printf("%s", line);
   }

   // Close the file when finished
   fclose(file_ptr);

   // Prompt user to enter some text to append to file
   printf("Enter some text to append to the file: ");
   char text[MAX_CHARACTERS];
   scanf(" %[^\n]", text);

   // Open the file in append mode
   file_ptr = fopen(filename, "a");
   if (file_ptr == NULL) {
      printf("Error opening file.\n");
      return 1; // Exit program if file cannot be opened
   }

   // Write the input text to the file and close it
   printf("Appending text to '%s'...\n", filename);
   fprintf(file_ptr, "\n%s", text);
   fclose(file_ptr);

   printf("Text successfully appended to '%s'.\n", filename);

   return 0; // Exit program successfully
}