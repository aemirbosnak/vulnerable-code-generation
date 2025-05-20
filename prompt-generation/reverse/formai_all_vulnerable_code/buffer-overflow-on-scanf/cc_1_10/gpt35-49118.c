//FormAI DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int choice, day, month, year, hour, minute;
   char entry[100];

   FILE *fptr; //File pointer to store the diary entries
   fptr = fopen("diary.txt", "a"); //Open file in append mode
   
   time_t now; //Get current date and time
   time(&now);

   struct tm *local = localtime(&now); //Convert to local time
   day = local->tm_mday;
   month = local->tm_mon + 1;
   year = local->tm_year + 1900;
   hour = local->tm_hour;
   minute = local->tm_min;
   
   printf("Welcome to your Digital Diary!\n");
   
   do {
      //Display menu options
      printf("1. Write an entry\n");
      printf("2. Display all entries\n");
      printf("3. Exit\n");
      printf("Enter your choice (1-3): ");
      scanf("%d", &choice);
      
      switch (choice) {
         case 1: //Write an entry
            printf("\nEnter your entry (max 100 characters):\n");
            getchar();
            fgets(entry, 100, stdin);
            
            //Write entry to file
            fprintf(fptr, "[%02d-%02d-%d %02d:%02d] %s\n", day, month, year, hour, minute, entry);
            printf("\nEntry saved!\n\n");
            break;
            
         case 2: //Display all entries
            rewind(fptr); //Go to beginning of file
            
            printf("\nAll entries:\n");
            printf("-----------------\n");
            
            while (fgets(entry, 100, fptr)) {
               printf("%s", entry);
            }
            
            printf("-----------------\n\n");
            break;
            
         case 3: //Exit
            printf("\nGoodbye!\n");
            break;
            
         default:
            printf("\nInvalid choice. Please try again.\n\n");
            break;
      }
   } while (choice != 3);

   fclose(fptr); //Close file
   
   return 0;
}