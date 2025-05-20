//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 10
#define BUFFER_SIZE 1024

typedef struct FileEntry
{
    char filename[256];
    long file_size;
    struct FileEntry* next;
} FileEntry;

FileEntry* insert_file(FileEntry* head, char* filename, long file_size)
{
    FileEntry* new_entry = malloc(sizeof(FileEntry));
    strcpy(new_entry->filename, filename);
    new_entry->file_size = file_size;
    new_entry->next = NULL;

    if (head == NULL)
    {
        head = new_entry;
    }
    else
    {
        head->next = new_entry;
    }

    return head;
}

int main()
{
    FileEntry* head = NULL;
    char buffer[BUFFER_SIZE];
    int i = 0;
    char filename[256];
    long file_size;

    // Simulate backing up 5 files
    for (i = 0; i < MAX_FILES; i++)
    {
        printf("Enter file name: ");
        scanf("%s", filename);

        printf("Enter file size: ");
        scanf("%ld", &file_size);

        insert_file(head, filename, file_size);
    }

    // Print the list of backed up files
    for (head = head->next; head != NULL; head = head->next)
    {
        printf("%s (size: %ld bytes)\n", head->filename, head->file_size);
    }

    return 0;
}