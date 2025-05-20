//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 50
#define MAX_FILE_NAME 20
#define MAX_FILE_CONTENT 100

typedef struct File {
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_CONTENT];
    bool is_deleted;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(const char *name) {
    if (num_files >= MAX_FILES) {
        printf("Error: Max number of files reached\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].is_deleted = false;
    num_files++;
}

void delete_file(const char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            files[i].is_deleted = true;
            num_files--;
            break;
        }
    }

    if (i == num_files) {
        printf("Error: File not found\n");
    }
}

void list_files() {
    int i;

    printf("Files in directory:\n");
    for (i = 0; i < num_files; i++) {
        if (!files[i].is_deleted) {
            printf("%s\n", files[i].name);
        }
    }
}

void write_file(const char *name, const char *content) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strcpy(files[i].content, content);
            break;
        }
    }

    if (i == num_files) {
        printf("Error: File not found\n");
    }
}

void read_file(const char *name, char *output, int size) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            strncpy(output, files[i].content, size);
            break;
        }
    }

    if (i == num_files) {
        printf("Error: File not found\n");
    }
}

int main() {
    char command[50];
    char name[MAX_FILE_NAME];
    char content[MAX_FILE_CONTENT];
    char output[MAX_FILE_CONTENT];
    int size;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "create") == 0) {
            scanf("%s", name);
            create_file(name);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "write") == 0) {
            scanf("%s", name);
            scanf("%s", content);
            write_file(name, content);
        } else if (strcmp(command, "read") == 0) {
            scanf("%s", name);
            scanf("%d", &size);
            read_file(name, output, size);
            printf("%s\n", output);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Error: Unknown command\n");
        }
    }

    return 0;
}