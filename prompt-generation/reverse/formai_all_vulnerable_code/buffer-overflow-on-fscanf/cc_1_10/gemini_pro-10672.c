//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the file name for the diary
#define DIARY_FILE "diary.txt"

// Define the structure of a diary entry
typedef struct {
  char *entry;
  int date;
} DiaryEntry;

// Create a new diary entry
DiaryEntry *new_entry(char *entry, int date) {
  DiaryEntry *new_entry = malloc(sizeof(DiaryEntry));
  new_entry->entry = strdup(entry);
  new_entry->date = date;
  return new_entry;
}

// Read the diary from a file
DiaryEntry **read_diary(int *num_entries) {
  FILE *fp = fopen(DIARY_FILE, "r");
  if (fp == NULL) {
    *num_entries = 0;
    return NULL;
  }

  // Read the number of entries
  fscanf(fp, "%d\n", num_entries);

  // Allocate memory for the entries
  DiaryEntry **entries = malloc(sizeof(DiaryEntry *) * (*num_entries));

  // Read the entries
  for (int i = 0; i < *num_entries; i++) {
    char entry[MAX_ENTRY_LENGTH];
    int date;
    fscanf(fp, "%s\n%d\n", entry, &date);
    entries[i] = new_entry(entry, date);
  }

  fclose(fp);

  return entries;
}

// Write the diary to a file
void write_diary(DiaryEntry **entries, int num_entries) {
  FILE *fp = fopen(DIARY_FILE, "w");
  if (fp == NULL) {
    return;
  }

  // Write the number of entries
  fprintf(fp, "%d\n", num_entries);

  // Write the entries
  for (int i = 0; i < num_entries; i++) {
    fprintf(fp, "%s\n%d\n", entries[i]->entry, entries[i]->date);
  }

  fclose(fp);
}

// Add a new entry to the diary
void add_entry(DiaryEntry **entries, int *num_entries, char *entry, int date) {
  // Reallocate the entries array
  entries = realloc(entries, sizeof(DiaryEntry *) * (*num_entries + 1));

  // Add the new entry
  entries[*num_entries] = new_entry(entry, date);

  // Increment the number of entries
  (*num_entries)++;

  // Write the diary to a file
  write_diary(entries, *num_entries);
}

// Delete an entry from the diary
void delete_entry(DiaryEntry **entries, int *num_entries, int index) {
  // Free the entry
  free(entries[index]->entry);
  free(entries[index]);

  // Shift the entries down
  for (int i = index; i < *num_entries - 1; i++) {
    entries[i] = entries[i + 1];
  }

  // Decrement the number of entries
  (*num_entries)--;

  // Write the diary to a file
  write_diary(entries, *num_entries);
}

// Print the diary
void print_diary(DiaryEntry **entries, int num_entries) {
  for (int i = 0; i < num_entries; i++) {
    printf("%s\n%d\n\n", entries[i]->entry, entries[i]->date);
  }
}

// Main function
int main() {
  // Read the diary from a file
  DiaryEntry **entries;
  int num_entries;
  entries = read_diary(&num_entries);

  // Print the diary
  print_diary(entries, num_entries);

  // Add a new entry to the diary
  add_entry(entries, &num_entries, "This is a new entry.", 20230308);

  // Delete an entry from the diary
  delete_entry(entries, &num_entries, 0);

  // Print the diary
  print_diary(entries, num_entries);

  // Free the entries
  for (int i = 0; i < num_entries; i++) {
    free(entries[i]->entry);
    free(entries[i]);
  }
  free(entries);

  return 0;
}