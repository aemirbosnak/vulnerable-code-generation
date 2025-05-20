//FormAI DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // Set up variables
  FILE *fp;
  char date[20];
  char entry[200];
  char filename[30] = "MyDigitalDiary.txt";
  char menuChoice;

  // Show menu and get user choice
  while (menuChoice != 'X') {
    printf("\n\nMy Digital Diary\n");
    printf("A - Add an entry\n");
    printf("V - View all entries\n");
    printf("D - Delete an entry\n");
    printf("X - Exit program\n");
    printf("\nEnter your choice: ");
    scanf(" %c", &menuChoice);

    // Add an entry
    if (menuChoice == 'A' || menuChoice == 'a') {
      printf("\nEnter the date (mm/dd/yyyy): ");
      scanf(" %s", date);
      printf("\nEnter your diary entry (max 200 characters): ");
      scanf(" %[^\n]", entry);

      // Open file for appending
      fp = fopen(filename, "a");

      if (fp == NULL) {
        printf("\nError opening file.");
        exit(1);
      }

      fprintf(fp, "%s: %s\n", date, entry);
      fclose(fp);
      printf("\nEntry added successfully.");
    }

    // View all entries
    if (menuChoice == 'V' || menuChoice == 'v') {
      char line[255];

      fp = fopen(filename, "r");

      if (fp == NULL) {
        printf("\nError opening file.");
        exit(1);
      }

      printf("\n\nEntries:\n");

      while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
      }

      fclose(fp);
    }

    // Delete an entry
    if (menuChoice == 'D' || menuChoice == 'd') {
      char dateToDelete[20];
      char line[255];
      int foundMatch = 0;

      printf("\nEnter the date of the entry to delete (mm/dd/yyyy): ");
      scanf(" %s", dateToDelete);

      fp = fopen(filename, "r");

      if (fp == NULL) {
        printf("\nError opening file.");
        exit(1);
      }

      // Create a temp file to store lines that aren't being deleted
      char tempFilename[30] = "MyDigitalDiaryTemp.txt";
      FILE *tempFp = fopen(tempFilename, "w");

      if (tempFp == NULL) {
        printf("\nError creating temp file.");
        exit(1);
      }

      while (fgets(line, sizeof(line), fp)) {
        // Check if the line starts with the date to delete
        if (strncmp(line, dateToDelete, strlen(dateToDelete)) == 0) {
          foundMatch = 1;
        } else {
          fprintf(tempFp, "%s", line);
        }
      }

      fclose(fp);
      fclose(tempFp);

      // Replace the original file with the temp file if a match was found
      if (foundMatch) {
        remove(filename);
        rename(tempFilename, filename);
        printf("\nEntry deleted successfully.");
      } else {
        remove(tempFilename);
        printf("\nNo matching entry found.");
      }
    }
  }

  return 0;
}