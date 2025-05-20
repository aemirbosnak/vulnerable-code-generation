//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_CONTENT_LENGTH 256

typedef struct File {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    struct File* next;
} File;

File* head = NULL;

void createFile(const char* name, const char* content) {
    File* newFile = (File*)malloc(sizeof(File));
    if (!newFile) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    strncpy(newFile->name, name, MAX_FILENAME_LENGTH);
    strncpy(newFile->content, content, MAX_CONTENT_LENGTH);
    newFile->next = head;
    head = newFile;
    printf("File '%s' created successfully.\n", name);
}

void deleteFile(const char* name) {
    File* current = head;
    File* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) { // File is at the head
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Error: File '%s' not found.\n", name);
}

void listFiles() {
    File* current = head;
    if (current == NULL) {
        printf("No files in the current directory.\n");
        return;
    }
    printf("Files in the current directory:\n");
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}

void viewFile(const char* name) {
    File* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Contents of '%s':\n%s\n", name, current->content);
            return;
        }
        current = current->next;
    }
    printf("Error: File '%s' not found.\n", name);
}

void freeMemory() {
    File* current = head;
    while (current != NULL) {
        File* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int choice;
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];

    while (1) {
        printf("\nSimple File System Simulation:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. List Files\n");
        printf("4. View File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                fgets(name, MAX_FILENAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter file content: ");
                fgets(content, MAX_CONTENT_LENGTH, stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline character
                createFile(name, content);
                break;

            case 2:
                printf("Enter file name to delete: ");
                fgets(name, MAX_FILENAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                deleteFile(name);
                break;

            case 3:
                listFiles();
                break;

            case 4:
                printf("Enter file name to view: ");
                fgets(name, MAX_FILENAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                viewFile(name);
                break;

            case 5:
                freeMemory();
                printf("Exiting the file system simulation.\n");
                exit(0);
                break;

            default:
                printf("Error: Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}