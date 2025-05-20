//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <string.h>

void write_entry(char **entries, int *entries_count);

int main()
{
    char **entries = NULL;
    int entries_count = 0;

    // Loop until the user enters "quit"
    while (1)
    {
        char input[256];

        printf("Enter a message: ");
        fgets(input, 256, stdin);

        // Remove newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // If the user has entered "quit", break out of the loop
        if (strcmp(input, "quit") == 0)
            break;

        // Write the entry to the digital diary
        write_entry(&entries, &entries_count);
    }

    // Print the entries from the digital diary
    for (int i = 0; i < entries_count; i++)
    {
        printf("Entry %d: %s\n", i + 1, entries[i]);
    }

    return 0;
}

void write_entry(char **entries, int *entries_count)
{
    // Allocate memory for the new entry
    entries = realloc(entries, (*entries_count + 1) * sizeof(char *));

    // Create a new entry
    entries[*entries_count] = malloc(256);

    // Write the entry to the new entry
    scanf("%s", entries[*entries_count]);

    // Increment the number of entries
    (*entries_count)++;
}