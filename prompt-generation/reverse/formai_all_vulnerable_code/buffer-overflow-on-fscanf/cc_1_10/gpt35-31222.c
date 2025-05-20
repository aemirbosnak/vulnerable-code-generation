//FormAI DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 50

struct Entry {
  char date[10];
  char time[8];
  char content[100];
};

struct Diary {
  struct Entry entries[MAX_ENTRIES];
  int count;
};

void print_entry(struct Entry entry) {
  printf("\nDate: %s\n", entry.date);
  printf("Time: %s\n", entry.time);
  printf("Content: %s\n", entry.content);
}

void print_diary(struct Diary diary) {
  printf("\nDIARY:\n");

  for (int i = 0; i < diary.count; i++) {
    print_entry(diary.entries[i]);
  }
}

void add_entry(struct Diary *diary) {
  struct Entry new_entry;
  printf("\nEnter the date (dd/mm/yyyy): ");
  scanf("%s", new_entry.date);
  printf("Enter the time (hh:mm:ss): ");
  scanf("%s", new_entry.time);
  printf("Enter the content: ");
  scanf(" %[^\n]s", new_entry.content);

  if (diary->count < MAX_ENTRIES) {
    diary->entries[diary->count++] = new_entry;
  } else {
    printf("Diary is full, cannot add new entry.\n");
  }
}

void save_diary(struct Diary diary) {
  FILE *fp = fopen("diary.txt", "w");

  if (fp == NULL) {
    printf("Error opening file to save diary.\n");
    return;
  }

  fprintf(fp, "%d\n", diary.count);

  for (int i = 0; i < diary.count; i++) {
    fprintf(fp, "%s\n", diary.entries[i].date);
    fprintf(fp, "%s\n", diary.entries[i].time);
    fprintf(fp, "%s\n", diary.entries[i].content);
  }

  fclose(fp);
}

void load_diary(struct Diary *diary) {
  FILE *fp = fopen("diary.txt", "r");
  if (fp == NULL) {
    printf("No saved diary found.\n");
    return;
  }

  fscanf(fp, "%d\n", &(diary->count));

  for (int i = 0; i < diary->count; i++) {
    struct Entry entry;
    fscanf(fp, "%s\n", entry.date);
    fscanf(fp, "%s\n", entry.time);
    fscanf(fp, "%[^\n]s\n", entry.content);
    diary->entries[i] = entry;
  }

  fclose(fp);
}

int main() {
  struct Diary my_diary;
  my_diary.count = 0;

  load_diary(&my_diary);

  char choice[10];

  while (1) {
    printf("\nMENU\n");
    printf("1. View diary.\n");
    printf("2. Add entry.\n");
    printf("3. Save and exit.\n");
    printf("Enter your choice: ");
    scanf("%s", choice);

    if (strcmp(choice, "1") == 0) {
      print_diary(my_diary);
    } else if (strcmp(choice, "2") == 0) {
      add_entry(&my_diary);
    } else if (strcmp(choice, "3") == 0) {
      save_diary(my_diary);
      break;
    } else {
      printf("Invalid choice.\n");
    }
  }

  return 0;
}