//FormAI DATASET v1.0 Category: Digital Diary ; Style: high level of detail
#include <stdio.h>

int main() {
   int option;
   char name[20];
   char entry[200];
   char line[10];

   // Create a new diary file for the user
   FILE *diary_file = fopen("my_diary.txt", "w");
   if (diary_file == NULL) {
      printf("Cannot create diary file.\n");
      return 1;
   }
   printf("Welcome to your Digital Diary!\n");

   // Menu to offer options to the user
   do {
      printf("\nMenu:\n1. View Diary\n2. Write an Entry\n3. Exit\n");
      printf("Enter your option: ");
      fgets(line, sizeof(line), stdin);
      sscanf(line, "%d", &option);

      // View the diary
      if (option == 1) {
         // Open diary for reading
         FILE *diary_file = fopen("my_diary.txt", "r");
         if (diary_file == NULL) {
            printf("Cannot read diary file.\n");
            return 1;
         }

         // Read and print the contents of the diary
         printf("\nHere are the entries in your diary:\n");
         while(fgets(entry, sizeof(entry), diary_file)) {
            printf("%s\n", entry);
         }

         // Close diary
         fclose(diary_file);
      }
      // Write an entry
      else if (option == 2) {
         printf("Please enter your name: ");
         fgets(name, sizeof(name), stdin);

         // Get the entry text
         printf("Please enter your entry: ");
         fgets(entry, sizeof(entry), stdin);

         // Write the entry to the diary file
         FILE *diary_file = fopen("my_diary.txt", "a");
         if (diary_file == NULL) {
            printf("Cannot write to diary file.\n");
            return 1;
         }
         fprintf(diary_file, "%s: %s\n", name, entry);
         fclose(diary_file);

         printf("Entry added successfully!\n");
      }
      // Exit the program
      else if (option == 3) {
         printf("Thank you for using the Digital Diary!\n");
         return 0;
      }
      else {
         printf("Invalid option, please try again.\n");
      }
   } while (option != 3);

   return 0;
}