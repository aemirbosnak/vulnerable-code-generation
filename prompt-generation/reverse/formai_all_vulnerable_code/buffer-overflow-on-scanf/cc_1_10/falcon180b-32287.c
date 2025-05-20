//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 500

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    char content[MAX_FILE_CONTENT_LENGTH];
} File;

File files[MAX_FILES];
int num_files;

void init() {
    num_files = 0;
    memset(files, 0, sizeof(files));
}

void create_file(char* name, char* content) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    int size = strlen(content);
    if (size > MAX_FILE_CONTENT_LENGTH) {
        printf("Error: File content too long.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    strcpy(files[num_files].content, content);

    num_files++;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            memset(&files[i], 0, sizeof(File));
            num_files--;
            printf("File deleted successfully.\n");
            return;
        }
    }

    printf("File not found.\n");
}

void list_files() {
    printf("Files:\n");
    int i;
    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

void view_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("File Content:\n%s\n", files[i].content);
            return;
        }
    }

    printf("File not found.\n");
}

int main() {
    init();

    char command[80];
    while (true) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            char content[MAX_FILE_CONTENT_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            printf("Enter file content: ");
            scanf("%s", content);
            create_file(name, content);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "view") == 0) {
            char name[MAX_FILE_NAME_LENGTH];
            printf("Enter file name: ");
            scanf("%s", name);
            view_file(name);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}