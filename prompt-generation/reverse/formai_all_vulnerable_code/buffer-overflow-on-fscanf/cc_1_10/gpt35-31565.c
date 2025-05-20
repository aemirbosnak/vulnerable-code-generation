//FormAI DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define structure for diary entry */
struct diaryEntry {
   char date[11];
   char time[6];
   char content[1001];
};

int main() {
   char option;
   FILE *fp;
   struct diaryEntry entry;

   /* Get date and time */
   time_t now = time(0);
   struct tm *current = localtime(&now);
   strftime(entry.date, sizeof(entry.date), "%Y/%m/%d", current);
   strftime(entry.time, sizeof(entry.time), "%H:%M", current);

   /* Open diary file */
   fp = fopen("diary.txt", "a+");

   if (fp == NULL) {
      printf("Error opening file");
      exit(1);
   }

   /* Display main menu */
   printf("1. Add entry\n");
   printf("2. View entries\n");
   printf("3. Exit\n");

   /* Get user input */
   printf("Enter option: ");
   scanf(" %c", &option);

   switch (option) {

      case '1':
         /* Add entry */
         printf("\nEnter content: ");
         scanf(" %[^\n]s", entry.content);
         fprintf(fp, "%s %s\n%s\n", entry.date, entry.time, entry.content);
         printf("\nEntry added successfully");
         break;

      case '2':
         /* View all entries */
         printf("\nAll entries:\n");
         rewind(fp);
         while (fscanf(fp, "%s %s\n", entry.date, entry.time) == 2) {
            fgets(entry.content, 1001, fp);
            printf("\nDate: %s\nTime: %s\nContent: %s", entry.date, entry.time, entry.content);
         }
         break;
      
      case '3':
         /* Exit */
         printf("\nGoodbye!");
         break;

      default:
         printf("\nInvalid option");
         break;

   }

   /* Close diary file */
   fclose(fp);

   return 0;
}