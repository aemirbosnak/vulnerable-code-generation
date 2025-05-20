//FormAI DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 10485760 // 10 MB

int main()
{
   char filename[MAX_FILENAME_LENGTH];
   printf("Enter the name of the file to recover: ");
   scanf("%s", filename);

   // open the file in binary read mode
   FILE* file = fopen(filename, "rb");

   if (file == NULL)
   {
      printf("Error: File not found.\n");
      return 1;
   }

   // allocate memory to store the file contents
   char* file_contents = (char*) malloc(MAX_FILE_SIZE * sizeof(char));
   if (file_contents == NULL)
   {
      printf("Error: Memory allocation failed.\n");
      fclose(file);
      return 1;
   }

   int file_size = fread(file_contents, sizeof(char), MAX_FILE_SIZE, file);
   fclose(file);

   if (file_size == 0)
   {
      printf("Error: File is empty.\n");
      free(file_contents);
      return 1;
   }

   for (int i = 0; i < file_size; i++)
   {
      if (file_contents[i] < 32 || file_contents[i] > 126)
      {
         file_contents[i] = ' '; // replace non-printable characters with spaces
      }
   }

   // create a new file with recovered contents
   char new_filename[MAX_FILENAME_LENGTH + 5]; // add .txt extension
   strcpy(new_filename, filename);
   strcat(new_filename, ".txt");

   FILE* new_file = fopen(new_filename, "w");

   if (new_file == NULL)
   {
      printf("Error: Could not create new file.\n");
      free(file_contents);
      return 1;
   }

   fwrite(file_contents, sizeof(char), file_size, new_file);
   fclose(new_file);

   printf("File Successfully Recovered!\n");
   free(file_contents);
   return 0;
}