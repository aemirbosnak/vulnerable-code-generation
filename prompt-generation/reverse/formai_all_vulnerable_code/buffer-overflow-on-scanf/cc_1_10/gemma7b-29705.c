//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <string.h>

void writeEntry(char **entries, int *entriesCount)
{
    // Allocate memory for a new entry
    entries = realloc(entries, (*entriesCount + 1) * sizeof(char *));

    // Create a new entry
    entries[*entriesCount] = malloc(200);

    // Get the entry text from the user
    printf("Enter your entry: ");
    fgets(entries[*entriesCount], 200, stdin);

    // Increment the number of entries
    (*entriesCount)++;
}

int main()
{
    // Define the entries array and the number of entries
    char **entries = NULL;
    int entriesCount = 0;

    // Loop until the user chooses to quit
    while (1)
    {
        // Display the entries
        printf("Your entries:\n");
        for (int i = 0; i < entriesCount; i++)
        {
            printf("%d. %s\n", i + 1, entries[i]);
        }

        // Write a new entry
        writeEntry(&entries, &entriesCount);

        // Ask the user if they want to quit
        printf("Do you want to quit? (y/n): ");
        char quit;
        scanf("%c", &quit);

        // Check if the user wants to quit
        if (quit == 'y')
        {
            break;
        }
    }

    // Free the memory allocated for the entries
    for (int i = 0; i < entriesCount; i++)
    {
        free(entries[i]);
    }

    // Free the memory allocated for the entries array
    free(entries);

    return 0;
}