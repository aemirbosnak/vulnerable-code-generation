//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <string.h>

// Define a structure to store diary entries
typedef struct Entry
{
    char date[20];
    char title[50];
    char entry[200];
} Entry;

// Define a function to add a new entry to the diary
void addEntry(Entry *entries, int *entriesCount)
{
    // Allocate memory for the new entry
    entries = (Entry *)realloc(entries, (*entriesCount + 1) * sizeof(Entry));

    // Get the date, title, and entry from the user
    printf("Enter the date of the entry:");
    scanf("%s", entries[*entriesCount].date);

    printf("Enter the title of the entry:");
    scanf("%s", entries[*entriesCount].title);

    printf("Enter the entry:");
    scanf("%s", entries[*entriesCount].entry);

    // Increment the number of entries
    (*entriesCount)++;
}

// Define a function to print an entry from the diary
void printEntry(Entry *entries, int entriesCount)
{
    // Loop through the entries and find the one to print
    for (int i = 0; i < entriesCount; i++)
    {
        if (strcmp(entries[i].date, "Today") == 0)
        {
            // Print the date, title, and entry
            printf("Date: %s\n", entries[i].date);
            printf("Title: %s\n", entries[i].title);
            printf("Entry: %s\n", entries[i].entry);
            break;
        }
    }
}

int main()
{
    // Create an array of entries
    Entry *entries = NULL;

    // Initialize the number of entries
    int entriesCount = 0;

    // Add some entries to the diary
    addEntry(entries, &entriesCount);
    addEntry(entries, &entriesCount);

    // Print an entry from the diary
    printEntry(entries, entriesCount);

    return 0;
}