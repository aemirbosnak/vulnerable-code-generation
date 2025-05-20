#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **entries = NULL;
  int numEntries = 0;

  // Open file if it exists, otherwise create new file
  FILE *file = fopen("diary.txt", "r");
  if (file == NULL) {
    file = fopen("diary.txt", "w");
  }

  // Loop until user chooses to quit
  while (1) {
    // Display options
    printf("Enter 'add', 'read', 'save', or 'quit': ");

    // Get user input
    char input[20];
    scanf("%s", input);

    // Handle user input
    switch (input[0]) {
      case 'a':
        // Get entry text
        char entry[200];
        printf("Enter your entry: ");
        scanf("%s", entry);

        // Allocate memory for new entry
        entries = realloc(entries, (numEntries + 1) * sizeof(char *));

        // Add entry to file
        entries[numEntries++] = strdup(entry);
        fprintf(file, "%s\n", entries[numEntries - 1]);
        break;

      case 'r':
        // Display entries
        for (int i = 0; i < numEntries; i++) {
          printf("%d. %s\n", i + 1, entries[i]);
        }
        break;

      case 's':
        // Save entries to file
        fclose(file);
        file = fopen("diary.txt", "w");
        for (int i = 0; i < numEntries; i++) {
          fprintf(file, "%s\n", entries[i]);
        }
        fclose(file);
        break;

      case 'q':
        // Quit
        printf("Thank you for using the diary. Goodbye!\n");
        exit(0);
        break;

      default:
        // Invalid input
        printf("Invalid input. Please try again.\n");
    }
  }

  return 0;
}
