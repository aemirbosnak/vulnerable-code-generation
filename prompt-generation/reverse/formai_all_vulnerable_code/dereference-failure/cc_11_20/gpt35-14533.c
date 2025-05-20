//FormAI DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ENTRIES 100   // Maximum number of entries in the diary

struct entry {
  int day;
  int month;
  int year;
  char *content;
};

int main() {
  struct entry diary[MAX_ENTRIES];   // Array of diary entries
  int num_entries = 0;     // Number of entries in the diary
  char *choice;            // User choice for operation

  // Loop until user chooses to quit
  while (1) {
    printf("\nSelect operation:\n");
    printf("1. Add entry\n");
    printf("2. View all entries\n");
    printf("3. Search for entry\n");
    printf("4. Exit\n");

    scanf("%s", choice);

    switch(*choice) {
      case '1':
        // Add new diary entry
        if (num_entries >= MAX_ENTRIES) {
          printf("Diary is full\n");
        } else {
          printf("Enter date (DD MM YYYY): ");
          scanf("%d %d %d", &diary[num_entries].day, &diary[num_entries].month, &diary[num_entries].year);
          
          // Allocate memory for content
          diary[num_entries].content = malloc(sizeof(char) * 1000);
          printf("Enter content:\n");
          getchar();    // Clear buffer
          fgets(diary[num_entries].content, 1000, stdin);   // Read input
          
          printf("Entry added successfully\n");
          num_entries++;
        }
        break;

      case '2':
        // View all diary entries
        if (num_entries == 0) {
          printf("No entries to display\n");
        } else {
          printf("Displaying all entries:\n");
          for (int i = 0; i < num_entries; i++) {
            printf("%d/%d/%d\n%s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].content);
          }
        }
        break;

      case '3':
        // Search for a diary entry
        if (num_entries == 0) {
          printf("No entries to search\n");
        } else {
          int found = 0;    // Flag for whether entry is found or not
          int search_day, search_month, search_year;
          printf("Enter date to search for (DD MM YYYY): ");
          scanf("%d %d %d", &search_day, &search_month, &search_year);
          for (int i = 0; i < num_entries; i++) {
            if (diary[i].day == search_day && diary[i].month == search_month && diary[i].year == search_year) {
              printf("Entry found:\n%d/%d/%d\n%s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].content);
              found = 1;
              break;
            }
          }
          if (!found) {
            printf("No entry found for specified date\n");
          }
        }
        break;

      case '4':
        // Exit program
        for (int i = 0; i < num_entries; i++) {
          free(diary[i].content);   // Free up memory for content
        }
        printf("Exiting...\n");
        return 0;

      default:
        printf("Invalid choice\n");
    }
  }
}