//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 64
#define MAX_FILE_CONTENT_LENGTH 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

void create_file(File *file) {
    printf("Enter file name: ");
    scanf("%s", file->name);
    printf("Enter file content: ");
    scanf("%s", file->content);
    file->size = strlen(file->content);
}

void read_file(File *file) {
    printf("File name: %s\n", file->name);
    printf("File content: %s\n", file->content);
    printf("File size: %d\n", file->size);
}

void delete_file(File *file) {
    printf("Deleting file %s...\n", file->name);
}

int main() {
    File file;
    char command[32];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            create_file(&file);
        } else if (strcmp(command, "read") == 0) {
            read_file(&file);
        } else if (strcmp(command, "delete") == 0) {
            delete_file(&file);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}