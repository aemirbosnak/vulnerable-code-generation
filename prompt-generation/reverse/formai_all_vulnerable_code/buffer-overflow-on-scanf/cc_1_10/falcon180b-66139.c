//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 20
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

int num_files = 0;
File files[MAX_FILES];

void create_file(char* name, char* content, int size) {
    if (num_files == MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = size;

    num_files++;
}

void delete_file(char* name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LENGTH);
            memset(files[i].content, 0, MAX_FILE_CONTENT_LENGTH);
            num_files--;
            return;
        }
    }

    printf("Error: File not found.\n");
}

void display_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("File %d:\nName: %s\nContent: %s\nSize: %d\n\n", i+1, files[i].name, files[i].content, files[i].size);
    }
}

int main() {
    char command[50];

    while (1) {
        printf("Enter command (create/delete/display/exit): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            char content[MAX_FILE_CONTENT_LENGTH];
            int size;

            printf("Enter file name: ");
            scanf("%s", name);

            printf("Enter file content: ");
            scanf("%s", content);

            printf("Enter file size: ");
            scanf("%d", &size);

            create_file(name, content, size);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILE_NAME_LENGTH];

            printf("Enter file name: ");
            scanf("%s", name);

            delete_file(name);
        } else if (strcmp(command, "display") == 0) {
            display_files();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}