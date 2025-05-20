//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_FILES 10

typedef struct {
    char name[50];
    int size;
    char content[MAX_SIZE];
} File;

void createFile(File* file, char* name, int size) {
    strcpy(file->name, name);
    file->size = size;
    memset(file->content, 0, MAX_SIZE);
}

void openFile(File* file, char* name) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(file[i].name, name) == 0) {
            printf("File already exists.\n");
            return;
        }
    }
    createFile(&file[MAX_FILES], name, 0);
}

void writeFile(File* file, char* content) {
    int i = 0;
    while (i < strlen(content) && i < MAX_SIZE) {
        strcat(file->content, content);
        i++;
    }
}

void readFile(File* file) {
    printf("Content of file: %s\n", file->content);
}

void closeFile(File* file) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(file[i].name, file->name) == 0) {
            file[i].size = strlen(file->content);
        }
    }
}

int main() {
    File file[MAX_FILES];
    int choice;
    do {
        printf("1. Create file\n2. Open file\n3. Write file\n4. Read file\n5. Close file\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", file[MAX_FILES].name);
                printf("Enter file size: ");
                scanf("%d", &file[MAX_FILES].size);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", file[MAX_FILES].name);
                break;
            case 3:
                printf("Enter file content: ");
                scanf("%s", file[MAX_FILES].content);
                break;
            case 4:
                printf("Content of file: %s\n", file[MAX_FILES].content);
                break;
            case 5:
                printf("File closed.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 6);
    return 0;
}