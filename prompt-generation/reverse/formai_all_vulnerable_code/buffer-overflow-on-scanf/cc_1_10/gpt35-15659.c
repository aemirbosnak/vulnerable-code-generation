//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char userInput[1000];
  FILE *file;
  int choice;

  printf("Welcome to your Digital Diary!\n");

  while(1) {
    // Present menu options
    printf("\nWhat would you like to do?\n");
    printf("1. Write new entry\n");
    printf("2. Read previous entries\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        // User wants to write a new entry
        printf("Enter your entry below:\n");
        getchar();  // Clear input buffer
        fgets(userInput, 1000, stdin);

        // Open file in append mode
        file = fopen("diary.txt", "a");
        if (file == NULL) {
          printf("Error: Unable to open file.\n");
          return 1;
        }

        // Write user input to file
        fputs(userInput, file);

        // Close file
        fclose(file);

        printf("Entry saved successfully!\n");

        break;
      
      case 2:
        // User wants to read previous entries
        file = fopen("diary.txt", "r");
        if (file == NULL) {
          printf("Error: Unable to open file.\n");
          return 1;
        }

        printf("Previous entries:\n\n");

        // Read file line by line and output to console
        char line[1000];
        while(fgets(line, 1000, file) != NULL) {
          printf("%s", line);
        }

        fclose(file);

        break;

      case 3:
        // User wants to quit
        printf("Goodbye!\n");
        exit(0);

        break;

      default:
        // Invalid input
        printf("Invalid choice. Please select a valid option.\n");
    }
  }

  return 0;
}