//FormAI DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 500

struct DiaryEntry {
   char date[11]; // format YYYY-mm-dd
   char content[MAX_ENTRY_LENGTH];
};

int printMainMenu() {
   int choice;
   printf("\nDIGITAL DIARY\n\n");
   printf("1. New Entry\n");
   printf("2. View Entries\n");
   printf("3. Exit\n");
   printf("Enter choice (1-3): ");
   scanf("%d", &choice);
   return choice;
}

void addNewEntry(struct DiaryEntry *entries, int *numEntries) {

   printf("\nEnter today's date (YYYY-mm-dd): ");
   scanf("%s", entries[*numEntries].date);
   printf("Enter diary entry (max %d characters):\n", MAX_ENTRY_LENGTH);
   scanf(" %[^\n]s", entries[*numEntries].content);
   printf("\nEntry added successfully!");
   (*numEntries)++;
   return;
}

void readFromFile(struct DiaryEntry *entries, int *numEntries) {

   FILE *fp;
   fp = fopen("diary.txt", "r");

   if (fp == NULL) {
      printf("No previous diary entries.\n");
      return;
   }

   while (fscanf(fp, "%s %[^\n]s\n", entries[*numEntries].date,
                                             entries[*numEntries].content) != EOF) {
      (*numEntries)++;
   }

   fclose(fp);
   printf("\nThere are %d previous diary entries.\n", *numEntries);

   return;
}

void writeToFile(struct DiaryEntry *entries, int numEntries) {

   FILE *fp;
   fp = fopen("diary.txt", "w");

   if (fp == NULL) {
      printf("Error writing to file.\n");
      return;
   }

   for (int i = 0; i < numEntries; i++) {
      fprintf(fp, "%s %s\n", entries[i].date, entries[i].content);
   }

   fclose(fp);
   return;
}

void viewEntries(struct DiaryEntry *entries, int numEntries) {

   char dateRange[25];
   printf("\nEnter date range to view entries (YYYY-mm-dd to YYYY-mm-dd): ");
   scanf("%s", dateRange);

   char *startPtr = strtok(dateRange, " ");
   char *endPtr = strtok(NULL, " ");

   if (startPtr == NULL || endPtr == NULL) {
      printf("\nInvalid format.\n");
      return;
   }

   struct tm start, end;
   memset(&start, 0, sizeof(struct tm));
   memset(&end, 0, sizeof(struct tm));

   int startYear, startMonth, startDay, endYear, endMonth, endDay;
   sscanf(startPtr, "%d-%d-%d", &startYear, &startMonth, &startDay);
   sscanf(endPtr, "%d-%d-%d", &endYear, &endMonth, &endDay);

   start.tm_year = startYear - 1900;
   start.tm_mon = startMonth - 1;
   start.tm_mday = startDay;
   end.tm_year = endYear - 1900;
   end.tm_mon = endMonth - 1;
   end.tm_mday = endDay + 1; // include end date in range
   time_t startTime = mktime(&start);
   time_t endTime = mktime(&end);

   printf("\nEntry/entries between %s and %s:\n", startPtr, endPtr);
   for (int i = 0; i < numEntries; i++) {
      struct tm entryTime;
      sscanf(entries[i].date, "%d-%d-%d", &entryTime.tm_year,
                                          &entryTime.tm_mon, &entryTime.tm_mday);
      entryTime.tm_year -= 1900;
      entryTime.tm_mon -= 1;
      time_t entryTimestamp = mktime(&entryTime);
      if (entryTimestamp >= startTime && entryTimestamp <= endTime) {
         printf("%s: %s\n", entries[i].date, entries[i].content);
      }
   }
   return;
}


int main() {

   struct DiaryEntry entries[500];
   int numEntries = 0;

   readFromFile(entries, &numEntries);

   int choice;
   do {
      choice = printMainMenu();
      switch (choice) {
         case 1:
            addNewEntry(entries, &numEntries);
            break;
         case 2:
            viewEntries(entries, numEntries);
            break;
         case 3:
            writeToFile(entries, numEntries);
            printf("\nGoodbye!\n");
            break;
         default:
            printf("\nInvalid choice.\n");
      }
   } while (choice != 3);

   return 0;
}