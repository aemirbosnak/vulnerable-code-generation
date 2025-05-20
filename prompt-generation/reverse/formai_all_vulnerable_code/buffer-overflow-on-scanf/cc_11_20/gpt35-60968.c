//FormAI DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_CONTENT_LENGTH 100

// Define file structure
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
} file;

int main() {
    int numFiles = 0;
    file files[MAX_FILES];

    while (1) {
        printf("Enter command (add, delete, view, exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (numFiles >= MAX_FILES) {
                printf("Error: Maximum number of files reached.\n");
                continue;
            }

            printf("Enter filename: ");
            char filename[MAX_FILENAME_LENGTH];
            scanf("%s", filename);

            // Check if filename already exists
            int exists = 0;
            for (int i = 0; i < numFiles; i++) {
                if (strcmp(files[i].filename, filename) == 0) {
                    exists = 1;
                    break;
                }
            }

            if (exists) {
                printf("Error: File already exists.\n");
            } else {
                printf("Enter file content: ");
                char content[MAX_FILE_CONTENT_LENGTH];
                scanf("%s", content);

                // Add file to list
                file newFile;
                strcpy(newFile.filename, filename);
                strcpy(newFile.content, content);
                files[numFiles] = newFile;
                numFiles++;

                printf("File added successfully.\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter filename: ");
            char filename[MAX_FILENAME_LENGTH];
            scanf("%s", filename);

            // Check if filename exists and delete if it does
            int deleted = 0;
            for (int i = 0; i < numFiles; i++) {
                if (strcmp(files[i].filename, filename) == 0) {
                    for (int j = i; j < numFiles - 1; j++) {
                        files[j] = files[j+1];
                    }
                    numFiles--;
                    deleted = 1;
                    break;
                }
            }

            if (deleted) {
                printf("File deleted successfully.\n");
            } else {
                printf("Error: File not found.\n");
            }
        } else if (strcmp(command, "view") == 0) {
            printf("Files:\n");
            for (int i = 0; i < numFiles; i++) {
                printf("%s: %s\n", files[i].filename, files[i].content);
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}