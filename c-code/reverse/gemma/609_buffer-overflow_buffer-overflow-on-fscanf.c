#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_SIZE 256

int main() {
  FILE *diary_file = NULL;
  char entry[MAX_ENTRY_SIZE];
  int entry_size = 0;

  // Open the diary file if it exists, otherwise create a new one
  diary_file = fopen("diary.txt", "r");
  if (diary_file == NULL) {
    diary_file = fopen("diary.txt", "w");
  }

  // Read the entry size from the file or initialize it to 0
  if (fscanf(diary_file, "%d", &entry_size) != 1) {
    entry_size = 0;
  }

  // Get the user input for the new entry
  printf("Enter your diary entry: ");
  fgets(entry, MAX_ENTRY_SIZE, stdin);

  // Add the new entry to the file
  fprintf(diary_file, "%d\n", entry_size + 1);
  fprintf(diary_file, "%s", entry);

  // Save the file
  fclose(diary_file);

  // Print the saved entry
  printf("Your diary entry has been saved: \n");
  printf("%s", entry);

  return 0;
}
