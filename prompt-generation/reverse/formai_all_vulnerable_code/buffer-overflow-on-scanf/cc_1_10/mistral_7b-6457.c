//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Directory structure definition
typedef struct DirEntry {
    char name[20];
    char type;
    char contents[100];
    int size;
    struct DirEntry *next;
} DirEntry;

// Initialize empty directory
DirEntry *root = NULL;

// Function to create a new file in the directory
void createFile(char *fileName, char *fileContents) {
    DirEntry *newEntry = (DirEntry *)malloc(sizeof(DirEntry));
    strcpy(newEntry->name, fileName);
    newEntry->type = 'F';
    strcpy(newEntry->contents, fileContents);
    newEntry->size = strlen(fileContents) + 1;
    newEntry->next = root;
    root = newEntry;
}

// Function to delete a file from the directory
void deleteFile(char *fileName) {
    DirEntry *current = root;
    DirEntry *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, fileName) == 0) {
            if (previous == NULL) {
                root = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("File not found.\n");
}

// Function to list files in the directory
void listFiles() {
    DirEntry *current = root;

    printf("\nFiles in the directory:\n");

    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

// Command-line interface for user interaction
int main() {
    char command[50], fileName[50], fileContents[100];

    while (1) {
        printf("\n> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", fileName);
            printf("Enter file contents: ");
            scanf("%s", fileContents);
            createFile(fileName, fileContents);
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter file name to delete: ");
            scanf("%s", fileName);
            deleteFile(fileName);
        } else if (strcmp(command, "list") == 0) {
            listFiles();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}