//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
  char date[11];
  char entry[256];
} diary_entry;

void print_entry(diary_entry entry) {
  printf("Entry for %s: %s\n", entry.date, entry.entry);
}

void add_entry(diary_entry* entries, char* date, char* entry) {
  strcpy(entries[0].date, date);
  strcpy(entries[0].entry, entry);
}

void save_entries(diary_entry* entries) {
  FILE* file = fopen("diary.txt", "w");
  if (file == NULL) {
    printf("Error: unable to open file\n");
    return;
  }
  for (int i = 0; i < MAX_ENTRIES; i++) {
    fprintf(file, "%s %s\n", entries[i].date, entries[i].entry);
  }
  fclose(file);
}

void load_entries(diary_entry* entries) {
  FILE* file = fopen("diary.txt", "r");
  if (file == NULL) {
    printf("Error: unable to open file\n");
    return;
  }
  char line[256];
  int i = 0;
  while (fgets(line, sizeof(line), file) != NULL) {
    char* date = strtok(line, " ");
    char* entry = strtok(NULL, "\n");
    strcpy(entries[i].date, date);
    strcpy(entries[i].entry, entry);
    i++;
  }
  fclose(file);
}

void print_diary(diary_entry* entries) {
  for (int i = 0; i < MAX_ENTRIES; i++) {
    print_entry(entries[i]);
  }
}

int main() {
  diary_entry entries[MAX_ENTRIES];
  load_entries(entries);
  print_diary(entries);
  char date[11];
  char entry[256];
  printf("Enter date (YYYY-MM-DD): ");
  scanf("%s", date);
  printf("Enter entry: ");
  fgets(entry, sizeof(entry), stdin);
  add_entry(entries, date, entry);
  save_entries(entries);
  print_diary(entries);
  return 0;
}