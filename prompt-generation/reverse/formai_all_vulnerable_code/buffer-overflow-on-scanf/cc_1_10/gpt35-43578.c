//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
/* This program demonstrates the use of file handling in C. 
   It reads data from an input file, does some processing on it, and writes the output to an output file */

#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *input_file, *output_file;
   char input_filename[50], output_filename[50], temp;
   int count = 0;

   /* Prompt user to enter input filename */
   printf("Enter the name of the input file: ");
   scanf("%s", input_filename);

   /* Open input file in read mode */
   input_file = fopen(input_filename, "r");

   /* If input file not found, display error message and exit */
   if (input_file == NULL) {
      printf("Error: File not found.\n");
      exit(EXIT_FAILURE);
   }

   /* Prompt user to enter output filename */
   printf("Enter the name of the output file: ");
   scanf("%s", output_filename);

   /* Open output file in write mode */
   output_file = fopen(output_filename, "w");

   /* Read characters from input file and write to output file in reverse order */
   fseek(input_file, 0, SEEK_END); // move file pointer to end of file
   count = ftell(input_file); // get size of input file
   fseek(input_file, -1, SEEK_CUR); // move file pointer to last character

   while (count > 0) {
      temp = fgetc(input_file);
      fputc(temp, output_file);
      fseek(input_file, -2, SEEK_CUR);
      count--;
   }

   printf("File processed successfully.\n");

   /* Close both files */
   fclose(input_file);
   fclose(output_file);
   
   return 0;
}