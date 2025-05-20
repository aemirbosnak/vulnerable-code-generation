//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 100
#define MAX_FILE_NAME_LENGTH 20
#define NUM_FILES 10

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    int size;
} File;

void createFile(File* file, char* name) {
    strcpy(file->name, name);
    file->size = 0;
}

void deleteFile(File* file) {
    strcpy(file->name, "");
    file->size = 0;
}

void writeToFile(File* file, char* content) {
    int length = strlen(content);
    if (file->size + length > MAX_FILE_SIZE) {
        printf("Error: File is full.\n");
        return;
    }
    strcat(file->content, content);
    file->size += length;
}

void readFromFile(File* file) {
    if (file->size == 0) {
        printf("Error: File is empty.\n");
        return;
    }
    printf("%s\n", file->content);
}

int main() {
    File files[NUM_FILES];
    int choice;

    do {
        printf("\n=== File System ===\n");
        printf("1. Create file\n");
        printf("2. Delete file\n");
        printf("3. Write to file\n");
        printf("4. Read from file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf("%s", files[0].name);
            createFile(&files[0], files[0].name);
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%s", files[0].name);
            deleteFile(&files[0]);
            break;
        case 3:
            printf("Enter file name: ");
            scanf("%s", files[0].name);
            printf("Enter content: ");
            scanf("%[^\n]s", files[0].content);
            writeToFile(&files[0], files[0].content);
            break;
        case 4:
            printf("Enter file name: ");
            scanf("%s", files[0].name);
            readFromFile(&files[0]);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}