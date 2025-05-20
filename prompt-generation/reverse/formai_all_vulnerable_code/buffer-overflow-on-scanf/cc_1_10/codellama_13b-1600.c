//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: peaceful
// Digital Diary in C

#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct diary_entry {
  char title[50];
  char content[500];
  int day;
  int month;
  int year;
};

int main() {
  struct diary_entry entries[MAX_ENTRIES];
  int num_entries = 0;

  printf("Welcome to your digital diary!\n");
  printf("Enter your first entry:\n");

  while (1) {
    printf("Title: ");
    fgets(entries[num_entries].title, 50, stdin);
    printf("Content: ");
    fgets(entries[num_entries].content, 500, stdin);
    printf("Day (DD): ");
    scanf("%d", &entries[num_entries].day);
    printf("Month (MM): ");
    scanf("%d", &entries[num_entries].month);
    printf("Year (YYYY): ");
    scanf("%d", &entries[num_entries].year);
    num_entries++;

    if (num_entries == MAX_ENTRIES) {
      break;
    }

    printf("Enter another entry (y/n)? ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'n') {
      break;
    }
  }

  printf("Here are your entries:\n");
  for (int i = 0; i < num_entries; i++) {
    printf("%s %d/%d/%d\n", entries[i].title, entries[i].day, entries[i].month, entries[i].year);
    printf("%s\n\n", entries[i].content);
  }

  return 0;
}