//Gemma-7B DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FileNode
{
    char *data;
    struct FileNode *next;
} FileNode;

int main()
{
    FileNode *head = NULL;
    char filename[256];
    char *fileData;
    int fileSize;

    // Open file
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    // Get file size
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);

    // Allocate memory for file data
    fileData = malloc(fileSize);

    // Read file data
    rewind(fp);
    fread(fileData, fileSize, 1, fp);

    // Create a linked list of file nodes
    FileNode *newNode = malloc(sizeof(FileNode));
    newNode->data = fileData;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    // Print file data
    printf("File data: \n");
    for (FileNode *currNode = head; currNode; currNode = currNode->next)
    {
        printf("%s", currNode->data);
    }

    // Close file
    fclose(fp);

    return 0;
}