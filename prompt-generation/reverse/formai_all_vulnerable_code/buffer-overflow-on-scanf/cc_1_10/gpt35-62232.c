//FormAI DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
   char title[50];
   char description[250];
   char date[20];
};

int main() {
   struct Entry entries[100];
   int num_entries = 0;
   char choice = '0';

   while (choice != 'q') {
      printf("========================================\n");
      printf("Digital Diary\n");
      printf("========================================\n");
      printf("1: Add new entry\n");
      printf("2: View existing entries\n");
      printf("q: Quit\n");
      printf("========================================\n");
      printf("Select an option: ");
      scanf(" %c", &choice);

      switch (choice) {
         case '1':
            printf("Title: ");
            scanf(" %[^\n]s", entries[num_entries].title);
            printf("Description: ");
            scanf(" %[^\n]s", entries[num_entries].description);
            time_t now = time(NULL);
            strftime(entries[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
            printf("Entry added on %s\n", entries[num_entries].date);
            num_entries++;
            break;

         case '2':
            if (num_entries == 0) {
               printf("No entries yet.\n");
            }
            else {
               printf("========================================\n");
               printf("Existing Entries\n");
               printf("========================================\n");
               for (int i = 0; i < num_entries; i++) {
                  printf("%d | %s | %s\n", i+1, entries[i].title, entries[i].date);
               }
               printf("========================================\n");
               printf("Enter the entry number to view details (or 0 to go back): ");
               int entry_num;
               scanf("%d", &entry_num);
               if (entry_num > 0 && entry_num <= num_entries) {
                  printf("Title: %s\n", entries[entry_num-1].title);
                  printf("Description: %s\n", entries[entry_num-1].description);
                  printf("Date: %s\n", entries[entry_num-1].date);
                  printf("Press enter to continue.");
                  getchar();
                  getchar();
               }
            }
            break;

         case 'q':
            break;

         default:
            printf("Invalid choice.\n");
            break;
      }
   }

   return 0;
}