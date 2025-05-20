//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: careful
// C Digital Diary Example Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define structure for each entry
typedef struct {
  char title[100];
  char text[1000];
  time_t date;
} entry;

// Define structure for diary
typedef struct {
  entry* entries;
  int num_entries;
  int max_entries;
} diary;

// Function to create a new diary
diary* create_diary() {
  diary* new_diary = (diary*) malloc(sizeof(diary));
  new_diary->entries = (entry*) malloc(sizeof(entry) * 100);
  new_diary->num_entries = 0;
  new_diary->max_entries = 100;
  return new_diary;
}

// Function to add an entry to the diary
void add_entry(diary* diary, char* title, char* text) {
  entry* new_entry = (entry*) malloc(sizeof(entry));
  strcpy(new_entry->title, title);
  strcpy(new_entry->text, text);
  new_entry->date = time(NULL);
  diary->entries[diary->num_entries] = *new_entry;
  diary->num_entries++;
}

// Function to print the diary
void print_diary(diary* diary) {
  for (int i = 0; i < diary->num_entries; i++) {
    entry* entry = &diary->entries[i];
    printf("%s\n", entry->title);
    printf("%s\n", entry->text);
    printf("%s\n", ctime(&entry->date));
  }
}

// Function to free the diary
void free_diary(diary* diary) {
  free(diary->entries);
  free(diary);
}

int main() {
  diary* my_diary = create_diary();
  add_entry(my_diary, "First Entry", "This is the first entry in my diary.");
  add_entry(my_diary, "Second Entry", "This is the second entry in my diary.");
  print_diary(my_diary);
  free_diary(my_diary);
  return 0;
}