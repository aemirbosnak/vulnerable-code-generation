//FormAI DATASET v1.0 Category: Digital Diary ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ENTRIES 100 //set a maximum number of entries in the diary
#define MAX_ENTRY_SIZE 500 //set a maximum number of characters in an entry

//struct to hold entry information
typedef struct Entry {
  char date[11];  //Format: MM/DD/YYYY
  char title[50];
  char notes[MAX_ENTRY_SIZE];
} Entry;

//function prototypes
void menu();
void add_entry();
void view_entries();
void search_entries();
void delete_entry();

//global variables
Entry entries[MAX_ENTRIES];
int num_entries = 0; //initialize the number of entries to 0

int main() {
  menu();
  return 0;
}

void menu() {
  int choice;
  do {
    printf("\n---Digital Diary Menu---\n");
    printf("1. Add an Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search for an Entry\n");
    printf("4. Delete an Entry\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
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
        delete_entry();
        break;
      case 5:
        printf("\nGoodbye!");
        break;
      default:
        printf("\nInvalid choice. Try again.");
        break;
    }
  } while (choice != 5);
}

void add_entry() {
  if (num_entries == MAX_ENTRIES) { //check if diary is full
    printf("\nThe diary is full!");
    return;
  }

  Entry new_entry;

  //get date
  printf("\nEnter the date (MM/DD/YYYY): ");
  scanf("%s", new_entry.date);

  //get title
  printf("\nEnter a title for the entry: ");
  getchar(); //clear input stream
  fgets(new_entry.title, sizeof(new_entry.title), stdin);

  //get notes
  printf("\nEnter the entry (max %d characters):\n", MAX_ENTRY_SIZE);
  fgets(new_entry.notes, sizeof(new_entry.notes), stdin);

  entries[num_entries] = new_entry; //add entry to diary
  num_entries++; //increment number of entries

  printf("\nEntry added successfully!");
}

void view_entries() {
  if (num_entries == 0) { //check if diary is empty
    printf("\nThe diary is empty!");
    return;
  }

  printf("\n---All Entries---\n");
  for (int i = 0; i < num_entries; i++) {
    printf("\nDate: %s", entries[i].date);
    printf("Title: %s", entries[i].title);
    printf("Notes: %s", entries[i].notes);
    printf("\n");
  }
}

void search_entries() {
  if (num_entries == 0) { //check if diary is empty
    printf("\nThe diary is empty!");
    return;
  }

  char search_date[11];
  printf("\nEnter the date to search (MM/DD/YYYY): ");
  scanf("%s", search_date);

  int found = 0;

  for (int i = 0; i < num_entries; i++) {
    if (strcmp(search_date, entries[i].date) == 0) {
      printf("\n---Entry Found---\n");
      printf("\nDate: %s", entries[i].date);
      printf("Title: %s", entries[i].title);
      printf("Notes: %s", entries[i].notes);
      printf("\n");
      found = 1;
      break; //exit loop if entry is found
    }
  }

  if (!found) {
    printf("\nEntry not found!");
  }
}

void delete_entry() {
  if (num_entries == 0) { //check if diary is empty
    printf("\nThe diary is empty!");
    return;
  }

  char delete_date[11];
  printf("\nEnter the date to delete (MM/DD/YYYY): ");
  scanf("%s", delete_date);

  int found = 0;

  for (int i = 0; i < num_entries; i++) {
    if (strcmp(delete_date, entries[i].date) == 0) {
      found = 1;

      //shift all entries after the deleted entry to the left
      for (int j = i; j < num_entries - 1; j++) {
        entries[j] = entries[j+1];
      }

      num_entries--; //decrement number of entries
      printf("\nEntry deleted successfully!");
      break; //exit loop if entry is found and deleted
    }
  }

  if (!found) {
    printf("\nEntry not found!");
  }
}