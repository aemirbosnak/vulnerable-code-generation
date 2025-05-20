//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a labyrinth of nested structs
    struct FileNode
    {
        char filename[256];
        struct FileNode* next;
    };

    struct FileNode* head = NULL;
    struct FileNode* tail = NULL;

    // Simulate a file system by traversing a linked list
    while (1)
    {
        // Get the file name from the user
        char filename[256];
        printf("Enter file name: ");
        scanf("%s", filename);

        // Check if the file already exists in the list
        struct FileNode* node = head;
        while (node)
        {
            if (strcmp(filename, node->filename) == 0)
            {
                printf("File already exists.\n");
                break;
            }
            node = node->next;
        }

        // If the file does not exist, create a new node
        struct FileNode* newNode = malloc(sizeof(struct FileNode));
        newNode->filename[0] = '\0';
        strcpy(newNode->filename, filename);
        newNode->next = NULL;

        // If the list is empty, make the new node the head
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        // Otherwise, add the new node to the tail
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        // Print a confirmation message
        printf("File added successfully.\n");
    }

    return 0;
}