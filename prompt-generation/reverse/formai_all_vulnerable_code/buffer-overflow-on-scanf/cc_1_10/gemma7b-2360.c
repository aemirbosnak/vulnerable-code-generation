//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store digital diary entries
typedef struct Entry {
    char name[20];
    char date[20];
    char content[1000];
} Entry;

// Function to create a new entry
Entry *createEntry() {
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    newEntry->name[0] = '\0';
    newEntry->date[0] = '\0';
    newEntry->content[0] = '\0';
    return newEntry;
}

// Function to save an entry
void saveEntry(Entry *entry) {
    FILE *file = fopen("diary.txt", "a");
    fprintf(file, "Name: %s\n", entry->name);
    fprintf(file, "Date: %s\n", entry->date);
    fprintf(file, "Content: %s\n", entry->content);
    fclose(file);
}

int main() {
    // Create a new entry
    Entry *entry = createEntry();

    // Get the entry's name, date, and content
    printf("Enter the entry's name:");
    scanf("%s", entry->name);

    printf("Enter the entry's date:");
    scanf("%s", entry->date);

    printf("Enter the entry's content:");
    scanf("%s", entry->content);

    // Save the entry
    saveEntry(entry);

    // Print a confirmation message
    printf("Entry saved successfully!\n");

    return 0;
}