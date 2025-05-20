//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_FILE_CONTENT_SIZE 1000

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    char content[MAX_FILE_CONTENT_SIZE];
    int size;
} File;

void create_file(File *file) {
    printf("Enter file name: ");
    scanf("%s", file->name);
    printf("Enter file content: ");
    fgets(file->content, MAX_FILE_CONTENT_SIZE, stdin);
    file->size = strlen(file->content);
    printf("File created successfully.\n");
}

void read_file(File *file) {
    printf("File content:\n%s", file->content);
}

void delete_file(File *file) {
    printf("File deleted successfully.\n");
}

void rename_file(File *file) {
    printf("Enter new file name: ");
    scanf("%s", file->name);
    printf("File renamed successfully.\n");
}

int main() {
    File file;
    int choice;

    do {
        printf("\nFile System Simulation\n");
        printf("1. Create file\n2. Read file\n3. Delete file\n4. Rename file\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_file(&file);
                break;
            case 2:
                read_file(&file);
                break;
            case 3:
                delete_file(&file);
                break;
            case 4:
                rename_file(&file);
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