//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_ENTRY_SIZE 1000
#define MAX_ENTRIES 365

// Structure to store diary entry details
struct DiaryEntry {
  char date[20];
  char entry[MAX_ENTRY_SIZE];
};

// Function to display menu
void displayMenu() {
  printf("\n\n**** Digital Diary ****\n");
  printf("1. Add an entry\n");
  printf("2. View previous entries\n");
  printf("3. Exit\n");
}

// Function to get the current date
void getCurrentDate(char *date) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

int main() {
  char choice;
  char filename[50];
  char date[20];
  char entry[MAX_ENTRY_SIZE];
  int entryCount = 0;
  FILE *fp;

  // Create a filename for the diary based on current year
  sprintf(filename, "diary_%d.txt", (int)time(NULL));

  // Display the main menu
  do {
    displayMenu();

    // Get user's choice
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    switch(choice) {
      case '1':
        // Get current date
        getCurrentDate(date);

        // Get entry from user
        printf("Enter your diary entry (max %d characters):\n", MAX_ENTRY_SIZE);
        getchar(); // Consume the newline character left behind by scanf
        fgets(entry, MAX_ENTRY_SIZE, stdin);

        // Add entry to file
        fp = fopen(filename, "a");
        if(fp == NULL) {
          printf("Error: Could not open file %s\n", filename);
          exit(EXIT_FAILURE);
        }
        fprintf(fp, "%s\n%s\n", date, entry);
        fclose(fp);

        printf("Entry added.\n");
        entryCount++;
        break;

      case '2':
        // Read entries from file and print them
        fp = fopen(filename, "r");
        if(fp == NULL) {
          printf("Error: Could not open file %s\n", filename);
          exit(EXIT_FAILURE);
        }

        printf("\n");
        while(fscanf(fp, "%[^\n]\n%[^\n]\n", date, entry) != EOF) {
          printf("%s\n%s\n\n", date, entry);
        }

        fclose(fp);
        break;
      
      case '3':
        printf("\nGoodbye!\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while(choice != '3');

  return 0;
}