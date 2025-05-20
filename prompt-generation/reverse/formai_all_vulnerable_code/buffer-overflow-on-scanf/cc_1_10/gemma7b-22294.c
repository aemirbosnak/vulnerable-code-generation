//Gemma-7B DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileEntry
{
    char *filename;
    int size;
    struct FileEntry *next;
} FileEntry;

FileEntry *insertFile(FileEntry *head, char *filename, int size)
{
    FileEntry *newEntry = malloc(sizeof(FileEntry));
    newEntry->filename = strdup(filename);
    newEntry->size = size;
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = insertFile(head->next, filename, size);
    }

    return head;
}

int main()
{
    FileEntry *head = NULL;
    char filename[256];
    int size;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter file size: ");
    scanf("%d", &size);

    insertFile(head, filename, size);

    printf("File inserted successfully.\n");

    return 0;
}