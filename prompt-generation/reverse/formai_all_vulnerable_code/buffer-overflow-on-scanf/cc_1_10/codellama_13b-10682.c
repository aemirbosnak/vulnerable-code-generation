//Code Llama-13B DATASET v1.0 Category: File handling ; Style: lively
/*
 * Lively File Handling Program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char filename[20];
  char mode[3];
  FILE *fp;
  int choice;
  char ch;

  // Welcome message
  printf("Welcome to the Lively File Handling Program!\n");

  // Get filename and mode from user
  printf("Enter the filename: ");
  scanf("%s", filename);
  printf("Enter the mode (r/w): ");
  scanf("%s", mode);

  // Open file
  fp = fopen(filename, mode);
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  // Display menu
  printf("Menu:\n");
  printf("1. Read from file\n");
  printf("2. Write to file\n");
  printf("3. Quit\n");

  // Get user choice
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Perform action based on choice
  switch (choice) {
    case 1:
      // Read from file
      printf("Reading from file...\n");
      while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
      }
      printf("\n");
      break;
    case 2:
      // Write to file
      printf("Enter some text: ");
      fgets(filename, 20, stdin);
      fprintf(fp, "%s", filename);
      printf("Text written to file.\n");
      break;
    case 3:
      // Quit
      printf("Quitting...\n");
      break;
    default:
      // Invalid choice
      printf("Invalid choice.\n");
      break;
  }

  // Close file
  fclose(fp);

  // Exit program
  return 0;
}