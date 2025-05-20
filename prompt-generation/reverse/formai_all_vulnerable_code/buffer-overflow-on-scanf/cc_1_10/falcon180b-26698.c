//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

typedef struct {
    char name[64];
    int size;
    int type;
} File;

File fileSystem[MAX_FILES];
int numFiles;

void createFile(char* name, int size, int type) {
    if (numFiles >= MAX_FILES) {
        printf("Error: File system is full.\n");
        return;
    }

    strcpy(fileSystem[numFiles].name, name);
    fileSystem[numFiles].size = size;
    fileSystem[numFiles].type = type;

    numFiles++;
}

void deleteFile(char* name) {
    int i;

    for (i = 0; i < numFiles; i++) {
        if (strcmp(fileSystem[i].name, name) == 0) {
            memset(&fileSystem[i], 0, sizeof(File));
            numFiles--;
            break;
        }
    }
}

void listFiles() {
    int i;

    for (i = 0; i < numFiles; i++) {
        printf("%s (%d bytes) - Type: %d\n", fileSystem[i].name, fileSystem[i].size, fileSystem[i].type);
    }
}

int main() {
    int choice;

    numFiles = 0;

    while (1) {
        printf("\nFile System\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            char name[64];
            scanf("%s", name);
            printf("Enter file size: ");
            int size;
            scanf("%d", &size);
            printf("Enter file type (0 - text, 1 - binary): ");
            int type;
            scanf("%d", &type);
            createFile(name, size, type);
            break;

        case 2:
            printf("Enter file name to delete: ");
            char name2[64];
            scanf("%s", name2);
            deleteFile(name2);
            break;

        case 3:
            listFiles();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}