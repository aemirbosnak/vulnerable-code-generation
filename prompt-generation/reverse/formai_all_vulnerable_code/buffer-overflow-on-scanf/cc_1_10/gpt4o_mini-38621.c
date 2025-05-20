//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 100
#define MAX_FILESIZE 1024

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    char content[MAX_FILESIZE];
    int size;
} File;

File fileSystem[MAX_FILES];
int fileCount = 0;

// Function declarations
void createFile();
void readFile();
void writeFile();
void listFiles();
void deleteFile();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Simple File System Simulation ---\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. List Files\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                listFiles();
                break;
            case 5:
                deleteFile();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}

void createFile() {
    if (fileCount >= MAX_FILES) {
        printf("File system is full. Cannot create more files.\n");
        return;
    }

    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", fileName);

    // Check for duplicate file names
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, fileName) == 0) {
            printf("File with this name already exists.\n");
            return;
        }
    }

    strcpy(fileSystem[fileCount].name, fileName);
    fileSystem[fileCount].size = 0;
    fileCount++;
    printf("File '%s' created successfully.\n", fileName);
}

void writeFile() {
    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter file name to write to: ");
    scanf("%s", fileName);

    int index = -1;
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, fileName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("File '%s' does not exist.\n", fileName);
        return;
    }

    printf("Enter content to write (max %d characters): ", MAX_FILESIZE);
    clearInputBuffer();
    fgets(fileSystem[index].content, MAX_FILESIZE, stdin);
    fileSystem[index].size = strlen(fileSystem[index].content);
    printf("Content written to file '%s' successfully.\n", fileName);
}

void readFile() {
    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter file name to read from: ");
    scanf("%s", fileName);

    int index = -1;
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, fileName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("File '%s' does not exist.\n", fileName);
        return;
    }

    printf("Content of file '%s':\n%s\n", fileName, fileSystem[index].content);
}

void listFiles() {
    if (fileCount == 0) {
        printf("No files in the system.\n");
        return;
    }

    printf("List of files:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%d. %s\n", i + 1, fileSystem[i].name);
    }
}

void deleteFile() {
    char fileName[MAX_FILENAME_LENGTH];
    printf("Enter file name to delete: ");
    scanf("%s", fileName);

    int index = -1;
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, fileName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("File '%s' does not exist.\n", fileName);
        return;
    }

    for (int i = index; i < fileCount - 1; i++) {
        fileSystem[i] = fileSystem[i + 1];
    }
    fileCount--;
    printf("File '%s' deleted successfully.\n", fileName);
}

// Function to clean input stream
void clearInputBuffer() {
    while (getchar() != '\n');
}