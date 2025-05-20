//FormAI DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Date {
   int day;
   int month;
   int year;
};

struct Entry {
   struct Date date;
   char title[50];
   char text[500];
};

int numOfEntries = 0;
struct Entry entries[100];

int main() {
   printf("Welcome to your Digital Diary!\n");

   while (1) {
      printf("\nWhat do you want to do?\n");
      printf("1. Create a new entry\n");
      printf("2. View previous entries\n");
      printf("3. Exit\n");

      int choice;
      scanf("%d", &choice);

      switch (choice) {
         case 1: {
            struct Entry newEntry;
            printf("\nEnter date in the format DD-MM-YYYY: ");
            scanf("%d-%d-%d", &newEntry.date.day, &newEntry.date.month, &newEntry.date.year);

            printf("Enter title of entry: ");
            getchar(); // To consume the newline character
            fgets(newEntry.title, 50, stdin);

            printf("Enter text of entry: ");
            fgets(newEntry.text, 500, stdin);

            entries[numOfEntries++] = newEntry;
            printf("\nEntry added successfully!\n");
            break;
         }
         case 2: {
            if (numOfEntries == 0) {
               printf("\nThere are no entries yet!\n");
               break;
            }

            printf("\nEnter date of entry to view in the format DD-MM-YYYY: ");
            int day, month, year;
            scanf("%d-%d-%d", &day, &month, &year);

            for (int i = 0; i < numOfEntries; i++) {
               if (entries[i].date.day == day && entries[i].date.month == month && entries[i].date.year == year) {
                  printf("\nDate: %02d-%02d-%04d\n", entries[i].date.day, entries[i].date.month, entries[i].date.year);
                  printf("Title: %s", entries[i].title);
                  printf("Text:\n%s\n", entries[i].text);
                  break;
               }
               if (i == numOfEntries - 1) {
                  printf("\nNo entry found for this date!\n");
               }
            }
            break;
         }
         case 3: {
            printf("\nThank you for using Digital Diary. Goodbye!\n");
            exit(0);
         }
         default: {
            printf("\nInvalid choice. Please try again.\n");
         }
      }
   }
   return 0;
}