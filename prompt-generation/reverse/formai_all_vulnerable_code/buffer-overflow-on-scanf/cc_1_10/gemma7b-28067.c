//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 255

typedef struct FileEntry {
    char filename[MAX_FILENAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

int main() {
    // Create a linked list of file entries
    FileEntry* head = NULL;

    // Loop until the user enters a filename or quits
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter a filename (or quit to exit): ");
    scanf("%s", filename);

    // While the user has not quit, add the file entry to the list
    while (strcmp(filename, "quit") != 0) {
        // Allocate memory for the new file entry
        FileEntry* newEntry = (FileEntry*)malloc(sizeof(FileEntry));

        // Copy the filename into the new file entry
        strcpy(newEntry->filename, filename);

        // Add the new file entry to the list
        if (head == NULL) {
            head = newEntry;
        } else {
            newEntry->next = head;
            head = newEntry;
        }

        // Get the next filename from the user
        printf("Enter a filename (or quit to exit): ");
        scanf("%s", filename);
    }

    // Print the list of file entries
    printf("Here is a list of your file entries:\n");
    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        printf("%s\n", currentEntry->filename);
    }

    // Free the memory allocated for the file entries
    for (FileEntry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
        free(currentEntry);
    }

    return 0;
}