//FormAI DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000 // maximum size of diary entry

int main()
{
   char diary[SIZE], date[20], choice;
   FILE *fileptr;
   
   printf("**** Welcome to your Digital Diary **** \n");
   
   do {
      printf("\nEnter the date (dd/mm/yyyy) of your entry: ");
      fgets(date, 20, stdin);
      strtok(date, "\n"); // remove newline character from user input
      
      // check if entry already exists for the given date
      fileptr = fopen(date, "r");
      if (fileptr != NULL) {
         printf("An entry for %s already exists. Do you want to overwrite it? (y/n): ", date);
         scanf("%c", &choice);
         getchar(); // clear input buffer
         if (choice == 'n') {
            fclose(fileptr);
            continue;
         }
      }
      
      printf("\nEnter your diary entry: ");
      fgets(diary, SIZE, stdin);
      
      fileptr = fopen(date, "w");
      if (fileptr == NULL) {
         printf("Error creating file!\n");
         exit(1); // exit program
      }
      
      fprintf(fileptr, "%s", diary); // write diary entry to file
      fclose(fileptr);
      
      printf("\nYour entry for %s has been saved successfully!\n", date);
      
      printf("\nDo you want to enter another entry? (y/n): ");
      scanf("%c", &choice);
      getchar(); // clear input buffer
   } while (choice == 'y');
   
   printf("\nThank you for using your Digital Diary!\n");
   
   return 0;
}