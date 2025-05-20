//FormAI DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  Date date;
  char *title;
  char *content;
} Entry;

int num_entries = 0;
Entry entry_array[MAX_ENTRIES];

void print_menu() {
  printf("\n===== DIGITAL DIARY =====\n");
  printf("1. New Entry\n");
  printf("2. View Entries\n");
  printf("3. Search Entries\n");
  printf("4. Quit\n");
  printf("=========================\n\n");
}

void new_entry() {
  if (num_entries >= MAX_ENTRIES) {
    printf("Error: maximum number of entries reached\n");
    return;
  }
  
  Entry new_entry;
  
  printf("Enter the date (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &new_entry.date.day, &new_entry.date.month, &new_entry.date.year);
  getchar(); // clear input buffer
  
  printf("Enter the title: ");
  new_entry.title = malloc(256 * sizeof(char));
  fgets(new_entry.title, 256, stdin);
  new_entry.title[strlen(new_entry.title)-1] = '\0'; // remove newline character
  
  printf("Enter the content (max 1000 characters):\n");
  new_entry.content = malloc(1000 * sizeof(char));
  fgets(new_entry.content, 1000, stdin);
  new_entry.content[strlen(new_entry.content)-1] = '\0'; // remove newline character
  
  entry_array[num_entries++] = new_entry;
  
  printf("\nEntry added successfully!\n");
}

void view_entries() {
  if (num_entries == 0) {
    printf("You have no entries\n");
    return;
  }
  
  printf("\n");
  
  for (int i = 0; i < num_entries; i++) {
    printf("Date: %02d/%02d/%d\n", entry_array[i].date.day, entry_array[i].date.month, entry_array[i].date.year);
    printf("Title: %s\n", entry_array[i].title);
    printf("Content:\n%s\n", entry_array[i].content);
    printf("=============================\n");
  }
}

void search_entries() {
  if (num_entries == 0) {
    printf("You have no entries to search\n");
    return;
  }
  
  int option;
  
  printf("\nSearch by:\n");
  printf("1. Date\n");
  printf("2. Title\n");
  printf("3. Content\n");
  printf("4. Cancel\n");
  
  printf("Enter your option: ");
  scanf("%d", &option);
  
  if (option == 1) {
    printf("Enter the date to search (dd/mm/yyyy): ");
    Date search_date;
    scanf("%d/%d/%d", &search_date.day, &search_date.month, &search_date.year);
    getchar(); // clear input buffer
    
    int found = 0;
    
    for (int i = 0; i < num_entries; i++) {
      if (entry_array[i].date.day == search_date.day && entry_array[i].date.month == search_date.month && entry_array[i].date.year == search_date.year) {
        printf("Date: %02d/%02d/%d\n", entry_array[i].date.day, entry_array[i].date.month, entry_array[i].date.year);
        printf("Title: %s\n", entry_array[i].title);
        printf("Content:\n%s\n", entry_array[i].content);
        printf("=============================\n");
        
        found = 1;
      }
    }
    
    if (!found) {
      printf("No entries found with the specified date\n");
    }
  } else if (option == 2) {
    printf("Enter the title to search: ");
    char search_title[256];
    getchar(); // clear input buffer
    fgets(search_title, 256, stdin);
    search_title[strlen(search_title)-1] = '\0'; // remove newline character
    
    int found = 0;
    
    for (int i = 0; i < num_entries; i++) {
      if (strcmp(entry_array[i].title, search_title) == 0) {
        printf("Date: %02d/%02d/%d\n", entry_array[i].date.day, entry_array[i].date.month, entry_array[i].date.year);
        printf("Title: %s\n", entry_array[i].title);
        printf("Content:\n%s\n", entry_array[i].content);
        printf("=============================\n");
        
        found = 1;
      }
    }
    
    if (!found) {
      printf("No entries found with the specified title\n");
    }
  } else if (option == 3) {
    printf("Enter the content to search: ");
    char search_content[1000];
    getchar(); // clear input buffer
    fgets(search_content, 1000, stdin);
    search_content[strlen(search_content)-1] = '\0'; // remove newline character
    
    int found = 0;
    
    for (int i = 0; i < num_entries; i++) {
      if (strstr(entry_array[i].content, search_content) != NULL) {
        printf("Date: %02d/%02d/%d\n", entry_array[i].date.day, entry_array[i].date.month, entry_array[i].date.year);
        printf("Title: %s\n", entry_array[i].title);
        printf("Content:\n%s\n", entry_array[i].content);
        printf("=============================\n");
        
        found = 1;
      }
    }
    
    if (!found) {
      printf("No entries found with the specified content\n");
    }
  } else if (option == 4) {
    printf("Search cancelled\n");
  } else {
    printf("Invalid option\n");
  }
}

int main() {
  printf("Welcome to Digital Diary!\n\n");
  
  int choice = 0;
  
  while (choice != 4) {
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        new_entry();
        break;
      case 2:
        view_entries();
        break;
      case 3:
        search_entries();
        break;
      case 4:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice\n");
        break;
    }
  }
  
  return 0;
}