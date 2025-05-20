//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024

typedef struct {
  char date[11];
  char time[9];
  char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
  if (num_entries == MAX_ENTRIES) {
    printf("Error: Diary is full.\n");
    return;
  }

  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  strftime(entries[num_entries].date, sizeof(entries[num_entries].date), "%Y-%m-%d", tm);
  strftime(entries[num_entries].time, sizeof(entries[num_entries].time), "%H:%M:%S", tm);

  printf("Enter your entry:\n");
  fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);

  num_entries++;
}

void view_entries() {
  if (num_entries == 0) {
    printf("Error: Diary is empty.\n");
    return;
  }

  for (int i = 0; i < num_entries; i++) {
    printf("%s %s\n\n%s\n\n", entries[i].date, entries[i].time, entries[i].entry);
  }
}

void search_entries() {
  char search_term[MAX_ENTRY_LENGTH];

  printf("Enter search term:\n");
  fgets(search_term, MAX_ENTRY_LENGTH, stdin);

  for (int i = 0; i < num_entries; i++) {
    if (strstr(entries[i].entry, search_term) != NULL) {
      printf("%s %s\n\n%s\n\n", entries[i].date, entries[i].time, entries[i].entry);
    }
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Add entry\n2. View entries\n3. Search entries\n4. Quit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_entry();
        break;
      case 2:
        view_entries();
        break;
      case 3:
        search_entries();
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }
}