//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].content, content);
    files[num_files].size = strlen(content);
    num_files++;

    printf("File created successfully\n");
}

void read_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("%s:\n%s", files[i].name, files[i].content);
            return;
        }
    }

    printf("File not found\n");
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(files[i].name, 0, MAX_FILE_NAME_LENGTH);
            memset(files[i].content, 0, MAX_FILE_CONTENT_LENGTH);
            num_files--;

            printf("File deleted successfully\n");
            return;
        }
    }

    printf("File not found\n");
}

int main() {
    char command[100];
    while (1) {
        printf("Enter command (create/read/delete): ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            char content[MAX_FILE_CONTENT_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file content: ");
            scanf("%s", content);
            create_file(name, content);
        } else if (strcmp(command, "read") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            read_file(name);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}