//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char content[MAX_FILE_SIZE];
    int size;
} File;

void create_file(File *file, char *name) {
    strcpy(file->name, name);
    file->size = 0;
    file->content[0] = '\0';
}

int open_file(File *file, char *name) {
    int i;

    for (i = 0; i < MAX_FILE_NAME_LEN; i++) {
        if (name[i] == '\0') {
            strcpy(file->name, name);
            break;
        }
    }

    if (i == MAX_FILE_NAME_LEN) {
        printf("Error: File name too long.\n");
        return 0;
    }

    return 1;
}

int write_file(File *file, char *content) {
    int i, j;

    for (i = 0, j = 0; i < MAX_FILE_SIZE - 1 && content[i]!= '\0'; i++, j++) {
        file->content[j] = content[i];
    }

    file->content[j] = '\0';
    file->size += strlen(content);

    return 1;
}

int read_file(File *file, char *content) {
    if (file->size == 0) {
        printf("Error: File is empty.\n");
        return 0;
    }

    strcpy(content, file->content);

    return 1;
}

int delete_file(File *file) {
    strcpy(file->name, "");
    file->size = 0;
    file->content[0] = '\0';

    return 1;
}

int main() {
    File file;
    char command[20];
    char content[MAX_FILE_SIZE];

    create_file(&file, "");

    while (1) {
        printf("Enter command (create/open/write/read/delete/exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            printf("Enter file name: ");
            scanf("%s", content);
            create_file(&file, content);
        } else if (strcmp(command, "open") == 0) {
            printf("Enter file name: ");
            scanf("%s", content);
            if (open_file(&file, content)) {
                printf("File opened successfully.\n");
            }
        } else if (strcmp(command, "write") == 0) {
            printf("Enter content: ");
            scanf("%s", content);
            if (write_file(&file, content)) {
                printf("Content written successfully.\n");
            }
        } else if (strcmp(command, "read") == 0) {
            char read_content[MAX_FILE_SIZE];
            if (read_file(&file, read_content)) {
                printf("Content: %s\n", read_content);
            }
        } else if (strcmp(command, "delete") == 0) {
            if (delete_file(&file)) {
                printf("File deleted successfully.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}