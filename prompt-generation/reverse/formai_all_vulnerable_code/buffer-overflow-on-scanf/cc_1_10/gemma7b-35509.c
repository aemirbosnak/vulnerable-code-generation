//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <string.h>

void write_entry(char **entries, int *entries_size)
{
  // Allocate memory for a new entry
  entries = realloc(entries, (*entries_size + 1) * sizeof(char *));

  // Create a new entry
  entries[*entries_size] = malloc(200);

  // Get the user input
  printf("What do you want to write about? ");
  gets(entries[*entries_size]);

  // Increment the number of entries
  (*entries_size)++;
}

int main()
{
  char **entries = NULL;
  int entries_size = 0;

  // Loop until the user enters "quit"
  while (1)
  {
    // Get the user input
    char input[200];
    printf("Enter command (add, quit): ");
    scanf("%s", input);

    // Check if the user wants to add an entry
    if (strcmp(input, "add") == 0)
    {
      write_entry(&entries, &entries_size);
    }

    // Check if the user wants to quit
    else if (strcmp(input, "quit") == 0)
    {
      break;
    }

    // Invalid command
    else
    {
      printf("Invalid command.\n");
    }
  }

  // Print the entries
  for (int i = 0; i < entries_size; i++)
  {
    printf("Entry %d: %s\n", i + 1, entries[i]);
  }

  // Free the memory
  for (int i = 0; i < entries_size; i++)
  {
    free(entries[i]);
  }
  free(entries);

  return 0;
}