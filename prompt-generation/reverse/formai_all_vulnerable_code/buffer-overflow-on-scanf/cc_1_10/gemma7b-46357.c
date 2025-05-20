//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DiaryEntry {
  char title[20];
  char content[200];
  int date;
} DiaryEntry;

DiaryEntry entries[100];

void addEntry() {
  printf("Enter the title of your entry:");
  scanf("%s", entries[0].title);

  printf("Enter the content of your entry:");
  scanf("%s", entries[0].content);

  printf("Enter the date of your entry:");
  scanf("%d", &entries[0].date);

  entries[0] = entries[0];
}

void viewEntries() {
  for (int i = 0; i < 100; i++) {
    if (entries[i].title[0] != '\0') {
      printf("Title: %s\n", entries[i].title);
      printf("Content: %s\n", entries[i].content);
      printf("Date: %d\n", entries[i].date);
      printf("\n");
    }
  }
}

int main() {
  int choice;

  printf("Welcome to the Digital Diary!\n");
  printf("1. Add Entry\n");
  printf("2. View Entries\n");
  printf("Enter your choice:");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      addEntry();
      break;
    case 2:
      viewEntries();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}