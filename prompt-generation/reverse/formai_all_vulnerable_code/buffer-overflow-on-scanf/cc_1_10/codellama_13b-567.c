//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: surrealist
// Unique C Digital Diary Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to store data
struct DiaryEntry {
  char title[20];
  char date[11];
  char entry[100];
};

// Function to display menu
void displayMenu() {
  printf("Welcome to your surrealist digital diary!\n");
  printf("Please select an option:\n");
  printf("1. Add a new entry\n");
  printf("2. View all entries\n");
  printf("3. Exit\n");
}

// Function to add a new entry
void addEntry() {
  struct DiaryEntry entry;
  printf("Enter the title of your entry: ");
  scanf("%s", entry.title);
  printf("Enter the date of your entry (DD/MM/YYYY): ");
  scanf("%s", entry.date);
  printf("Enter your entry: ");
  scanf("%s", entry.entry);
  printf("Your entry has been added!\n");
}

// Function to view all entries
void viewEntries() {
  struct DiaryEntry entry;
  printf("Your digital diary:\n");
  while (scanf("%s %s %s", entry.title, entry.date, entry.entry) != EOF) {
    printf("%s - %s\n", entry.title, entry.entry);
  }
}

// Function to exit program
void exitProgram() {
  printf("Thank you for using your digital diary!\n");
  exit(0);
}

int main() {
  int option;
  while (1) {
    displayMenu();
    scanf("%d", &option);
    switch (option) {
      case 1:
        addEntry();
        break;
      case 2:
        viewEntries();
        break;
      case 3:
        exitProgram();
        break;
      default:
        printf("Invalid option. Please try again.\n");
    }
  }
  return 0;
}