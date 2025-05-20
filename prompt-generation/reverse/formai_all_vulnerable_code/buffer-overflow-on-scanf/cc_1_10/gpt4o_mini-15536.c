//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 50
#define FILE_CONTENT_LENGTH 256

typedef struct {
    char name[FILE_NAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];
    int isUsed;
} File;

File fileSystem[MAX_FILES];

// Function prototypes
void createFile(char *name);
void readFile(char *name);
void writeFile(char *name, char *content);
void deleteFile(char *name);
void displayFiles();

int main() {
    char choice;
    char name[FILE_NAME_LENGTH];
    char content[FILE_CONTENT_LENGTH];

    printf("Welcome to the Grateful File System Simulation!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Write File\n");
        printf("4. Delete File\n");
        printf("5. Display All Files\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the name of the file to create: ");
                scanf("%s", name);
                createFile(name);
                break;
            case '2':
                printf("Enter the name of the file to read: ");
                scanf("%s", name);
                readFile(name);
                break;
            case '3':
                printf("Enter the name of the file to write to: ");
                scanf("%s", name);
                printf("Enter the content to write: ");
                fgetc(stdin); // clear buffer
                fgets(content, FILE_CONTENT_LENGTH, stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline character
                writeFile(name, content);
                break;
            case '4':
                printf("Enter the name of the file to delete: ");
                scanf("%s", name);
                deleteFile(name);
                break;
            case '5':
                displayFiles();
                break;
            case '6':
                printf("Thank you for using the file system simulation! Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void createFile(char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!fileSystem[i].isUsed) {
            strcpy(fileSystem[i].name, name);
            fileSystem[i].content[0] = '\0';
            fileSystem[i].isUsed = 1;
            printf("File '%s' created successfully!\n", name);
            return;
        }
    }
    printf("File system is full, cannot create more files!\n");
}

void readFile(char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fileSystem[i].isUsed && strcmp(fileSystem[i].name, name) == 0) {
            printf("Contents of file '%s': %s\n", name, fileSystem[i].content);
            return;
        }
    }
    printf("File '%s' not found!\n", name);
}

void writeFile(char *name, char *content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fileSystem[i].isUsed && strcmp(fileSystem[i].name, name) == 0) {
            strcpy(fileSystem[i].content, content);
            printf("Content written to file '%s' successfully!\n", name);
            return;
        }
    }
    printf("File '%s' not found! Cannot write content.\n", name);
}

void deleteFile(char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fileSystem[i].isUsed && strcmp(fileSystem[i].name, name) == 0) {
            fileSystem[i].isUsed = 0;
            printf("File '%s' deleted successfully!\n", name);
            return;
        }
    }
    printf("File '%s' not found! Cannot delete.\n", name);
}

void displayFiles() {
    printf("Current files in the file system:\n");
    int found = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        if (fileSystem[i].isUsed) {
            printf(" - %s\n", fileSystem[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No files found in the file system.\n");
    }
}