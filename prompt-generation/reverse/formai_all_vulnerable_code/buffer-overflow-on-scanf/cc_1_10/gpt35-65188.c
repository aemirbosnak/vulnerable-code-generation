//FormAI DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 1000

struct entry {
  char date[20];
  char title[50];
  char content[500];
};

struct entry diary[MAX_ENTRY];
int entry_count = 0;

void add_entry() {
  char date[20];
  char title[50];
  char content[500];

  printf("My dearest diary, pray tell, what shall I record on this day?\n");
  printf("Date (dd/mm/yyyy): ");
  fgets(date, sizeof(date), stdin);

  printf("Title (max 50 chars): ");
  fgets(title, sizeof(title), stdin);

  printf("Content (max 500 chars): ");
  fgets(content, sizeof(content), stdin);

  struct entry new_entry;
  strcpy(new_entry.date, date);
  strcpy(new_entry.title, title);
  strcpy(new_entry.content, content);

  diary[entry_count] = new_entry;
  entry_count++;

  printf("\nPrithee, the entry hath been added to thy diary!\n\n");
}

void show_entries() {
  printf("Here are thy entries in the diary:\n\n");

  for (int i = 0; i < entry_count; i++) {
    printf("Date: %s", diary[i].date);
    printf("Title: %s", diary[i].title);
    printf("%s\n\n", diary[i].content);
  }
}

void search_entry() {
  char search_title[50];

  printf("Let's discover if thy diary hath an entry with a certain title.\n");
  printf("Please enter a title to search for: ");
  fgets(search_title, sizeof(search_title), stdin);

  for (int i = 0; i < entry_count; i++) {
    if (strstr(diary[i].title, search_title) != NULL) {
      printf("\nFound a match!\n\n");
      printf("Date: %s", diary[i].date);
      printf("Title: %s", diary[i].title);
      printf("%s\n\n", diary[i].content);
      return;
    }
  }

  printf("\nAlas, thy diary hath no entries with that title!\n\n");
}

int main() {
  int choice;

  printf("O, diary of mine, I beseech thee to open and reveal your secrets to me!\n\n");

  while (1) {
    printf("What wouldst thou like to do today?\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry by title\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    getchar();  // Flush newline character

    switch (choice) {
      case 1:
        add_entry();
        break;
      case 2:
        show_entries();
        break;
      case 3:
        search_entry();
        break;
      case 4:
        printf("Farewell, dear diary, for now we part ways.\n");
        exit(0);
      default:
        printf("Alas, that is not a valid choice! Please try again.\n");
    }
  }

  return 0;
}