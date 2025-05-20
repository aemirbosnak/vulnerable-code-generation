//FormAI DATASET v1.0 Category: File system simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_FILE_COUNT 100

typedef struct {
    char name[MAX_FILENAME_SIZE];
    int size;
} File;

File files[MAX_FILE_COUNT];
int fileCount = 0;

int main() {
    int choice;
    do {
        printf("Select an option:\n1. Create a new file.\n2. Display files.\n3. Delete a file.\n4. Exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[MAX_FILENAME_SIZE];
                int size;
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);
                if (fileCount >= MAX_FILE_COUNT) {
                    printf("Maximum file count reached. Cannot create a new file.\n");
                } else {
                    File newFile = { .size = size };
                    strcpy(newFile.name, name);
                    files[fileCount++] = newFile;
                    printf("File created successfully.\n");
                }
                break;
            }
            case 2: {
                if (fileCount == 0) {
                    printf("No files created yet.\n");
                } else {
                    printf("List of files:\n");
                    for (int i = 0; i < fileCount; i++) {
                        printf("%d. %s (%dKB)\n", i+1, files[i].name, files[i].size);
                    }
                }
                break;
            }
            case 3: {
                if (fileCount == 0) {
                    printf("No files to delete.\n");
                } else {
                    char name[MAX_FILENAME_SIZE];
                    printf("Enter name of file to delete: ");
                    scanf("%s", name);
                    int indexToDelete = -1;
                    for (int i = 0; i < fileCount; i++) {
                        if (strcmp(files[i].name, name) == 0) {
                            indexToDelete = i;
                            break;
                        }
                    }
                    if (indexToDelete == -1) {
                        printf("File not found.\n");
                    } else {
                        for (int i = indexToDelete; i < fileCount-1; i++) {
                            files[i] = files[i+1];
                        }
                        fileCount--;
                        printf("File deleted successfully.\n");
                    }
                }
                break;
            }
            case 4: {
                printf("Exiting simulation.\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while (choice != 4);
    return 0;
}