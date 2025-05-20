//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIARY_ENTRIES 100
#define MAX_DIARY_LENGTH 1024

typedef struct {
  char title[MAX_DIARY_LENGTH];
  char content[MAX_DIARY_LENGTH];
} diary_entry;

void print_menu() {
  printf("Welcome to your Digital Diary!\n");
  printf("1. Add a new entry\n");
  printf("2. View all entries\n");
  printf("3. Search for an entry\n");
  printf("4. Exit\n");
}

void add_entry(diary_entry* diary) {
  printf("Enter a title for your entry: ");
  scanf("%s", diary->title);
  printf("Enter the content of your entry: ");
  scanf("%s", diary->content);
}

void view_all_entries(diary_entry* diary) {
  for (int i = 0; i < MAX_DIARY_ENTRIES; i++) {
    if (diary[i].title[0] != '\0') {
      printf("%s: %s\n", diary[i].title, diary[i].content);
    }
  }
}

void search_entry(diary_entry* diary) {
  char search_term[MAX_DIARY_LENGTH];
  printf("Enter a search term: ");
  scanf("%s", search_term);
  for (int i = 0; i < MAX_DIARY_ENTRIES; i++) {
    if (strstr(diary[i].title, search_term) != NULL) {
      printf("%s: %s\n", diary[i].title, diary[i].content);
    }
  }
}

int main() {
  diary_entry diary[MAX_DIARY_ENTRIES];
  int option;
  while (1) {
    print_menu();
    scanf("%d", &option);
    switch (option) {
      case 1:
        add_entry(&diary);
        break;
      case 2:
        view_all_entries(&diary);
        break;
      case 3:
        search_entry(&diary);
        break;
      case 4:
        return 0;
        break;
      default:
        printf("Invalid option\n");
        break;
    }
  }
  return 0;
}