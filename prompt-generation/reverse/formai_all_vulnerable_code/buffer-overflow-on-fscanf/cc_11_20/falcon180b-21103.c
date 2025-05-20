//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
  char date[11];
  char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
  FILE *diary;
  Entry entries[MAX_ENTRIES];
  int numEntries = 0;
  char choice;
  int year, month, day;
  int i;

  // Open diary file
  diary = fopen("diary.txt", "a");
  if (diary == NULL) {
    printf("Error: Could not open diary file.\n");
    return 1;
  }

  // Read in existing entries
  rewind(diary);
  while (fscanf(diary, "%s %s\n", entries[numEntries].date, entries[numEntries].entry)!= EOF) {
    numEntries++;
  }

  // Main loop
  while (1) {
    printf("\nDigital Diary\n");
    printf("A - Add entry\n");
    printf("R - Read entry\n");
    printf("S - Search entry\n");
    printf("Q - Quit\n");
    printf("Choose an option: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'A':
        // Add entry
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%d-%d-%d", &year, &month, &day);
        sprintf(entries[numEntries].date, "%04d-%02d-%02d", year, month, day);
        printf("Enter entry: ");
        fgets(entries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
        numEntries++;
        break;

      case 'R':
        // Read entry
        printf("Enter date to read (YYYY-MM-DD): ");
        scanf("%s", entries[0].date);
        for (i = 0; i < numEntries; i++) {
          if (strcmp(entries[i].date, entries[0].date) == 0) {
            printf("%s\n%s", entries[i].date, entries[i].entry);
            break;
          }
        }
        break;

      case 'S':
        // Search entry
        printf("Enter keyword to search: ");
        scanf("%s", entries[0].entry);
        for (i = 0; i < numEntries; i++) {
          if (strstr(entries[i].entry, entries[0].entry)!= NULL) {
            printf("%s\n%s", entries[i].date, entries[i].entry);
          }
        }
        break;

      case 'Q':
        // Quit
        fclose(diary);
        return 0;

      default:
        printf("Invalid option.\n");
    }
  }

  return 0;
}