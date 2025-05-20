//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
    char filename[MAX_FILE_NAME_LENGTH];
    struct FileEntry* next;
} FileEntry;

int main() {
    FILE* file_ptr;
    FileEntry* head = NULL;
    char filename[MAX_FILE_NAME_LENGTH];

    // Loop to get the filename from the user
    while (1) {
        printf("Enter the filename: ");
        scanf("%s", filename);

        // Check if the filename is already in the list
        if (head != NULL) {
            FileEntry* current = head;
            while (current) {
                if (strcmp(filename, current->filename) == 0) {
                    printf("Error: File already exists.\n");
                    return 1;
                }
                current = current->next;
            }
        }

        // Allocate memory for the new file entry
        FileEntry* new_entry = malloc(sizeof(FileEntry));
        new_entry->filename[0] = '\0';
        strcpy(new_entry->filename, filename);
        new_entry->next = NULL;

        // Add the new file entry to the list
        if (head == NULL) {
            head = new_entry;
        } else {
            FileEntry* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_entry;
        }

        // Print a confirmation message
        printf("File added successfully.\n");
    }

    return 0;
}